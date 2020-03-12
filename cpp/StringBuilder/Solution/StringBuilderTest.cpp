// StringBuilderTest.cpp

#include "StringBuilder.h"

void TEST_Append(StringBuilder& sb)
{
	cout << "+-------------+" << endl
		<< "| APPEND TEST |" << endl
		<< "+-------------+" << endl;
	sb.Append("TestName1").Append(" ").Append("TestSurname1")
		.Append(" ").Append(25).Append(" ")
		.Append(45.2).AppendNewLineCharacter();
	sb.Append("TestName2").Append(" ").Append("TestSurname2")
		.Append(" ").Append(24).Append(" ")
		.Append(47.45).AppendNewLineCharacter();
	cout << sb.GetData() << endl;
	sb.Clear();
}

void TEST_Clear(StringBuilder& sb)
{
	cout << "+-------------+" << endl
		<< "| CLEAR TEST |" << endl
		<< "+-------------+" << endl;
	sb.Clear();
	cout << sb.GetData() << endl;
}

void TEST_Contains(StringBuilder& sb)
{
	cout << "+----------------+" << endl
		<< "| CONTAINS TEST |" << endl
		<< "+----------------+" << endl;
	sb.Append("ESOGU");
	if (sb.Contains("OGU"))
	{
		cout << "StringBuilder contains the string 'OGU'" << endl;
	}
	else
	{
		cout << "StringBuilder does not contain the string 'OGU'" << endl;
	}
	if (sb.Contains("Bilgisayar"))
	{
		cout << "StringBuilder contains the string 'Bilgisayar'" << endl;
	}
	else
	{
		cout << "StringBuilder does not contain the string 'Bilgisayar'" <<
			endl;
	}
	sb.Clear();
}

void TEST_RemoveAt(StringBuilder& sb)
{
	cout << "+-----------------+" << endl
		<< "| REMOVE AT TEST |" << endl
		<< "+-----------------+" << endl;
	sb.Append("ESOGU Bilgisayar");
	sb.RemoveAt(1);
	cout << sb.GetData() << endl;
	sb.Clear();
}

void TEST_RemoveChar(StringBuilder& sb)
{
	cout << "+------------------------+" << endl
		<< "| REMOVE CHARACTER TEST |" << endl
		<< "+------------------------+" << endl;
	sb.Append("ESOGU Bilgisayar");
	sb.Remove('a');
	cout << sb.GetData() << endl;
	sb.Clear();
}

void TEST_RemoveRange(StringBuilder& sb)
{
	cout << "+--------------------+" << endl
		<< "| REMOVE RANGE TEST |" << endl
		<< "+--------------------+" << endl;
	sb.Append("ESOGU BilgisayarBilgisayar");
	sb.Remove(16, 10);
	cout << sb.GetData() << endl;
	sb.Clear();
}

void TEST_RemoveString(StringBuilder& sb)
{
	cout << "+---------------------+" << endl
		<< "| REMOVE STRING TEST  |" << endl
		<< "+---------------------+" << endl;
	sb.Append("ESOGU Bilgisayar, ESOGU Bilgisayar, ESOGU Bilgisayar");
	cout << "Before Remove : " << sb.GetData() << endl;
	sb.Remove("Bilgisayar");
	cout << "After Remove : " << sb.GetData() << endl;
	sb.Clear();
}

void TEST_Replace(StringBuilder& sb)
{
	cout << "+----------------------+" << endl
		<< "| REPLACE STRING TEST  |" << endl
		<< "+----------------------+" << endl;
	sb.Clear();
	sb.Append("ESOGU BILGI, ESOGU BILGI, ESOGU BILGI");
	cout << "Before Replace : " << sb.GetData() << endl;
	sb.Replace("BILGI", "Bilgisayar");
	cout << "After Replace : " << sb.GetData() << endl;
	sb.Clear();
}

void TEST_Split_And_Join() {
	cout << "+---------------------+" << endl
		<< "|     SPLIT TEST      |" << endl
		<< "+---------------------+" << endl;
	StringBuilder sb;
	sb.Append("This is a test                sentence and and it is               created to test the        execution of the implemented `SPLIT` function");
	cout << sb.GetData() << endl;
	vector<string> vec = sb.Split(" ");
	for (int i = 0; i<vec.size(); i++)
	{
		cout << i + 1 << ". world " << vec[i] << "\n" ;
	}

	cout << "+---------------------+" << endl
		<< "|     JOIN  TEST      |" << endl
		<< "+---------------------+" << endl;
	sb.Join(vec, ",");
	cout << "\n" << sb.GetData() << endl;;
}


int main()
{
	StringBuilder strBuilder;
	TEST_Append(strBuilder);
	TEST_Clear(strBuilder);
	TEST_Contains(strBuilder);
	TEST_RemoveAt(strBuilder);
	TEST_RemoveRange(strBuilder);
	TEST_RemoveString(strBuilder);
	TEST_Replace(strBuilder);
	TEST_Split_And_Join();
	
	return 0;
}
