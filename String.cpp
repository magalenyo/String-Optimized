#include "String.h"
#include <iostream>

String::String()
{
	strLength = 0;
	str = new char[0];
 	str[0] = '\0';		// no sé por qué esto funciona?!?!?!?
}

String::String(const char* toCopy)
{
	//delete str;
	if (toCopy != nullptr) {
		strLength = lengthOf(toCopy);			// looks for new string length
		str = new char[strLength + 1];			// resizes current String
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

String::String(const String& toCopy)
{
	if (toCopy.str != nullptr) {
		strLength = toCopy.strLength;
		str = new char[strLength];				// resizes current String, not necessary the +1 for the \0?!?!
		str[0] = '\0';							// init
		int i = 0;
		char current = toCopy.str[i];
		while (toCopy.str[i] != '\0') {			// while not end line
			str[i] = current;					// copy current character
			i++;
			current = toCopy.str[i];
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

String* String::operator+(const String& b)
{
	String* stringResult = new String();
	stringResult->strLength = strLength + b.strLength;
	stringResult->str = new char[stringResult->strLength];
	int i = 0;
	if (str != nullptr) {
		for (i; str[i] != '\0'; ++i) {
			stringResult->str[i] = str[i];
		}
	}

	if (b.str != nullptr) {
		for (int j = 0; b.str[j] != '\0'; ++i, ++j) {
			stringResult->str[i] = b.str[j];
		}
	}
	stringResult->str[stringResult->strLength] = '\0';
	return stringResult;
}

bool String::operator==(const String& b) const
{
	if (str == nullptr || b.str == nullptr) {
		return false;
	}
	else {
		int i = 0;
		while (str[i] != '\0' || b.str[i] != '\0') {
			if (str[i] != b.str[i]) {
				return false;
			}
			i++;
		}
		// todos han sido checkeados
		if (str[i] == b.str[i]) {		// si los dos tienen el '\0' end
			return true;
		}
		else return false;
	}
	
}

bool String::operator==(const char* &b) const
{
	if (str == nullptr || b == nullptr) {
		return false;
	}
	else {
		int i = 0;
		while (str[i] != '\0' || b[i] != '\0') {
			if (str[i] != b[i]) {
				return false;
			}
			i++;
		}
		// todos han sido checkeados
		if (str[i] == b[i]) {		// si los dos tienen el '\0' end
			return true;
		}
		else return false;
	}
}

int String::lengthOf(const char* b) const
{
	int n = 0;
	if (b != nullptr) {
		for (n = 0; b[n] != '\0'; ++n) {}
	}
	return n;
}
