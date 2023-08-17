/*/ Output LED pin numbers
const int O0LED_PIN = 10;
const int O1LED_PIN = 11;
const int O2LED_PIN = 12;
const int O3LED_PIN = 13;

// Switch input pin numbers
const int I0Switch_PIN = 2;
const int I1Switch_PIN = 3;
const int I2Switch_PIN = 4;
const int I3Switch_PIN = 5;

void setup() {
  DDRD &= B11111011; // sets pin 2 to input
  DDRD &= B11110111; // sets pin 3 to input
  DDRD &= B11101111; // sets pin 4 to input
  DDRD &= B11011111; // sets pin 5 to input

  DDRB |= B00000100; // sets pin 10 to output
  DDRB |= B00001000;  // sets pin 11 to output
  DDRB |= B00010000;  // sets pin 12 to output
  DDRB |= B00100000; // sets pin 13 to output
}

void loop() {
   

} *///////////// Separate



// output LED variable declaration
// O0LED = 10; // variable for O0 LED connected to pin 10 
// O1LED = 11; // variable for O1 LED connected to pin 11 
// O2LED = 12; // variable for O2 LED connected to pin 12 
// O3LED = 13; //variable for O3 LED connected to pin 13 

// switch input variable declaration
// I0Switch = 2; // variable for switch O0 connected to pin 2
// I1Switch = 3; // variable for switch O1 connected to pin 3
// I2Switch = 4; // variable for switch O2 connected to pin 4
// I3Switch = 5; // variable for switch O3 connected to pin 5
unsigned long startTime;
unsigned long endTime;

void setup()
{
  
  // sets Switches as input
  DDRD &= ~(1 << 2); // sets PORTD bit 2 as input
  DDRD &= ~(1 << 3); // sets PORTD bit 3 as input
  DDRD &= ~(1 << 4); // sets PORTD bit 4 as input
  DDRD &= ~(1 << 5); // sets PORTD bit 5 as input
  // sets LEDs as output
  DDRB |= (1 << 2); // sets PORTB bit 2 as output
  DDRB |= (1 << 3); // sets PORTB bit 3 as output
  DDRB |= (1 << 4); // sets PORTB bit 4 as output
  DDRB |= (1 << 5); // sets PORTB bit 5 as output; 
  Serial.begin(9600);
  
}

void loop()
{ 
  startTime = micros();
  // read the switch states
  bool I0State = (PIND & (1 << 2)) != 0;
  bool I1State = (PIND & (1 << 3)) != 0;
  bool I2State = (PIND & (1 << 4)) != 0;
  bool I3State = (PIND & (1 << 5)) != 0;

  // calculate the LED states
  bool O0State = (!I0State & !I1State & !I2State & !I3State) |
                   (!I0State & I1State & I3State) |
                   (I0State & !I1State & I3State) |
                   (I0State & I1State & !I2State);
  bool O1State = (!I1State & !I2State & I3State) |
                   (I0State & I1State & !I2State) |
                   (!I0State & I2State) |
                   (I1State & !I3State);
  bool O2State = (!I0State & !I1State & !I2State) |
                   (!I1State & I3State) |
                   (I2State & I3State);
  bool O3State = (!I0State & !I1State & I3State) |
                   (I0State & I1State & I2State) |
                   (!I2State & I3State) |
                   (I0State & !I3State);

  // write the LED states
  PORTB |= (O0State << 2); // sets PORTB bit 2 to the value of O0State
  PORTB |= (O1State << 3); // sets PORTB bit 3 to the value of O1State
  PORTB |= (O2State << 4); // sets PORTB bit 4 to the value of O2State
  PORTB |= (O3State << 5); // sets PORTB bit 5 to the value of O3State;
  endTime = micros();
  Serial.print("Execution Time:");
  Serial.print(endTime-startTime);
  Serial.println(" microsec");   
}



