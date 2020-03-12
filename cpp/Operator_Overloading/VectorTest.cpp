/**
* VectorTest.cpp
* Operator Overloading
*/

#include "Vector.h"

void TEST_Input(Vector& vector)
{
cout << "+------------+" << endl
<< "| INPUT TEST |" << endl
<< "+------------+" << endl;
cin >> vector;
}

void TEST_Output(Vector& vector)
{
cout << "+-------------+" << endl
<< "| OUTPUT TEST |" << endl
<< "+-------------+" << endl;
cout << vector << endl;
}

void TEST_CopyConstructor(Vector& vector)
{
cout <<"+-----------------------+" << endl
<< "| COPY CONSTRUCTOR TEST |" << endl
<< "+-----------------------+" << endl;
Vector copy_vector(vector);
cout << "Original Vector : " <<vector<< endl<< "Copy Vector : "<<copy_vector
<< endl;
}

void TEST_Assignment(Vector& vector)
{
cout<< "+-----------------+" << endl
<< "| ASSIGNMENT TEST |" << endl
<< "+-----------------+" << endl;
Vector copy_vector;
copy_vector = vector;
cout << "Original Vector : " << vector << endl << "Assignment Copy Vector : "
<< copy_vector << endl;
}

void TEST_Equal(Vector& vector1, Vector& vector2)
{
cout <<"+------------+" << endl
<< "| EQUAL TEST |" << endl
<< "+------------+" << endl;
if (vector1 == vector2)
{
cout << vector1 << " is equal to " << vector2 << endl;
}
else
{
cout << vector1 << " is not equal to " << vector2 << endl;
}
}

void TEST_Not_Equal(Vector& vector1, Vector& vector2)
{
// Implement the function
}
