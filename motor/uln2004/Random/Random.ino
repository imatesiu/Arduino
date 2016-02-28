// Random.pde
// -*- mode: C++ -*-
//
// Make a single stepper perform random changes in speed, position and acceleration
//
// Copyright (C) 2009 Mike McCauley
// $Id: HRFMessage.h,v 1.1 2009/08/15 05:32:58 mikem Exp mikem $

#include <AccelStepper.h>

// Motor definitions
#define motorPin1  8     // IN1 on the ULN2003 driver 1
#define motorPin2  9     // IN2 on the ULN2003 driver 1
#define motorPin3  10     // IN3 on the ULN2003 driver 1
#define motorPin4  11     // IN4 on the ULN2003 driver 1

//tips (from Mark Benson)
//If anyone else is having problems with a BYJ48 stepper not doing anything, 
//change the HALFSTEP value to 4 & REVOLUTION_STEP to 2048
#define HALFSTEP 4
#define REVOLUTION_STEP 2048

// Define a stepper and the pins it will use
AccelStepper stepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4); // Defaults to 4 pins on 2, 3, 4, 5

void setup()
{  
}

void loop()
{
    if (stepper.distanceToGo() == 0)
    {
	// Random change to speed, position and acceleration
	// Make sure we dont get 0 speed or accelerations
	delay(1000);
	stepper.moveTo(rand() % 200);
	stepper.setMaxSpeed((rand() % 200) + 1);
	stepper.setAcceleration((rand() % 200) + 1);
    }
    stepper.run();
}
