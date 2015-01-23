/*
  
  Simple Cat Toy for an ATtiny45 or ATtiny85
  
  Built by John Keefe
  January 2015
  
  Details at:
  
  Derived from the "Blink" example code, which is in the public domain.
 */
 
// No Pin 13 on an ATtiny, so using Pin 0.
// give it a name:
int led_one = 0;
int led_two = 1;
int buzzer = 4;
int rand_select;
int rand_repeat;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_one, OUTPUT);
  pinMode(led_two, OUTPUT);
  pinMode(buzzer, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {

  rand_select = random(3); // picks 0-2; random number max is not inclusive
  rand_repeat = random(1, 5); // picks 1-4
  
  // depending on the first random number, pick a thing to do
  // then pass the second random number to repeat that thing
  switch (rand_select) {
    case 0: 
      flash(rand_repeat);
      break;
    case 1:
      buzz(rand_repeat);
      break;
    case 2:
      silent(rand_repeat);
      break;
  
  }

  
}

void flash(int repeat) {

  // always do one little buzz when the lights start to flash
  // to get the cat's attention
  buzz(1);
  
  // flash the lights three times the random repeat number
  for (int i = 0; i < repeat * 3; i++) { 
    
    digitalWrite(led_one, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(150);               // wait for 150 milliseconds
    digitalWrite(led_one, LOW);    // turn the LED off by making the voltage LOW
    
    digitalWrite(led_two, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(150);               // wait for 150 milliseconds
    digitalWrite(led_two, LOW);    // turn the LED off by making the voltage LOW
  
  }

}

void buzz(int repeat) {
  
  // buzz the number of times that is passed to the function
  for (int i = 0; i < repeat; i++) { 
    digitalWrite(buzzer, HIGH);   // turn the buzzer on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(buzzer, LOW);    // turn the buzzer off by making the voltage LOW
    delay(50);
  }
  
}

void silent(int repeat) {

   // sit silent for 2 seconds times the repeat number
   delay(repeat * 2000);

}


