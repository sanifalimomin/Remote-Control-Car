#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
AF_DCMotor motor4(4, MOTOR12_8KHZ);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
}

int command;
void forward(){
    motor1.run (FORWARD);
    motor2.run (FORWARD);
    motor3.run (FORWARD);
    motor4.run (FORWARD);
    delay(50);
}

void backward(){
    motor1.run (BACKWARD);
    motor2.run (BACKWARD);
    motor3.run (BACKWARD);
    motor4.run (BACKWARD);
    delay(50);
}

void right(){
    motor1.run (FORWARD);
    motor2.run (FORWARD);
      
    motor3.run (RELEASE);
    motor4.run (RELEASE);
    delay(50);
}

void left(){
    motor1.run (RELEASE);
    motor2.run (RELEASE);
      
    motor3.run (FORWARD);
    motor4.run (FORWARD);
    delay(50);
}

void stopcar(){
    motor1.run (RELEASE);
    motor2.run (RELEASE);
    motor3.run (RELEASE);
    motor4.run (RELEASE);
    delay(50);
}
void forwardright(){
    motor1.run (FORWARD);
    motor2.run (FORWARD);
      
    motor3.run (FORWARD);
    motor4.run (RELEASE);
    delay(50);
}

void forwardleft(){
    motor1.run (RELEASE);
    motor2.run (FORWARD);
      
    motor3.run (FORWARD);
    motor4.run (FORWARD);
    delay(50);
}

void backwardright(){
    motor1.run (BACKWARD);
    motor2.run (BACKWARD);
      
    motor3.run (RELEASE);
    motor4.run (BACKWARD);
    delay(50);
}

void backwardleft(){
    motor1.run (BACKWARD);
    motor2.run (RELEASE);
      
    motor3.run (BACKWARD);
    motor4.run (BACKWARD);
    delay(50);
}
void setspeedofcar(int speedofcar){
    motor1.setSpeed(speedofcar);
    motor2.setSpeed(speedofcar);
    motor3.setSpeed(speedofcar);
    motor4.setSpeed(speedofcar);
    delay(50);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    command = Serial.read();
    stopcar(); 
  }
  switch(command){
    case 'F':forward(); break;
    case 'B':backward(); break;
    case 'L':left(); break;
    case 'R':right(); break;
    case 'S':stopcar(); break;
    
    case 'I':forwardright(); break;
    case 'G':forwardleft(); break;
    case 'J':backwardright(); break;
    case 'H':backwardleft(); break;
    
    case '0':setspeedofcar(100);break;
    case '1':setspeedofcar(115);break;
    case '2':setspeedofcar(130);break;
    case '3':setspeedofcar(145);break;
    case '4':setspeedofcar(160);break;  
    case '5':setspeedofcar(175);break;
    case '6':setspeedofcar(190);break;
    case '7':setspeedofcar(205);break;  
    case '8':setspeedofcar(220);break;
    case '9':setspeedofcar(235);break;
    case 'q':setspeedofcar(255);break;
  }
}
