void PWM_init(){
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);
  OCR2A = 180;
  OCR2B = 50;
}

void WritePWM(char A, char B, int pwm_A, int pwm_B){
  if(A>0)OCR2A = pwm_A;
  if(B>0)OCR2B = pwm_B;
}

void MotorSpeed(int motor_1, int motor_2){
  WritePWM(1,1,motor_1, motor_2);
}

void setup() {
  PWM_init();
}

void loop() {
  MotorSpeed(200, 200); //80% power
}
