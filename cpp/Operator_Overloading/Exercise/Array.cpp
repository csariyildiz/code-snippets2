 // Array.cpp
 // Member function definitions for class Array
 #include <iostream>
 #include <iomanip>
 #include <cstdlib>
 #include <new>
 using namespace std;

 #include "Array.h"

 // initialize static data member at file scope
 int Array::arrayCount = 0; // no objects yet

 // default constructor for class Array (default size 10)
 Array::Array( int arraySize )
 {
 size = ( arraySize > 0 ? arraySize : 10 );
 ptr = new int[ size ]; // create space for array
 ++arrayCount; // count one more object

 for ( int i = 0; i < size; i++ )
 ptr[ i ] = 0; // initialize array

 } // end class Array constructor

 // copy constructor for class Array
 // must receive reference to prevent infinite recursion
 Array::Array( const Array &arrayToCopy ) : size( arrayToCopy.size )
 {
 ptr = new int[ size ]; // create space for array
 ++arrayCount; // count one more object

 for ( int i = 0; i < size; i++ )
 ptr[ i ] = arrayToCopy.ptr[ i ]; // copy arayToCopy into object

 } // end copy constructor

 // destructor for class Array
 Array::~Array()
 {
 delete [] ptr; // reclaim space for array
 --arrayCount; // one fewer object

 } // end class Array destructor

 // get size of array
 int Array::getSize() const
 {
 return size;

 } // end function getSize

 // overloaded assignment operator
 // const return avoids: ( a1 = a2 ) = a3
 const Array &Array::operator=( const Array &right ) 
 {
 if ( &right != this ) { // check for self-assignment

 // for arrays of different sizes, deallocate original
 // left side array, then allocate new left side array
 if ( size != right.size ) {
 delete [] ptr; // reclaim space
 size = right.size; // resize this object
 ptr = new int[ size ]; // create space for array copy

 } // end if

 for ( int i = 0; i < size; i++ )
 ptr[ i ] = right.ptr[ i ]; // copy array into object

 } // end if

 return *this; // enables x = y = z;

 } // end function operator=

 // determine if two arrays are equal and
 // return true, otherwise return false
 bool Array::operator==( const Array &right ) const
 {
 if ( size != right.size )
 return false; // arrays of different sizes

 for ( int i = 0; i < size; i++ )

 if ( ptr[ i ] != right.ptr[ i ] )
 return false; // arrays are not equal

 return true; // arrays are equal

 } // end function operator==

 // overloaded subscript operator for non-const Arrays
 // reference return creates an lvalue
 int &Array::operator[]( int subscript )
 {
 // check for subscript out of range error
 if ( subscript < 0 || subscript >= size ) {
 cout << "\nError: Subscript " << subscript
 << " out of range" << endl;

 exit( 1 ); // terminate program; subscript out of range

 } // end if

 return ptr[ subscript ]; // reference return

 } // end function operator[]

 // overloaded subscript operator for const Arrays
 // const reference return creates an rvalue
 const int &Array::operator[]( int subscript ) const
 {
 // check for subscript out of range error
 if ( subscript < 0 || subscript >= size ) {
 cout << "\nError: Subscript " << subscript
 << " out of range" << endl;

 exit( 1 ); // terminate program; subscript out of range

 } // end if

 return ptr[ subscript ]; // const reference return

 } // end function operator[]

 // return number of Array objects instantiated
 // static functions cannot be const
 int Array::getArrayCount()
 {
 return arrayCount;

 } // end function getArrayCount

 // overloaded input operator for class Array;
 // inputs values for entire array
 istream &operator>>( istream &input, Array &a )
 {
 for ( int i = 0; i < a.size; i++ )
 input >> a.ptr[ i ];

 return input; // enables cin >> x >> y;

 } // end function operator>>

 // overloaded output operator for class Array
 ostream &operator<<( ostream &output, const Array &a )
 {
 int i;

 for ( i = 0; i < a.size; i++ ) {
 output << setw( 12 ) << a.ptr[ i ];

 if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
 output << endl;

 } // end for

 if ( i % 4 != 0 )
 output << endl;

 return output;

 } // end function operator<< 
