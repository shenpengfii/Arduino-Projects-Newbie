// #define SENSORS PINB
// #define LIGHTS  PORTD
// #define GOS     0
// #define WAITS   1
// #define GOW     2
// #define WAITW   3

// typedef struct tagSysState{
//     int str;    // 有限状态机的字段串
//     int time;   // 暂停时间
//     int next[4];// 转置状态
// } SYSSTATE;

// const SYSSTATE Fsm[4] = {
//     0x21, 3000, {GOS,WAITS,GOS,WAITS},  // GOS
//     0x22, 500,  {GOW,GOW,GOW,GOW},      // WAITS
//     0x0C, 3000, {GOW,GOW,WAITW,WAITW},  // GOW
//     0x14, 500,  {GOS,GOS,GOS,GOS}       // WAITW
// };

// int curSysState = GOS, sensorState;

// void setup() {
//     pinMode(8, INPUT_PULLUP);
//     pinMode(9, INPUT_PULLUP);
//     DDRB &= B11111100; // 传感（按钮）模块初始化
//     DDRD |= B11111100; // LED灯模块初始化
// }

// void loop() {
//     /*
//     由于使用了delay(), 车流的状态输入会有所延迟，使得灯的变化符合“向对应状态改变”的要求
//     */
//     LIGHTS = (Fsm[curSysState].str) << 2;               // 根据当前状态机，设置Led灯的状态
//     delay(Fsm[curSysState].time);                       // 根据当前状态机，设置亮灯时间
//     sensorState = SENSORS & B00000011;                  // 读取车流
//     curSysState = Fsm[curSysState].next[sensorState];   // 根据车流调整状态机
// }