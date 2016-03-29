#include <Keyboard.h>
#include <Servo.h>

Servo money; 
int buttonPin = 2;     
int buttonState = 0;

int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter


char space = 32;

void setup() {

  Serial.begin(9600);

  money.attach(3); // pin servo
  pinMode(buttonPin, INPUT);
  money.write(0);

  Keyboard.begin();

}

int mynt() {
  money.write(150);
  delay(1000);
  money.write(0);
}


int btn(){
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == LOW)) {
    // increment the button counter
    Keyboard.press(space);
    delay(50);
    Keyboard.release(space);
    delay(30000);
    counter++;
    // type out a message
    money.write(150);
    delay(500);
    money.write(0);
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}


void loop() {
  btn();

}



