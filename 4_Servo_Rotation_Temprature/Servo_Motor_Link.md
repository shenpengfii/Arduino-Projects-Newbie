# 舵机接线笔记

## 走线

- 亮橙色线 ->>> 任意数字端口
- 大红色线 ->>> 5v火线
- 棕色/黑色线 ->>> 地线

## 代码

```c++
#include <Servo.h>
#define PIN_SERVO 9

Servo servo;

void setup() {
    servo.attach(PIN_SERVO);
}

void loop() {
    servo.write(/*...*/);
}
```