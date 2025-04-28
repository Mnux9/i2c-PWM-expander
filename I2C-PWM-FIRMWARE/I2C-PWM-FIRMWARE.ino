#include <Wire.h>

//ADRESS PINS
#define A1 PC3
#define A2 PC4
#define A3 PC6

//CHANNEL PINS
#define CH1 PD4
#define CH2 PC7  
#define CH3 PA1
#define CH4 PA2
#define CH5 PC0


int type = 0;
int currentChannel = 0;

void setup()
{
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  analogWriteFrequency(16000); 

  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  pinMode(CH3, OUTPUT);
  pinMode(CH4, OUTPUT);
  pinMode(CH5, OUTPUT);

  //000
  if (digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 0) {
    Wire.begin(1);
  }
  // 001
  else if (digitalRead(A1) == 0 && digitalRead(A2) == 0 && digitalRead(A3) == 1) {
    Wire.begin(2);
  }
  // 010
  else if (digitalRead(A1) == 0 && digitalRead(A2) == 1 && digitalRead(A3) == 0) {
    Wire.begin(3);
  }
  // 011
  else if (digitalRead(A1) == 0 && digitalRead(A2) == 1 && digitalRead(A3) == 1) {
    Wire.begin(4);
  }
  // 100
  else if (digitalRead(A1) == 1 && digitalRead(A2) == 0 && digitalRead(A3) == 0) {
    Wire.begin(5);
  }
  // 101
  else if (digitalRead(A1) == 1 && digitalRead(A2) == 0 && digitalRead(A3) == 1) {
    Wire.begin(6);
  }
  // 110
  else if (digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 0) {
    Wire.begin(7);
  }
  // 111
  else if (digitalRead(A1) == 1 && digitalRead(A2) == 1 && digitalRead(A3) == 1) {
    Wire.begin(8);
  }
  else{
    Wire.begin(9);
  }

  //Serial.println(String(digitalRead(A1)) + String(digitalRead(A2) + String(digitalRead(A3))));

  Wire.onReceive(receiveEvent); //function to run on I2C receiveEvent
}


void loop(){  
}


// function that runs whenever data is received over I2C
void receiveEvent(int howMany){
  //Serial.println("--new rx:--");
  while(0 < Wire.available()) // loop through all but the last
  {
    int c = Wire.read(); // receive byte as a character
    if(type == 0){
      //Serial.print("CH: ");
      //Serial.println(c);  
      currentChannel = c;
      type++;
    }
    else if(type == 1){
      //Serial.print("PWM: ");
      //Serial.println(c);


  
      analogWrite(channelLookup(currentChannel), map(c, 0, 255, 0, 2048));
      type = 0;

    }
    
  }
  //int x = Wire.read();    // receive byte as an integer
  //Serial.println(x);         // print the integer
}

int channelLookup(int channel){
  
  if (channel == 1){
    return CH1;
  }
  if (channel == 2){
    return CH2;
  }
  if (channel == 3){
    return CH3;
  }
  if (channel == 4){
    return CH4;
  }
  if (channel == 5){
    return CH5;
  }

  //Serial.print(channel);
}
