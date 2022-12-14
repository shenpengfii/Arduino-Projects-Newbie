# 四位七段码
## 接线说明
![四位七段码显示屏接头图示](https://osoyoo.com/wp-content/uploads/2017/08/4-digit-7-segment-LED-display-pinout.png)

可简化为：  
| 1 | A | F | 2 | 3 | B |
|---|---|---|---|---|---|
| E | D | P | C | G | 4 |

这些接口需要与开发板上的2-13号接口连接。  
理论上可以任意对应连接，只须确保如下对应规则
```c
  // 数组内存储的是开发板上的接口数字，需要与显示屏对应
  byte digitPins[] = { // 四个数位码
      13, // A 
      12, // B
      11, // C
      10};// D
  byte segmentPins[] = { // 7段码+小数点码
      2, // 1
      3, // 2
      4, // 3
      5, // 4
      6, // 5
      7, // 6 
      8, // 7
      9};// P
```

## 连接方案
### 接线规则
| Board | 4D7S |
|:-----:|:----:|
|   2   |   A  |
|   3   |   B  |
|   4   |   C  |
|   5   |   D  |
|   6   |   E  |
|   7   |   F  |
|   8   |   G  |
|   9   |   P  |
|   10  |   4  |
|   11  |   3  |
|   12  |   2  |
|   13  |   1  |

### 代码
```c
// 代码
byte digitPins[] = {13, 12, 11, 10};
byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
```