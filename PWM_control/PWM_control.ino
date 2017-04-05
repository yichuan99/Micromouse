#define motorDIR_L 2
#define motorPWM_L 3
#define motorDIR_R 4
#define motorPWM_R 11

void PWM_init(){
  pinMode(motorDIR_L, OUTPUT);
  pinMode(motorPWM_L, OUTPUT);
  pinMode(motorDIR_R, OUTPUT);
  pinMode(motorPWM_R, OUTPUT);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);
  OCR2A = 0;
  OCR2B = 0;
  digitalWrite(motorDIR_L, LOW);
  digitalWrite(motorDIR_R, LOW);
}

void WritePWM(int pwm_A, int pwm_B){
  OCR2A = pwm_A;
  OCR2B = pwm_B;
}

void MotorSpeed(int motor_L, int motor_R){

  motor_L *= 2.55;
  motor_R *= 2.55;
  
  if(motor_L >= 0)digitalWrite(motorDIR_L, LOW);  
  else{
    digitalWrite(motorDIR_L, HIGH);
    motor_L += 255;
  }
  
  if(motor_R>=0)digitalWrite(motorDIR_R, LOW);  
  else{
    digitalWrite(motorDIR_R, HIGH);
    motor_R += 255;
  }

  if(motor_L>255)motor_L=255;
  if(motor_L<0)motor_L=0;
  if(motor_R>255)motor_R=255;
  if(motor_R<0)motor_R=0;
  
  WritePWM(motor_L, motor_R);
}

void setup() {
  PWM_init();
}

void loop() {
  MotorSpeed(-100, 100);
}
