# Inheritance

## Objectives

* To create classes by inheriting from existing classes.
* The notions of base classes and derived classes and the relationships between them.

## Correct The Code

* For each of the given program segments, determine if there is an error in the code. 
* If there is an error, specify whether it is a logic or compilation error, write the corrected code.
* If the code does not contain an error, write “no error.”
* For code segments, assume the code appears in main and that using directives are provided.
* Note: It is possible that a program segment may contain multiple errors.

1 . Class X inherits from class Y.

```cpp
 #include <iostream>
using namespace std;

// class Y definition
class Y
{
    public:
    Y(); // default constructor
    ~Y(); // destructor
    private:
    int data;
}; // end class Y

// class X definition
class X ; public Y
{
    public:
    // function print
    void print() const
    {
        cout << data;
    } // end function print
}; // end class X
 ```

2 . The following code should construct a Derived object.

```cpp
 #include <iostream>
 using namespace std;

 // class Base definition 
 class Base
 {
 private:
 // constructor
 Base( int b )
 {
 cout << b;
 } // end class Base constructor
 }; // end class Base

 // class Derived definition
 class Derived : public Base
 {
 // constructor calls base-class constructor
 Derived( int a )
 : Base( a )
 {
 // empty
 } // end class Derived constructor
 }; // end class Derived

 int main()
 {
 Derived d( 5 );
 } // end main
```

3 . The following code creates an object of type B. Class B inherits from class A.

```cpp
 #include <iostream>
 using namespace std;

 // class A definition
 class A
 {
 public:
 // constructor
 A( int a )
 {
 value = a;
 } // end class A constructor

 // return value
 int getValue() const
 {
 return value;
 } // end function getValue
 private:
 int value;
 }; // end class A

 // class B definition
 class B
 {
 public:
 // constructor
 B( int b )
 : A( b )
 {
 // empty
 } // end class B constructor
}; // end class B

 int main()
 {
 B object( 50 );
 cout << object.getValue();
 } // end main

 ```
 
 4 . The following code creates an object of type Y. Class Y inherits from class X.
 
 ```cpp
  #include <iostream>
 using namespace std;

 // class X definition
 class X
 {
 public:
 // constructor
 X()
 {
 cout << "X constructed!";
 } // end class X constructor
 }; // end class X

 // class Y definition
 class Y
 {
 public:
 // redefine inherited constructor
 X()
 {
 cout << "Y created, not X!";
 } // end class Y constructor
 }; // end class Y

 int main()
 {
 Y yObject();
 } // end main
 ```
