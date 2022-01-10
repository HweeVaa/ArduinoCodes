 /*Vibration sensor connected to Arduino pins as follows:
 Arduino            Vibration Sensor
   D3                    DOut
   GND                   GND
   +5V                   VCC      
*/
#include<SoftwareSerial.h>

int blueTx=0;
int blueRx=1;
int Shock = 3;
int Shock_Val = 0;
int Vibe_count = 0; //the pulses will be counted on here
SoftwareSerial BTSerial(blueTx,blueRx);

void setup() {
  Serial.begin(9600); //init serial 9600
  BTSerial.begin(9600);
  pinMode(Shock,INPUT);
}




void loop() {
  if(BTSerial.available()){
    Serial.write(BTSerial.read());
  }
  if(Serial.available()){
    BTSerial.write(Serial.read());

    
    if(digitalRead(Shock)==HIGH){
      //count when the sensor value is HIGH
      Vibe_count = Vibe_count +1;
      delay(50);

      //if the sensor detacted pulses 3 times or more per 50ms, print "SHOCK!!"
      if(Vibe_count >= 3){
        Serial.println("SHOCK!!");
        BTSerial.println("SHOCK!!");
      }
    //initialize counter
    else{
      Vibe_count = 0;
      }
    }
  }
}
