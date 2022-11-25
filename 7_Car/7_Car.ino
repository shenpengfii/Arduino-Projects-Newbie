// 7s数据一：LBS 55 RBS 85 kp 10 ki 0.001/0.0005
// 6s数据二：LBS 75 RBS 115 kp 13
// 5s数据三：LBS 122 RBS 122 kp 22

const int L1 = 2;
const int L2 = 4;
const int R1 = 7;
const int R2 = 8;
const int LS = 3;
const int RS = 5;
const int LBS = 230;
const int RBS = 200;
const int SENSER[5] = { A0, A1, A2, A3, A4 };

void setup() {
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(LS, OUTPUT);
    pinMode(RS, OUTPUT);
    
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    analogWrite(LS, LBS);
    analogWrite(RS, RBS);

    pinMode(SENSER[0], INPUT);
    pinMode(SENSER[1], INPUT);
    pinMode(SENSER[2], INPUT);
    pinMode(SENSER[3], INPUT);
    pinMode(SENSER[4], INPUT);
}


void loop() {
    // kp:ki:kd ≈ 100:1:10
    const float kp = 45;
    const float ki = 0, kd = 0;
    static float last_err, sum_err, last_det;
    float err;

    int sensors = readSensors();
    if (last_det == 4 && sensors != 0b11111) // 已经检测到黑线，并且上个周期为持续大右转
        last_det = 0;
    switch(sensors) {
    case 0b01111:
        err = -4; break;
    case 0b00111:
        err = -3; break;
    case 0b10111:
        err = -2; break;
    case 0b10011:
        err = -1; break;
    case 0b11011:
        err = 0; break;
    case 0b11001:
        err = 1; break;
    case 0b11101:
        err = 2; break;
    case 0b11100:
        err = 3; break;
    case 0b11110:
        err = 4; 
        last_det = 4;
        break;
    case 0b11111: // 脱离黑线
        if (last_det == 4)
            err = 4; // 上次检测到右边线，则大右转
        else 
            err = -4; // （左边传感器坏了，默认上次检测到黑线）自动大左转
        break; 
    default:
        err = 0;
    }

    sum_err += err;
    int output = kp * err + ki * sum_err + kd * (err-last_err);
    last_err = err;

    analogWrite(LS, min(max(LBS + output,0), 255));
    analogWrite(RS, min(max(RBS - output,0), 255));
}

inline int readSensors() {
    int ans = 0;
    for (int i = 0; i < 5; ++ i) {
        ans <<= 1;
        ans ^= digitalRead(SENSER[i]);
    }
    return ans;
}