#include <iostream>
#include <string>
using namespace std;

class String;
String operator+(const String& left, const String& right);
class String
{
	unsigned int size;
	char* str;

public:
	unsigned int get_size() const
	{
		return size;
	}
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	explicit String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Default_Constructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "1_Arg_Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "Copy_Constructor:\t" << this << endl;
	}
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "Copy_Assignment: \t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor: \t\t" << this << endl;
	}

	const char& operator[] (unsigned int i)const
	{
		return str[i];
	}
	char& operator[] (unsigned int i)
	{
		return str[i];
	}
	void print() const
	{
		cout << "Size: \t" << size << endl;
		cout << "Str: \t" << str << endl;
	}

};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

int main()
{
	setlocale(LC_ALL, "Russian");


	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	cout << str1 + str2 << endl;
}