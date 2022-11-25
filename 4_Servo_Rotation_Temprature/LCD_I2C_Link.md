# LCD_I2C接线笔记

## 走线

| LCD_I2C | BOARD |
|:-------:|:-----:|
|   GND   |  GND  |
|   VCC   |   5V  |
|   SDA   |   A4  |
|   SCL   |   A5  |

## 代码

```c++
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init();
  lcd.backlight(); // 打开背灯

  lcd.setCursor(0, 0); // 打印内容
  lcd.print("Arduino");
  lcd.setCursor(2, 1);
  lcd.print("GetStarted.com");
}

void loop()
{
}

```