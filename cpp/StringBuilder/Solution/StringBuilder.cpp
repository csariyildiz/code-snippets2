#include "StringBuilder.h"

StringBuilder::StringBuilder()
{
}

StringBuilder::~StringBuilder()
{
}

StringBuilder& StringBuilder::Append(const string & data)
{
	stream << data;
	return *this;
}

StringBuilder & StringBuilder::Append(int data)
{
	stream << to_string(data);
	return *this;
}

StringBuilder & StringBuilder::Append(float data)
{
	stream << data;
	return *this;
}

StringBuilder & StringBuilder::Append(double data)
{
	stream << data;
	return *this;
}

StringBuilder & StringBuilder::Append(char data)
{
	stream << to_string(data);
	return *this;
}

StringBuilder & StringBuilder::AppendNewLineCharacter()
{
	stream << "\n";
	return *this;
}

StringBuilder & StringBuilder::Clear()
{
	stream.str("");
	return *this;
}

bool StringBuilder::Contains(const string & data)
{
	size_t found = stream.str().find(data);
	if (found != std::string::npos) { return true; }
	else return false;

}

string StringBuilder::GetData()
{
	return stream.str();
}

StringBuilder & StringBuilder::Remove(char removeChar)
{
	string str;
	// "size_t" for “signed/unsigned mismatch” warning (C4018) 
	for (size_t i = 0; i < stream.str().size(); i++)
	{
		if (stream.str()[i] != removeChar)
			str += stream.str()[i];
	}
	stream.str("");
	stream << str;
	return *this;
}

StringBuilder & StringBuilder::Remove(int startIndex, int charCount)
{
	string str = stream.str();
	str.erase(startIndex, startIndex + charCount);
	stream.str("");
	stream << str;
	return *this;
}

//Removing a substring from stream
//http://stackoverflow.com/a/32435062
StringBuilder & StringBuilder::Remove(const string & removeString)
{
	string str = stream.str();
	string::size_type n = removeString.length();
	for (string::size_type i = str.find(removeString); i != string::npos; i = str.find(removeString))
		str.erase(i, n);

	stream.str("");
	stream << str;
	return *this;
}

StringBuilder & StringBuilder::RemoveAt(int index)
{
	string str;
	// "size_t" for “signed/unsigned mismatch” warning (C4018) 
	for (size_t i = 0; i < stream.str().size(); i++)
	{
		if (i != index - 1)
			str += stream.str()[i];
	}

	stream.str("");
	stream << str;
	return *this;
}

StringBuilder & StringBuilder::Replace(const string & replacedString, const string & newString)
{
	string str = stream.str();
	size_t start_pos = str.find(replacedString);
	if (start_pos != std::string::npos)
		str.replace(start_pos, replacedString.length(), newString);

	stream.str("");
	stream << str;
	return *this;
}

vector<string> StringBuilder::Split(const string & character)
{
	vector<string> ret_value;
	string word;
	string str = stream.str();

	while (!str.empty()) {
		// Get the matching index
		size_t idx = str.find(character);
		// If index is not empty
		if (idx != std::string::npos) {
			// Get the word
			word = str.substr(0, idx);
			// Delete the word + character
			str.erase(0, idx + 1);
			// If its not empty
			if (word != "")
			{
				ret_value.push_back(word);
			}
		}
		else {
			ret_value.push_back(str);
			str.erase();

		}

	}

	return ret_value;
}

void StringBuilder::Join(const vector<string>& stringVector, const string & mergeCharacter)
{
	string str = "";
	for (size_t i = 0; i < stringVector.size(); i++) {
		str += stringVector[i] + mergeCharacter;

	}
	str = str.substr(0, str.size() - 1);

	stream.str("");
	stream << str;
}
