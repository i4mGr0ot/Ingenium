#include <Servo.h>
#include <Stepper.h>

#define number_of_samples = 12
#define STEPS = 200 //Steps per revolution

Servo myservo;  // create servo object to control a servo
Stepper stepper(STEPS, 8, 9, 10, 11);



void sample(int n)
{
// Goes to samples number n

int angle = 180/number_of_samples * (n-1);
myservo.write(angle);
}

void rotations(int n)
{
// n can be negative for reversing the direction
myStepper.step(stepsPerRevolution * n);
} 

void setup() {
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
  myStepper.setSpeed(60);
  // set the speed of the motor to 60 RPMs
}
