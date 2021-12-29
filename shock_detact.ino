/*Vibration sensor connected to Arduino pins as follows:
 Arduino            Vibration Sensor
   D3                    DOut
   GND                   GND
   +5V                   VCC      
*/


int Shock = 3;
int Shock_Val = 0;
int Vibe_count = 0; //the pulses will be counted on here


void setup() {
  Serial.begin(9600); //init serial 9600
  pinMode(Shock,INPUT);
}

void loop() {
  if(digitalRead(Shock) == HIGH){

    //count when the sensor value is HIGH
    Vibe_count = Vibe_count +1;
    delay(50);


    //if the sensor detacted pulses 3 times or more per 50ms, count +1
    if(Vibe_count >= 3){
      Serial.println("SHOCK!!");
      Vibe_count = 0;
    }
  }
  //initialize counter
  else{
    Vibe_count = 0;
  }
}
