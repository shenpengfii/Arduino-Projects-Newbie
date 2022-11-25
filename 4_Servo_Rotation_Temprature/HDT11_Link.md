# HDT11温湿度传感器模块接线

## 走线

模块以从‘s’到‘-’的顺序放置（在模块上有标注符号）

从左到右分别为：
- 信号线（可接任意数字端口）
- 5v火线（火线必须加一个电阻！！！否则输出nan）
- 地线

## 代码

```c++
#include <DHT.h>

#define DHTPIN 8 // 任意数字端口

DHT dht(DHTPIN, DHT11);

void setup() {
    dht.begin();
}

void loop() {
    // ...
}
```