#include <Servo.h>
#include <Keypad.h>
#include <Servo.h>

Servo myservo; 
int buttonPin = 12;
int buttonState = 0; 



Servo ServoMotor;
char* password = "111"; 
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


void setup()
{
  ServoMotor.attach(11);
  LockedPosition(true);
  myservo.attach(13);
  pinMode(buttonPin, INPUT); 
}

void loop()
{
  buttonState = digitalRead(buttonPin); 

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
  delay(50);
}
void LockedPosition(int locked)
{
  if (locked)
  {

    ServoMotor.write(11);
  }
  else
  {

    ServoMotor.write(90);
    
    
  }
}
