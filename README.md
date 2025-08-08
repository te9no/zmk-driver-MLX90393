# MLX90393 ZMK Input Driver

Arduino互換のMLX90393三軸磁気センサー用ZMK入力ドライバーです。トラックポイント形式のカーソル制御を提供します。

## 概要

このドライバーは実証済みのArduinoサンプルコードをベースに開発され、MLX90393センサーとの確実なI2C通信を実現します。

### 主要機能

- ✅ **Arduino互換実装** - 動作が実証済みのArduinoコードと同じ通信パターン
- ✅ **自動キャリブレーション** - 起動時に自動で中心位置を設定（50サンプル/5秒）
- ✅ **滑らかな動作** - デッドゾーンと感度調整による安定した操作感  
- ✅ **詳細デバッグログ** - リアルタイムセンサー値監視
- ✅ **I2Cアドレス検出** - 標準的なMLX90393設定（0x0C）をサポート
- ✅ **相対座標システム** - ベースラインからの相対変化でスムーズな制御

## ハードウェア要件

- MLX90393 三軸磁気センサー
- プルアップ抵抗有効のI2C接続
- 標準I2Cアドレス: `0x0C`

## 設定方法

デバイスツリーオーバーレイに追加:

```dts
&i2c0 {
    status = "okay";
    pinctrl-0 = <&i2c0_default>;
    pinctrl-1 = <&i2c0_sleep>;
    pinctrl-names = "default", "sleep";
    clock-frequency = <100000>;
    
    mlx90393_input: mlx90393-input@0c {
        compatible = "melexis,mlx90393-input";
        reg = <0x0c>;
        polling-interval-ms = <10>;
    };
};

// I2Cピン設定でプルアップ抵抗を有効化（重要）
&pinctrl {
    i2c0_default: i2c0_default {
        group1 {
            psels = <NRF_PSEL(TWIM_SDA, 0, 4)>,
                    <NRF_PSEL(TWIM_SCL, 0, 5)>;
            bias-pull-up; // 必須: プルアップ抵抗を有効化
        };
    };
    
    i2c0_sleep: i2c0_sleep {
        group1 {
            psels = <NRF_PSEL(TWIM_SDA, 0, 4)>,
                    <NRF_PSEL(TWIM_SCL, 0, 5)>;
            low-power-enable;
            bias-pull-up; // スリープ時もプルアップ維持
        };
    };
};
```

## 設定パラメーター

| パラメーター | デフォルト値 | 説明 |
|------------|------------|------|
| `polling-interval-ms` | 10 | センサー読み取り間隔（ミリ秒） |
| `reg` | 0x0c | I2Cアドレス（通常変更不要） |

## ドライバー動作

1. **初期化**: Arduinoで実証済みのレジスタ設定シーケンス実行
2. **キャリブレーション**: 50サンプル収集でベースライン確立（約5秒）
3. **動作**: ベースラインからの相対変化をフィルタリングして報告
4. **感度**: 滑らかな制御のため動きを1/4にスケーリング

## デバッグ出力

ログ出力でリアルタイムセンサーデータを確認:

```
[INF] input_mlx90393: Initializing MLX90393 at address 0x0C
[INF] input_mlx90393: First config status: 0x3c
[INF] input_mlx90393: Second config status: 0x3c
[INF] input_mlx90393: Calibration 10/50 - Current: X:1234 Y:5678 Z:9012
[INF] input_mlx90393: *** Calibration COMPLETE! Baseline: X=1234 Y=5678 Z=9012 ***
[INF] input_mlx90393: Sensor values - Raw: X:1240 Y:5680 Z:9015, Baseline: X:1234 Y:5678 Z:9012, Relative: X:1 Y:0 Z:0
[INF] input_mlx90393: >>> INPUT GENERATED: X:1 Y:0 Z:0
```

## 実装詳細

### Arduino互換I2C通信パターン

```c
// Arduino: Wire.beginTransmission() → Wire.write() → Wire.endTransmission()
static int mlx90393_write(const struct device *dev, uint8_t *data, size_t len) {
    return i2c_write_dt(&config->i2c, data, len);
}

// Arduino: Wire.requestFrom() → Wire.read()
static int mlx90393_read(const struct device *dev, uint8_t *data, size_t len) {
    return i2c_read_dt(&config->i2c, data, len);
}
```

### センサー読み取りサイクル

1. **開始コマンド送信** (0x3E) - 単発測定モード開始
2. **ステータス読み取り** - 1バイトのステータス確認
3. **待機** - 100ms待機（Arduino互換）
4. **読み取りコマンド送信** (0x4E) - 測定データ読み取り要求
5. **データ読み取り** - 7バイト（ステータス + XYZ磁気データ）

### キャリブレーションとフィルタリング

```c
// デッドゾーン適用（小さな動きを無視）
const int16_t deadzone = 5;
if (abs(rel_x) < deadzone) rel_x = 0;

// 感度調整（動きを1/4に縮小）
rel_x /= 4;
rel_y /= 4; 
rel_z /= 4;
```

## トラブルシューティング

### 一般的な問題と解決方法

**I2C NACK エラー (0x0BAE0001)**
- ✅ pinctrl設定で `bias-pull-up` が有効化されているか確認
- ✅ I2Cアドレスが正しいか確認（通常は0x0C）
- ✅ 配線とセンサーの物理的接続を確認

**センサーが応答しない**
- ✅ デバッグログでI2C初期化メッセージを確認
- ✅ I2Cバス上でデバイスが検出されるか確認
- ✅ 電源供給とGND接続を確認

**動きが激しすぎる/かくつく**
- ✅ ドライバー内のデッドゾーン値を調整（コード内の `deadzone = 5` を増加）
- ✅ 感度スケーリング値を変更（`/= 4` を `/= 8` に変更等）
- ✅ キャリブレーション完了を待つ（約5秒間）

**キャリブレーションが完了しない**  
- ✅ センサーを静止状態に保つ（約5秒間）
- ✅ デバッグログでキャリブレーション進行状況を確認
- ✅ センサー読み取り値が安定しているか確認

### デバッグ手順

1. **I2C通信確認**: 初期化メッセージをログで確認
2. **設定完了確認**: レジスタ設定のステータス確認  
3. **キャリブレーション確認**: ベースライン設定完了の確認
4. **センサー値監視**: リアルタイムの生データと相対値確認

## 技術仕様

- **ベースライン**: Arduino sample code (ControlEverything.com)
- **I2C周波数**: 100kHz
- **I2Cアドレス**: 0x0C (7bit)
- **データ更新レート**: 設定可能（デフォルト10ms）
- **分解能**: 16bit signed integer per axis
- **感度**: 1/4スケーリング適用済み

## ライセンス

MIT License

## 貢献

プルリクエストやイシューの報告を歓迎します。