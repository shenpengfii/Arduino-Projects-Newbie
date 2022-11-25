/*
@ Project: 交通灯
@ I/O: LED(2~7), Button(8, 9)
@ I/O: 234 -> 西侧绿黄红灯, I/O 567 -> 南侧绿黄红灯
@ I/O: 8 -> 北侧来车, 9 -> 东侧来车
*/

#include <StateMachine.h>

#define SENSORS PINB
#define LIGHTS  PORTD

// 创建FSM
StateMachine machine = StateMachine();

// 设置状态
State* gos   = machine.addState([]{LIGHTS = B10000100; delay(3000);});
State* waits = machine.addState([]{LIGHTS = B10001000; delay(500);});
State* gow   = machine.addState([]{LIGHTS = B00110000; delay(3000);});
State* waitw = machine.addState([]{LIGHTS = B01010000; delay(500);});

void setup() {
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    DDRD = B11111100;

    // 为状态添加转置
    gos   -> addTransition([]{return SENSORS & B00000001;}, waits);
    waits -> addTransition([]{return true;}, gow);
    gow   -> addTransition([]{return SENSORS & B00000010;}, waitw);
    waitw -> addTransition([]{return true;}, gos);
}

void loop() {
    // 运行
    machine.run();
}