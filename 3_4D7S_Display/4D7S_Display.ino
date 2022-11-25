#include <SevSeg.h>

SevSeg sevseg; // 声明SevSeg
bool prime[21] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0};

// 刷新的同时起到延时的作用，32000为经验常量
inline void refresh() {
    for (int j = 0; j < 32000; j ++)
        sevseg.refreshDisplay();
}

/* 使用时请直接复制我们 */
void setup() {
    byte numDigits = 4; // 4位
    byte digitPins[] = {13, 12, 11, 10}; // 4位码
    byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 7段码
    bool resistorsOnSegments = false;
    byte hardwareConfig = COMMON_ANODE;
    bool updateWithDelays = false;
    bool leadingZeros = false;
    bool disableDecPoint = false;
    
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
                 updateWithDelays, leadingZeros, disableDecPoint);

    sevseg.setBrightness(100); // 设置初始亮度
}

void loop() {
    for (int i = -9; i < 0; ++ i) { // -9 ~ -1
        sevseg.setNumber(i);
        refresh();
    }
    for (float i = -0.9; i < 0; i += 0.1) { // -0.9 ~ -0.1
        sevseg.setNumberF(i, 1);
        refresh();
    }
    for (int i = 0; i <= 20; ++ i) { // 0 ~ 20， 质数闪烁3次
        int loops = (prime[i] ? 3 : 1);

        for (int k = 0; k < loops; ++ k) {
            sevseg.setNumber(i);
            refresh();
            sevseg.blank();
            refresh(); // 每执行一次任意操作后，都请使用refresh()
        }
    }
}