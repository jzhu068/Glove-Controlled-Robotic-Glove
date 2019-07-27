#include <Servo.h> 
 
Servo thumbMotor;  // create servo object to control the thumb
Servo indexMotor;  // create servo object to control the index finger
Servo middleMotor;  // create servo object to control the middle finger
Servo ringMotor;  // create servo object to control the ring finger
Servo pinkyMotor;  // create servo object to control the pinky finger

int thumbOpened = 0;
int indexOpened = 0;
int middleOpened = 0;
int ringOpened = 0;
int pinkyOpened = 0;

int thumbClosed;
int indexClosed;
int middleClosed;
int ringClosed; 
int pinkyClosed;

int thumb = 0;
int index = 0;
int middle = 0;
int ring = 0;
int pinky = 0;

void setup() {
  
  // attach the motors to their corresponding digital pins
  thumbMotor.attach(8);
  indexMotor.attach(9);
  middleMotor.attach(10);
  ringMotor.attach(11);
  pinkyMotor.attach(12);


  thumbClosed = analogRead(A0);
  indexClosed = analogRead(A1);
  middleClosed = analogRead(A2);
  ringClosed = analogRead(A3);
  pinkyClosed = analogRead(A4);
  
  
  Serial.begin(9600);
}

void loop() {
  
  // get the sensor values from each finger
  thumb = analogRead(A0);
  index = analogRead(A1);
  middle = analogRead(A2);
  ring = analogRead(A3);
  pinky = analogRead(A4);

  ///CALIBRATION of MAXIMUM VALUES

   if(thumb > thumbOpened)
    thumbOpened = thumb;
   if(index > indexOpened)
    indexOpened = index;
   if(middle > middleOpened)
    middleOpened = middle;
   if(ring > ringOpened)
    ringOpened = ring;
   if(pinky > pinkyOpened)
    pinkyOpened = pinky;

  ////CALIBRATION of MINIMUM VALUES

    if(thumb < thumbClosed)
      thumbClosed = thumb;
    if(index < indexClosed)
       indexClosed = index;
    if(middle < middleClosed)
      middleClosed = middle;
    if(ring < ringClosed)
        ringClosed = ring;
    if(pinky < pinkyClosed)
        pinkyClosed = pinky;

  // map the sensors values to degrees from 0 to 180 for the servo
  int thumbPos = map(thumb, thumbOpened, thumbClosed, 0, 180);
  int indexPos = map(index, indexOpened, indexClosed, 0, 180);
  int middlePos = map(middle, middleOpened, middleClosed, 0, 180);
  int ringPos = map(ring, ringOpened, ringClosed, 0, 180);
  int pinkyPos = map(pinky, pinkyOpened, pinkyClosed, 0, 180);
  
  // write the updated servo positions
  thumbMotor.write(thumbPos);
  indexMotor.write(indexPos);
  middleMotor.write(middlePos);
  ringMotor.write(ringPos);
  pinkyMotor.write(pinkyPos);

  Serial.println(thumbPos);
}
