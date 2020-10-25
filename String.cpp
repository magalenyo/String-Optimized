#include "String.h"
#include <iostream>

String::String()
{
	strLength = 0;
	str = new char[0];
 	str[0] = '\0';		// no sé por qué esto funciona
}

String::String(const char* toCopy)
{
	//delete str;
	if (toCopy != nullptr) {
		strLength = lengthOf(toCopy);		// looks for new string length
		str = new char[strLength + 1];				// resizes current String
		str[0] = '\0';							// init
		int i = 0;
		char current = toCopy[i];
		while (toCopy[i] != '\0') {				// while not end line
			str[i] = current;					// copy current character
			i++;
			current = toCopy[i];
		}
		str[i] = current;						// will copy \0
	}
	else {
		strLength = 0;
		str = nullptr;
	}

}

String::~String()
{
	if (str != nullptr) {
		delete[]str;
		strLength = 0;
	}
}

int String::length() const
{
	return strLength;
}

void String::clear()
{
	if (str != nullptr) {
		delete[]str;
		strLength = 0;
	}
}

void String::print()
{
	std::cout << str << std::endl;
}

bool String::operator==(const String& b) const
{
	/*if (strLength != lengthOf(b.str)) {

	}*/
	return false;
}

bool String::operator==(const char*& b) const
{
	return false;
}

int String::lengthOf(const char*& b) const
{
	int n = 0;
	if (b != nullptr) {
		for (n = 0; b[n] != '\0'; ++n) {

		}
	}
	return n;
}
