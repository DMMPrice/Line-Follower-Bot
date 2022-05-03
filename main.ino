#define echopin 7 // echo pin
#define trigpin 8 // Trigger pin

int S_A = 9; 
int S_B = 10; 
int M_B1 = 4;
int M_B2 = 5;

int M_A1 = 2;
int M_A2 = 3;


int speed = 35;

int frontdist;
long duration;

int setdist= 10;

int L_S = 11; //sincer L
int S_S = 12; 
int R_S = A0; //sincer R
void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);
pinMode(echopin,INPUT);
pinMode(trigpin, OUTPUT);

pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);
Serial.begin(9600);

}
void forword(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}


void turnRight(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}

void turnLeft(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}

void Stop(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}

void loop(){

  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  // Sets the trigpin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigpin, LOW);
  // Reads the echopin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);
  frontdist = duration * 0.034 / 2;
  Serial.println(frontdist);
  
if(frontdist>setdist)
{
  if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){
    analogWrite(S_A, 60); 
    analogWrite(S_B, 60);
    forword();
    }


  else if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){
    analogWrite(S_A, 80); 
    analogWrite(S_B, 80);
    turnLeft();
    }
  else if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) ==1)&&(digitalRead(R_S) == 1)) {
    analogWrite(S_A, 80); 
    analogWrite(S_B, 80);
    turnLeft();
    }

  else if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){
    analogWrite(S_A, 80); 
    analogWrite(S_B, 80);
    turnRight();
    }
  else if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){
    analogWrite(S_A, 80); 
    analogWrite(S_B, 80);
    turnRight();
    }

  else if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){
     analogWrite(S_A, 80); 
    analogWrite(S_B, 80);
    turnLeft();
   
    }
  else if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){
    Stop();
    }
}
else
{
   Stop();
   delay(500);
  if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){
    analogWrite(S_A, 80); 
    analogWrite(S_B, 80);
    turnLeft();
    }
  else if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) ==1)&&(digitalRead(R_S) == 1)) {
    analogWrite(S_A, 80); 
    analogWrite(S_B, 80);
    turnLeft();
    }

  else if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){
    analogWrite(S_A, 70); 
    analogWrite(S_B, 70);
    turnRight();
    }
  else if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){
    analogWrite(S_A, 70); 
    analogWrite(S_B, 70);
    turnRight();
    }

  else if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){
    Stop();
    }
  else if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){
    analogWrite(S_A, 70); 
    analogWrite(S_B, 70);
    turnRight();}
  }
}

//long data(){
//digitalWrite(trigpin, LOW);
// delayMicroseconds(2);
// // Sets the trigpin HIGH (ACTIVE) for 10 microseconds
// digitalWrite(trigpin, HIGH);
// delayMicroseconds(10);
// digitalWrite(trigpin, LOW);
// // Reads the echopin, returns the sound wave travel time in microseconds
// duration = pulseIn(echopin, HIGH);
// // Calculating the distance
//long distance = duration * 0.034 / 2;
//Serial.println(distance); 
// return distance;
//}


                                                    
