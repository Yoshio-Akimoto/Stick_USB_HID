// arduino joystick library Header file
#include <Joystick.h>

// 定数定義
#define SW_PIN 7
#define ANALOG_PIN_1 A0
#define ANALOG_PIN_2 A1
#define ANALOG_PIN_3 A2

// Joystickメンバ設定
Joystick_ Joystick(//有効無効を切り替える
  0x03, //hid report id
  JOYSTICK_TYPE_GAMEPAD, //joystick type
  1, //button count   <- 使用するスイッチの数 [予備]
  0, //Hsw 0-2
  true, //x         <- サムスティック X軸 [Analog]
  true, //y         <- サムスティック Y軸 [Analog]
  false, //z
  false, //rx
  false, //ry
  false, //rz
  false, //rudder
  true, //throttle  <- スロットル V軸 [Analog]
  false, //accelerator
  false, //brake
  false//steeing;
);

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP); //ピンの設定 [Digital]
  pinMode(A0, INPUT); //ピンの入出力論理 [Analog]
  pinMode(A1, INPUT); //ピンの入出力論理 [Analog]
  pinMode(A2, INPUT); //ピンの入出力論理 [Analog]
  Joystick.begin();   //Joystickライブラリを使用するため必須
  Joystick.setXAxisRange(0,1023);    //Aalogピンの値範囲を設定
  Joystick.setYAxisRange(0,1023);    //Aalogピンの値範囲を設定
  Joystick.setThrottleRange(0,1023); //Aalogピンの値範囲を設定。
}

void loop() {
    Joystick.setXAxis(analogRead(ANALOG_PIN_1));    //サムスティック X軸の値を読み取りセット
    Joystick.setYAxis(analogRead(ANALOG_PIN_2));    //サムスティック Y軸の値を読み取りセット
    Joystick.setThrottle(analogRead(ANALOG_PIN_3)); //スロットル    V軸の値を読み取りセット
    Joystick.setButton(0, digitalRead(SW_PIN));     //スイッチ(予備)の値を読み取りセット
}