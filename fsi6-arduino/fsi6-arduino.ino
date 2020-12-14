int mr1 = 52;
int mr2 = 53;
int ml1 = 50;
int ml2 = 51;
int gripper1 = 48;
int gripper2 = 49;
int arm1 = 46;
int arm2 = 47;
int enablegripper = 3;
int enablearm = 2;
int enablemr = 4;
int enableml = 5;
int channel_1 = 10;
int channel_2 = 11;

void setup()
{
  pinMode(channel_1, INPUT);
  pinMode(channel_2, INPUT);
  pinMode(mr1, OUTPUT);
  pinMode(mr2, OUTPUT);
  pinMode(ml1, OUTPUT);
  pinMode(ml2, OUTPUT);
  pinMode(gripper1, OUTPUT);
  pinMode(gripper2, OUTPUT);
  pinMode(arm1, OUTPUT);
  pinMode(arm2, OUTPUT);
  pinMode(enablemr, OUTPUT);
  pinMode(enableml, OUTPUT);
  pinMode(enablegripper, OUTPUT);
  pinMode(enablearm, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int channel_1_value = pulseIn(channel_1, HIGH);
  int channel_2_value = pulseIn(channel_2, HIGH);
  if (channel_2_value > 2000 && channel_1_value > 1900 && channel_1_value < 2100) {
    forward(channel_2_value);
  }
  else if (channel_2_value < 1900 && channel_1_value > 1900 && channel_1_value < 2100) {
    backward(channel_2_value);
  }
  else if (channel_1_value > 2000 && channel_2_value > 1900 && channel_2_value < 2100) {
    right(channel_1_value);
  }
  else if (channel_1_value < 1900 && channel_2_value > 1900 && channel_2_value < 2100) {
    left(channel_1_value);
  }
  else if (channel_2_value > 2000 && channel_1_value > 2100) {
    forwardright(channel_1_value, channel_2_value);
  }
  else if (channel_2_value > 2000 && channel_1_value < 1900) {
    forwardleft(channel_1_value, channel_2_value);
  }
  else if (channel_2_value < 1900 && channel_1_value < 1900) {
    backwardleft(channel_1_value, channel_2_value);
  }
  else if (channel_2_value < 1900 && channel_1_value > 2100) {
    backwardright(channel_1_value, channel_2_value);
  }
  else {
    digitalWrite(mr1, LOW);
    digitalWrite(mr2, LOW);
    digitalWrite(ml1, LOW);
    digitalWrite(ml2, LOW);
    digitalWrite(gripper1, LOW);
    digitalWrite(gripper2, LOW);
    digitalWrite(arm1, LOW);
    digitalWrite(arm2, LOW);
    analogWrite(enablemr, 0);
    analogWrite(enableml, 0);
    analogWrite(enablegripper, 0);
    analogWrite(enablearm, 0);
  
}
void forward(int forvalue) {
  int pwm = map(forvalue, 2000, 2615, 0, 255);
  digitalWrite(mr1, HIGH);
  digitalWrite(ml1, HIGH);
  analogWrite(enablemr, pwm);
  analogWrite(enableml, pwm);
}
void backward(int backvalue) {
  int pwm = map(backvalue, 1900, 1300, 0, 255);
  digitalWrite(mr2, HIGH);
  digitalWrite(ml2, HIGH);
  analogWrite(enablemr, pwm);
  analogWrite(enableml, pwm);
}
void right(int rightvalue) {
  int pwm = map(rightvalue, 2000, 2615, 0, 255);
  digitalWrite(mr2, HIGH);
  digitalWrite(ml1, HIGH);
  analogWrite(enablemr, pwm);
  analogWrite(enableml, pwm);

}
void left(int leftvalue) {
  int pwm = map(leftvalue, 1900, 1300, 0, 255);
  digitalWrite(mr1, HIGH);
  digitalWrite(ml2, HIGH);
  analogWrite(enablemr, pwm);
  analogWrite(enableml, pwm);
}
void forwardright(int channel1, int channel2) {
  int pwm = map(channel2, 2000, 2615, 0, 255);
  int pwm2 = map(channel1, 2000, 2615, 255, 0);
  digitalWrite(mr1, HIGH);
  digitalWrite(ml1, HIGH);
  analogWrite(enablemr, pwm);
  analogWrite(enableml, pwm2);
}
void forwardleft(int channel1, int channel2) {
  int pwm = map(channel2, 2000, 2615, 0, 255);
  int pwm2 = map(channel1, 1900, 1300, 255, 0);
  digitalWrite(mr1, HIGH);
  digitalWrite(ml1, HIGH);
  analogWrite(enablemr, pwm2);
  analogWrite(enableml, pwm);
}
void backwardright(int channel1, int channel2) {
  int pwm = map(channel2, 1900, 1300, 0, 255);
  int pwm2 = map(channel1, 2000, 2615, 255, 0);
  digitalWrite(mr2, HIGH);
  digitalWrite(ml2, HIGH);
  analogWrite(enablemr, pwm2);
  analogWrite(enableml, pwm);

}
void backwardleft(int channel1, int channel2) {
  int pwm = map(channel2, 1900, 1300, 0, 255);
  int pwm2 = map(channel1, 1900, 1300, 255, 0);
  digitalWrite(mr2, HIGH);
  digitalWrite(ml2, HIGH);
  analogWrite(enablemr, pwm);
  analogWrite(enableml, pwm2);
}
