//  Pin Assignments
// Segments a, b, c, d, e, f, g mappedto arduino pins:
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};
int numSegments = 7;
int buzzerPin = 8;

// 2D Lookup Table: digitpatterns(1 = ON, 0 =OFF)
// Column order: a b c d e f g 
byte digits[10][7] = {
{1, 1, 1, 1, 1, 1, 0},    // 0
{0, 1, 1, 0, 0, 0, 0},    // 1
{1, 1, 0, 1, 1, 0, 1},    // 2
{1, 1, 1, 1, 0, 0, 1},    // 3
{0, 1, 1, 0, 0, 1, 1},    // 4
{1, 0, 1, 1, 0, 1, 1},    // 5
{1, 0, 1, 1, 1, 1, 1},    // 6
{1, 1, 1, 0, 0, 0, 0},    // 7
{1, 1, 1, 1, 1, 1, 1},    // 8
{1, 1, 1, 1, 0, 1, 1},    // 9
}; 

//--- showDigit() ---
//Sends the correctHIGH/LOW signals to display digit n (0-9).
void showDigit(int n){
  if (n < 0 || n > 9) return;   // safety guard
  for (int i = 0; i < numSegments; i++){
    digitalWrite(segmentPins[i], digits[n][i]);
    // digits [n][i] is0 or 1; digitWrite treats 0=LOW, 1=HIGH
  }
}



void setup() {
  Serial.begin(9600);   
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output

// Set every segment pin as output and start LOW (display blank)
  for (int i = 0; i < numSegments; i++){
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  Serial.println("===Beeping Countdown Starting===");

  // --- Countdown; 9 down to 1---
  int count = 9;
  while (count >= 1){
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);               // show current digit
    tone(buzzerPin, 1000, 200);    // short beep: 1000 Hz, 200 ms
    delay(1000);                   // hold digit for 1 second 

    count = count - 1;
  }
  // --- Show 0 and play competion tone---
showDigit(0);
tone(buzzerPin, 1500, 1000);      // longer tone; 1500 Hz, 1 second

  Serial.println("===Countdown Complete===");
}

void loop() {
  // Empty because the countdown runs once in setup() and stops.

}
