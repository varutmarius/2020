
int r1=2,r2=3; // for going up
int r3=4,r4=5; // for going down
// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r4, OUTPUT);
}



void loop() {
  blk();
  goup();
  godw();
}

void blk() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
   delay(100);              // wait for a second
}

void goup() {
  digitalWrite(r1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r3, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(r4, HIGH);    // turn the LED off by making the voltage LOW
  delay(5000);              // wait for a second
  digitalWrite(r1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(r4, LOW);    // turn the LED off by making the voltage LOW
  
  delay(100);              // wait for a second
}

void godw() {
  digitalWrite(r1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(r4, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);              // wait for a second
  digitalWrite(r1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(r3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(r4, LOW);    // turn the LED off by making the voltage LOW
  
  delay(100);              // wait for a second
}
