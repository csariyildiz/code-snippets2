# Vehicle

1. [Objectives](#objectives)
2. [Description of the Problem](#description-of-the-problem)
3. [UML Diagram](#uml-diagram)
4. [Sample Output](#sample-output)
5. [Program Template](#program-template)
6. [Problem-Solving Tips](#problem-solving-tips)

The program template gives some tips about the program structure. 

Read the problem description and examine the sample output; then study the template code.

Using the problem-solving tips as a guide, write your C++ code.

Compile and execute the program. Compare your output with the sample output provided.

## Objectives

You will practice:

* Declaring data members.
* Providing set and get functions to manipulate a data member’s value.
* Declaring member functions with parameters.



## Description of the Problem

Write a Vehicle class that simulate a basic vehicle(automobile). 

Your class header file is given to you. Your job is to implement these class member functions and obtain required outputs. 

You can compare your output by the given sample output. Some of the test procedures is given to you (main.cpp). 

You are also required to complete missing test functions.

## UML Diagram


<img class="img-responsive" src="https://acsariyildiz.github.io/images/cpp4.png">


## Sample Output


<img class="img-responsive" src="https://acsariyildiz.github.io/images/cpp8.png">

## Program Template

[Vehicle.h](https://raw.githubusercontent.com/acsariyildiz/Notes/master/cpp/Vehicle/Vehicle.h)

[Vehicle.cpp](https://raw.githubusercontent.com/acsariyildiz/Notes/master/cpp/Vehicle/Vehicle.cpp)

[VehicleTestMain.cpp](https://raw.githubusercontent.com/acsariyildiz/Notes/master/cpp/Vehicle/VehicleTestMain.cpp)

## Problem-Solving Tips

1. Acceleration of the car depends on the engine status, if engine is not started, accelerate function returns false. Acceleration limit also depends on the maxSpeed of the vehicle. If any attempt to increase the speed of the vehicle to a higher value than maxSpeed, just set the currentSpeed to maxSpeed value.

2. GetIn and GetOut member functions depend on the current speed and passengerCount. If current speed is non-zero value. GetIn and GetOut functions returns false. If currentPassenger number is not enough to GetIn or GetOut, these functions print an error message and returns false. Otherwise, do the operation.

3. StartEngine and StopEngine functions print a message on the screen and set the bool member variable depending.

4. To implement the test functions, you can check the given sample test function.

5. Use ASCII table to find the corresponding random value ranges.
