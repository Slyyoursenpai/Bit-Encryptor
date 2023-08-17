/// output LED variable declaration
int O0LED = 10; /// variable for O0 LED connected to pin 10 
int O1LED = 11; /// variable for O1 LED connected to pin 11 
int O2LED = 12; // variable for O2 LED connected to pin 12 
int O3LED = 13; //variable for O3 LED connected to pin 13 
/// switch input variable declaration
int I0Switch = 2; /// variable for switch O0 connected to pin 2
int I1Switch = 3; /// variable for switch O1 connected to pin 3
int I2Switch = 4; /// variable for switch O2 connected to pin 4
int I3Switch = 5; /// variable for switch O3 connected to pin 5
unsigned long startTime;
unsigned long endTime;


void setup()
{ 
  
  // sets Switches as input
  pinMode(I0Switch,INPUT);
  pinMode(I1Switch,INPUT);
  pinMode(I2Switch,INPUT);
  pinMode(I3Switch,INPUT);
  // sets LEDs as output
  pinMode(O0LED,OUTPUT);
  pinMode(O1LED,OUTPUT);
  pinMode(O2LED,OUTPUT);
  pinMode(O3LED,OUTPUT);
  Serial.begin(9600);
    
}

void loop()
{
  startTime = millis();
  boolean I0State = digitalRead(I0Switch);
  boolean I1State = digitalRead(I1Switch);
  boolean I2State = digitalRead(I2Switch);
  boolean I3State = digitalRead(I3Switch);
  boolean O0State;
  boolean O1State;
  boolean O2State;
  boolean O3State;

 // Kmap Equation Logic
 O0State= (!I0State & !I1State & !I2State & !I3State)|(!I0State & I1State & I3State)|(I0State & !I1State & I3State)|(I0State & I1State& !I2State);
 O1State= (!I1State & !I2State & I3State)|(I0State & I1State & !I2State)|(!I0State & I2State)|(I1State & !I3State);
 O2State= (!I0State & !I1State & !I2State)|(!I1State & !I3State)|(I2State & !I3State);
 O3State= (!I0State & !I1State & I3State)|(I0State & I1State & I2State)|(!I2State & !I3State)|(I0State & !I3State);
 
 digitalWrite(O0LED,O0State);
 digitalWrite(O1LED,O1State);
 digitalWrite(O2LED,O2State);
 digitalWrite(O3LED,O3State);
 Serial.print(O3State);
  Serial.print(O2State);
  Serial.print(O1State);
  Serial.println(O0State);
  endTime = millis();
  Serial.print("Execution Time:");
  Serial.print(endTime-startTime);
  Serial.println(" ms");
 // delay(1000);
  }

 

