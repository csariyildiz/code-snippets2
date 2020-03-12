# Operator Overloading
## Programming Output

For each of the given program segments, read the code and write the output in the space provided
below each program. [Note: Do not execute these programs on a computer.]

For Programming Output Exercises 1–2, use the following class definition.

* Array.h
* Array.cpp

1 . What is output by the following code? Use the definition of class Array provided above

```cpp
 #include "Array.h"

 int main()
 {
 cout << "# of arrays instantiated = "
 << Array::getArrayCount() << '\n';

 Array integers1( 4 );
 Array integers2;
 
 cout << "# of arrays instantiated = "
 << Array::getArrayCount() << "\n";

 Array integers3( 8 ), *intptr = &integers2;

 cout << "# of arrays instantiated = "
 << Array::getArrayCount() << "\n\n";
 } // end main 
 ```
 
2 . What is the output of the following program? Use the Array class shown above.
 
 ```cpp
 #include "Array.h"

 int main()
 {
 Array integers1( 4 );
 Array integers2( 4 );

 if ( integers1 != integers2 )
 cout << "Hello";
 else
 cout << "Goodbye" << endl;
 } // end main 
 ```
