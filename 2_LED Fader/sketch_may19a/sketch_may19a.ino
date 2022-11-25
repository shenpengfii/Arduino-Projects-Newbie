#include <LED.h>

LED led[3] = {LED(3), LED(5), LED(6)};

void setup() {}

void loop() {
  for (int i = 0; i < 3; ++ i) {
    led[i].fadeIn(200);
    led[i].fadeOut(200);
  }
}
