# 电位器接线笔记

## 走线

正对电位器的帽子看去（大帽头离眼睛更近）：

| Potentiometer | BOARD |
|:-------------:|:-----:|
|      LEFT     |   5V  |
|      MID      |   A0  |
|     RIGHT     |  GND  |

左边火线，右边地线，中间为**类比脉冲**线。

## 代码

```c++
int val = analogRead(A0);
```