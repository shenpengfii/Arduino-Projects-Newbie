#include <ezButton.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <DHT.h>

#define PIN_DHT 8
#define PIN_LCD_CONTRAST 9 // lcd对比度pin
#define PIN_LCD_BRIGHTNESS 10   // lcd亮度pin
#define PIN_SERVO 6
#define PIN_JOY_BUTTON 7
#define ANA_JOY_X A0
#define ANA_JOY_Y A1
#define ANA_POTENTIOMETER A2

DHT dht(PIN_DHT, DHT11);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // see the markdown file
Servo servo;
ezButton joyButton(PIN_JOY_BUTTON);

unsigned long iTime;
float tempC, tempF;

void setup() {
    dht.begin();
    lcd.begin(16, 2); // 16x2 LCD
    servo.attach(PIN_SERVO);

    analogWrite(PIN_LCD_CONTRAST, 0); // 低对比度下字体可以被显示出来
    analogWrite(PIN_LCD_BRIGHTNESS, 255); // 点亮屏幕
}

void loop() {
    joyButton.loop(); // ezButton要求loop
    
    // 控制舵机转向
    servo.write(map(analogRead(ANA_POTENTIOMETER), 0, 1023, 0, 180));    

    // 隔一秒测一次温
    unsigned long iCur = millis();
    if (iCur - iTime >= 1000) {
        iTime = iCur;
        tempC = dht.readTemperature();
        tempF = dht.readTemperature(true);
    }

    // 长按显示华氏温度，松开显示摄氏温度
    lcd.setCursor(0, 0);
    lcd.print("Temprature");
    lcd.setCursor(0, 1);
    if (joyButton.getState() == HIGH) {
        lcd.print(tempC);
        lcd.print("C");
    } else {
        lcd.print(tempF);
        lcd.print("F");
    }
}
