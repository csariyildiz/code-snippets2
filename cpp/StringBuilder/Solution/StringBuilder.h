#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class StringBuilder
{
public:

	StringBuilder();
	~StringBuilder();

	StringBuilder& Append(const string&);
	StringBuilder& Append(int);
	StringBuilder& Append(float);
	StringBuilder& Append(double);
	StringBuilder& Append(char);
	StringBuilder& AppendNewLineCharacter();
	StringBuilder& Clear();
	bool Contains(const string&);
	string GetData();
	StringBuilder& Remove(char removeChar);
	StringBuilder& Remove(int startIndex, int charCount);
	StringBuilder& Remove(const string& removeString);
	StringBuilder& RemoveAt(int index);
	StringBuilder& Replace(const string& replacedString, const string& newString);

	vector<string> Split(const string& character);
	void Join(const vector<string>& stringVector, const string& mergeCharacter);


private:
	stringstream stream;
};

