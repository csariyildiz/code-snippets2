# Operator Overloading - Vector Implementation

1. [Objectives](#objectives)
2. [Description of the Problem](#description-of-the-problem)
3. [UML Diagram](#uml-diagram)
4. [Sample Output](#sample-output)
5. [Test Code Template](#test-code-template)
6. [Problem-Solving Tips](#problem-solving-tips)

The test program template represents a complete working C++ program test application.
Read the problem description and examine the sample output; then study the template code. 
Using the problem-solving tips as a guide, write your C++ code.
Compile and execute the program. 
Compare your output with the sample output provided.

# Objectives

* What operator overloading is and how it simplifies programming.
* To overload operators for user-defined classes.
* To overload unary and binary operators.
* To convert objects from one class to another class.
* Overloading the + operator to allow String objects to be concatenated.
* Writing function prototypes for overloaded operators.
* Using overloaded operators.

# Description of the Problem

Implement a Vector class that represents a mathematical vector. Look at the UML Diagram and
implement required functionalities. Required functions is explained in the UML Diagram section.
You are given a non-complete test code. Complete the test code according to the sample output.
Test your implementation.

# UML Diagram

<img src="https://acsariyildiz.github.io/images/cpp13.png"/>

# Sample Output


<img src="https://acsariyildiz.github.io/images/cpp15.png"/>

# Test Code Template


[VectorTest.cpp](https://raw.githubusercontent.com/acsariyildiz/Notes/master/cpp/Operator_Overloading/VectorTest.cpp)


Members:

* m_dimension: size of the vector
* m_data: a double array to keep the raw data

Functions:

* Vector(dimension = 3): Default parameter constructor
* Vector(data,dimension): Overloaded constructor with a double array and dimension parameter
* Vector(copyVector): Copy constructor
* ~Vector(): Destructor. You have to free the data array to handle the memory leak
* getDimension() : Returns the dimension of the vector
* Equal operator: Return true, if the vectors are equal
* Not equal operator: Returns true if the vectors are not equal
* Less than, greater than operators decides according to the magnitude of the vectors.
* Assign operator: Copies the vector given in the argument
* Subscription operator: Returns the vector element according to the given index

# Problem-Solving Tips

Use given UML Diagram and Test Code Template. 
