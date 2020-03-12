 // Array.h
 // Simple class Array (for integers)
 #ifndef ARRAY_H
 #define ARRAY_H

 #include <iostream>
 using namespace std;

 // class Array definition
 class Array
 {
 friend ostream &operator<<( ostream &, const Array & );
 friend istream &operator>>( istream &, Array & );

 public:
 Array( int = 10 ); // default constructor
 Array( const Array & ); // copy constructor
 ~Array(); // destructor
 int getSize() const; // return size
 const Array &operator=( const Array & ); // assignment operator
 bool operator==( const Array & ) const; // equality operator

 // determine if two arrays are not equal and
 // return true, otherwise return false (uses operator==)
 bool operator!=( const Array &right ) const
 {
 return ! ( *this == right );

 } // end function operator!=

 int &operator[]( int ); // subscript operator
 const int &operator[]( int ) const; // subscript operator
 static int getArrayCount(); // return number of
 // arrays instantiated
 private:
 int size; // size of array
 int *ptr; // pointer to first element of array 
 static int arrayCount; // number of Arrays instantiated

 }; // end class Array

 #endif // ARRAY_H 
