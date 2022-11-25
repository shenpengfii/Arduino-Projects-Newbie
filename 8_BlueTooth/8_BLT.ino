#include <SoftwareSerial.h>

SoftwareSerial carblt(2, 3);

void setup() {
    Serial.begin(9600);
    carblt.begin(9600);
}

void loop() {
    char s[20];
    int i = 0;
    while (carblt.available()) {
        s[i ++] = carblt.read();
    }
    s[i] = 0;
    Serial.print("Data Received: ");
    Serial.println(s);
}