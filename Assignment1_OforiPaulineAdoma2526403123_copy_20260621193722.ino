
int startValue = 5;
int ledPin = 13;        // pin is connected to LED 13


void flashLED(int times){       // Blink LED given number of times
    int flashCount =  times;

    while( flashCount > 0){       // keep looping while countering is greater than zero
    digitalWrite(ledPin, HIGH);   // turns LED ON
    delay(200);                  // LED is ON for 1 second
    digitalWrite(ledPin, LOW);    // turns LED OFF
    delay(200);                  // LED is OFF for 1 second

    flashCount= flashCount-1;        // decreases counter each time              

    }
  delay(400);     // short pause after all flashCount
  
}     




void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  
  Serial.println("===Smart Countdown Starting===");

  int count = startValue;
  
  while( count > 0){                   // keep looping while countering than zero
     Serial.print("Count is: ");
     Serial.println(count);
     count = count-1;

      
    flashLED(count);

    delay(1000);
     

    


  }
    Serial.println("===Countdown Complete===");
}

void loop() {
  // Empty-all code is in setup

}
