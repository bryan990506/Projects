unsigned const int A = 1;
unsigned const int B = 2;
unsigned const int C = 4;
unsigned const int D = 7;
unsigned const int E = 8;
unsigned const int F = 12;
unsigned const int G = 13;
unsigned const int DP = 0;
int CC1 = 11;
int CC2 = 10;
int CC3 = 9;

float tempmV;
float temperatureC;
int setpoint = 40;
int sensorValue = 0;
int sensor = A0;
int D6 = 6;
int D5 = 5;
#define PIN_SWITCH 6
#define PIN_SENSOR A0



void setup(void)
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(CC1, OUTPUT);
  pinMode(CC2, OUTPUT);
  pinMode(CC3, OUTPUT);
  
  Serial.begin(9600);
  pinMode(PIN_SENSOR, INPUT);
  pinMode(PIN_SWITCH, OUTPUT);
  
}

void display1(int num)
{
  
  switch(num)
  {
case 0: {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  break;
}

case 1: {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  break;

}

case 2: {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  break;
}

case 3: {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);

}

case 4: {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;

}

case 5: {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;

}

case 6: {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;

}

case 7: {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  break;

}

case 8: {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;

}

case 9: {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;
}
}
}



void disp(void) 
{
  display1((temperatureC / 100) * 10);
  digitalWrite(CC1, LOW);
  digitalWrite(CC2, LOW);
  digitalWrite(CC3, LOW);
  delay(1000);
  
  
}


// Start
void loop(void)
{
  digitalWrite(D6, HIGH);
  digitalWrite(D5, HIGH);
  int sensorValue = analogRead(A0);
  tempmV = ((sensorValue) * 1023 * 5000) + 40;
  temperatureC = ((5.506 - sqrt(sq(-5.506) + (4 * 0.00176 * (870.6 - tempmV))))/(2 * -0.00176)) + 30;
  Serial.print("Temperature in Degree celsius: "); Serial.println(temperatureC, 1);
  Serial.print("Analog: "); Serial.println(sensorValue);
  Serial.print("mVolts: "); Serial.println(tempmV, 1);
  

if (temperatureC > setpoint)
{
  digitalWrite(PIN_SWITCH, HIGH);
  delay(500);
} else {
  digitalWrite(PIN_SWITCH, LOW);
  delay(500);
  }
  
  disp();
  delay(1000);
}  
