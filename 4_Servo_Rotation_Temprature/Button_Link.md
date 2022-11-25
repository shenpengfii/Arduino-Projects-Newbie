# 按钮接线笔记

## 按钮走线

按钮有四个角，但实际上只需要在两边接两根线就可以了（四个角为了方便固定）

- 一边 -> 任意数字端口
- 另一边 -> 地线GND

## 代码

```c++
#define PIN_BUTTON 7

void setup() {
    // 无法使用DDR+PIN进行控制
    pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
    int iButtonState = digitalRead(PIN_BUTTON); // HIGH(0x01)[unpressed] or LOW(0x00)[pressed]
}
```