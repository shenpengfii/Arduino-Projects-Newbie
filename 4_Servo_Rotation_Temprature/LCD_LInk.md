# 液晶显示屏串口连接笔记

## 接线

| LCD | BOARD |
|:---:|:-----:|
| VSS |  GND  |
| VDD |   5V  |
|  VO |   ~9  |
|  RS |   12  |
| R/W |  GND  |
|  E  |  ~11  |
|  D4 |   ~5  |
|  D5 |   4   |
|  D6 |   ~3  |
|  D7 |   2   |
|  A  |  ~10  |
|  K  |  GND  |

**LCD的火线接口、地线接口不能和其他模块的火线接口、地线接口共用，否则LCD可能输出不稳定**

## 代码

```c++
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS E D4 D5 D6 D7

#define PIN_CTS 9 // contrast pin
#define PIN_BRT 10 // brightness pin

// others could get from the code flie

void setup() {}

void loop() {}
```