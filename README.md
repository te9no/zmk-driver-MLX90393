# ZMK MLX90393 Magnetic Sensor Input Driver

ZMK (Zephyr Mechanical Keyboard) ファームウェア用のMLX90393磁気センサー入力ドライバーです。

## 概要

このドライバーは、MLX90393 3軸磁気センサーからデータを読み取り、Z軸の値に基づいて2つの状態（通常/押し込み）を検出し、状態に応じて異なるbehavior bindingを実行します。

### 主要機能

- **I2C通信**: MLX90393センサーとの通信
- **2状態検出**: Z軸閾値による通常/押し込み状態の判定
- **ヒステリシス**: 状態振動を防ぐヒステリシス機能
- **自動キャリブレーション**: 30秒間無動作後の自動基準点設定
- **デッドゾーン**: 小さな動きをフィルタリング
- **Behavior Binding**: 状態に応じた異なるキーマップアクション

## インストール

### 1. west.ymlに追加

```yaml
manifest:
  projects:
    - name: zmk-driver-MLX90393
      remote: github
      repo: your-username/zmk-driver-MLX90393
      revision: v1
      path: modules/zmk-driver-MLX90393
```

### 2. ボード設定での有効化

`<board>.conf`ファイルで有効化：

```ini
CONFIG_ZMK_INPUT_MLX90393=y
```

### 3. デバイスツリー設定

キーマップファイル（`.keymap`）で設定：

```dts
/ {
    // Behavior bindings
    behaviors {
        normal_mouse: normal_mouse {
            compatible = "zmk,behavior-mouse-key-press";
            #binding-cells = <1>;
            time-to-max-speed-ms = <300>;
            acceleration-exponent = <1>;
        };
        
        pressed_mouse: pressed_mouse {
            compatible = "zmk,behavior-mouse-key-press";
            #binding-cells = <1>;
            time-to-max-speed-ms = <150>;
            acceleration-exponent = <2>;
        };
    };
};

&i2c0 {
    mlx90393_input: mlx90393-input@0c {
        compatible = "melexis,mlx90393-input";
        reg = <0x0C>;
        
        polling-interval-ms = <10>;
        z-press-threshold = <50>;
        z-hysteresis = <10>;
        
        normal-binding = <&normal_mouse MOVE_X>;
        pressed-binding = <&pressed_mouse MOVE_X>;
        
        deadzone-x = <3>;
        deadzone-y = <3>;
        deadzone-z = <5>;
        
        movement-threshold = <20>;
        auto-calibration-timeout-s = <30>;
    };
};
```

## 設定オプション

### デバイスツリープロパティ

| プロパティ | デフォルト値 | 説明 |
|-----------|-------------|------|
| `polling-interval-ms` | 10 | センサー読み取り間隔（ミリ秒） |
| `z-press-threshold` | 50 | Z軸押し込み検出閾値 |
| `z-hysteresis` | 10 | Z軸ヒステリシス値 |
| `normal-binding` | - | 通常状態のbehavior binding（必須） |
| `pressed-binding` | - | 押し込み状態のbehavior binding（必須） |
| `deadzone-x` | 3 | X軸デッドゾーン |
| `deadzone-y` | 3 | Y軸デッドゾーン |
| `deadzone-z` | 5 | Z軸デッドゾーン |
| `movement-threshold` | 20 | 動き検出閾値 |
| `auto-calibration-timeout-s` | 30 | 自動キャリブレーションタイムアウト（秒） |

### Kconfigオプション

| オプション | デフォルト値 | 説明 |
|-----------|-------------|------|
| `CONFIG_ZMK_INPUT_MLX90393` | n | ドライバーの有効化 |
| `CONFIG_ZMK_INPUT_MLX90393_INIT_PRIORITY` | 80 | 初期化優先度 |
| `CONFIG_ZMK_INPUT_MLX90393_LOG_LEVEL` | 3 | ログレベル (0-4) |

## 使用例

### 基本設定

最小限の設定例：

```dts
&i2c0 {
    mlx90393_input: mlx90393-input@0c {
        compatible = "melexis,mlx90393-input";
        reg = <0x0C>;
        normal-binding = <&mkp LCLK>;
        pressed-binding = <&mkp MCLK>;
    };
};
```

### 高詳細設定

カスタマイズされた設定例：

```dts
&i2c0 {
    mlx90393_input: mlx90393-input@0c {
        compatible = "melexis,mlx90393-input";
        reg = <0x0C>;
        
        polling-interval-ms = <5>;    // より高い応答性
        z-press-threshold = <100>;    // より強い押し込み要求
        z-hysteresis = <20>;          // より安定した状態検出
        
        normal-binding = <&custom_normal>;
        pressed-binding = <&custom_pressed>;
        
        deadzone-x = <5>;
        deadzone-y = <5>;
        deadzone-z = <8>;
        
        movement-threshold = <15>;
        auto-calibration-timeout-s = <60>;
    };
};
```

## トラブルシューティング

### センサーが検出されない

1. I2Cアドレスを確認（通常0x0C）
2. I2Cバスの設定を確認
3. センサーの電源供給を確認

### 状態検出が不安定

1. `z-hysteresis`値を増加
2. `deadzone-z`値を調整
3. `movement-threshold`を調整

### 自動キャリブレーションが動作しない

1. `auto-calibration-timeout-s`を確認
2. ログレベルを上げてデバッグ情報を確認
3. センサーが実際に静止していることを確認

## ログとデバッグ

ログレベルを上げることで詳細な情報を取得できます：

```ini
CONFIG_ZMK_INPUT_MLX90393_LOG_LEVEL=4
```

ログ出力例：
```
[INF] input_mlx90393: MLX90393 input driver initialized
[DBG] input_mlx90393: State changed to pressed
[INF] input_mlx90393: Auto-calibration completed: baseline X=1234, Y=5678, Z=9012
```

## ライセンス

MIT License

## 貢献

プルリクエストやイシューの報告を歓迎します。