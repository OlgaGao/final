#include <Servo.h>
#include <Keypad.h>
#include <Servo.h>

Servo myservo; // creating myservo object
int buttonPin = 12;//set button pin
int buttonState = 0; // set buttonState



Servo ServoMotor;
char* password = "111";  // change the password here, just pick any 3 numbers
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 12;
int GreenpinUnlock = 13;

void setup()
{
  ServoMotor.attach(11);
  LockedPosition(true);
  myservo.attach(13);// attach the 13 pin to servo
  pinMode(buttonPin, INPUT); // set button to input
}

void loop()
{
  buttonState = digitalRead(buttonPin); // read and save to the variable "buttonState" the actual state of button

    if (buttonState == HIGH)
      myservo.write(0);

    else
      myservo.write(65);
//    adelay(500);
  char key = keypad.getKey();
  if (key == '*' || key == '#')
  {
    position = 0;
    LockedPosition(true);
  }
  if (key == password[position])
  {
    position ++;
  }
  if (position == 3)
  {
    LockedPosition(false);
  }
  delay(100);
}
void LockedPosition(int locked)
{
  if (locked)
  {
    digitalWrite(RedpinLock, HIGH);
    digitalWrite(GreenpinUnlock, LOW);
    ServoMotor.write(11);
  }
  else
  {
    digitalWrite(RedpinLock, LOW);
    digitalWrite(GreenpinUnlock, HIGH);
    ServoMotor.write(90);
    
    
  }
}
