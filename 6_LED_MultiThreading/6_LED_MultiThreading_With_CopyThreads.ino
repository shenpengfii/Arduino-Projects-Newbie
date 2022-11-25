/*---(c)2022, MultiThreading Leds---*/

#include <Cth.h>
#include <LED.h>

int pin[6] = {2, 3, 4, 5, 6, 7};

void myfade(int pin) {
    LED led = LED(pin);
    int dTime = random(100, 2000);
    led.fadeIn(dTime);
    led.fadeOut(dTime);
}

void loop0() { myfade(pin[0]); }
void loop1() { myfade(pin[1]); }
void loop2() { myfade(pin[2]); }
void loop3() { myfade(pin[3]); }
void loop4() { myfade(pin[4]); }
void loop5() { myfade(pin[5]); }

void setup() {
    randomSeed(millis());
    Scheduler.startLoop(loop0);
    Scheduler.startLoop(loop1);
    Scheduler.startLoop(loop2);
    Scheduler.startLoop(loop3);
    Scheduler.startLoop(loop4);
    Scheduler.startLoop(loop5);
}