# StringBuilder

1. [Objectives](#objectives)
2. [Description of the Problem](#description-of-the-problem)
3. [UML Diagram](#uml-diagram)
4. [Sample Output](#sample-output)
5. [Program Template](#program-template)
6. [Problem-Solving Tips](#problem-solving-tips)

The program given represent a test application of your class. 
Read the problem description and examine the sample output. 
Using the problem-solving tips as a guide, write the StringBuilder class.
Compile and execute the program. 
Compare your output with the sample output provided.

# Objectives

* Creating new helper class by writing class definitions.
* Defining member functions of programmer-defined classes.
* Learn member function overloading of a class.
* Learn “stringstream” class and its member functions.
* Instantiating objects from programmer-defined classes.
* Calling member functions of programmer-defined classes.

# Description of the Problem

Create a class called StringBuilder to perform string appending, removing operations for some primitive data types, 
such as int,float,double,char etc. 
StringBuilder class has member functions and the function prototypes is given to you via UML diagram. 
The class also has a member variable of type “stringstream” called stream that is encapsulated in private scope of the class. 
You requirements is to write a header and source file for the class. 
Implement the member functions and test your implementation by using the given main function. 
You are not allowed to change the test code.

# UML Diagram

<img src="https://acsariyildiz.github.io/images/cpp11.png"/>


* Append(…) : All append functions is used to perform string appending operation.
* Clear() : Remove the content of the stream object
* Contains(…) : Check the stream object contents and returns true if given string is located in
the stream, otherwise false.
* GetData() : Returns the content of the stream object
* Remove(removeChar) : Removes all characters which is equal to the given character in the
stream objects.
* Remove(startIndex,charCount) : Removes characters starting from the given index until
given charCount removed.
* RemoveAt(index) : Removes the character at the given index.
* Remove(removeString): Removes all occurrences of the given string from the stream.
* Replace(replacedString, newString): Replaces all occurrences of the given string by the
newstring.


# Sample Output

<img src="https://acsariyildiz.github.io/images/cpp12.png"/>


# Program Template

[StringBuilderTest.cpp](https://raw.githubusercontent.com/acsariyildiz/Notes/master/cpp/StringBuilder/StringBuilderTest.cpp)


# Problem-Solving Tips

Use UML Diagram, and test code.


