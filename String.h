#include <iostream>
#ifndef STRING
#define STRING
class String
{
public:
	String(const char* str = "");
	String(size_t size, char c);
	~String();
	size_t Length();
	void Print(bool new_line = 0);
	void Append(String& other);
	void Append(const char* other);
	char Get(size_t index);
	void Reverse();
	void Replace(const char* from, const char* to, unsigned quantity = 0);
	unsigned Count(const char* item);
private:
	size_t size;
	char* str;
};
#endif 

