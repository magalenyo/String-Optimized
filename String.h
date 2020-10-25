#ifndef _STRING_
#define _STRING_


class String
{
	public:
		String();
		String(const char* toCopy);
		String(const String &toCopy);
		~String();

		int length() const;
		void clear();
		void print();

		String* operator+(const String &b);
		bool operator==(const String& b) const;
		bool operator==(const char* &b) const;


private:
	char* str;
	int strLength;

	int lengthOf(const char* b) const;
};
#endif // !_STRING_

