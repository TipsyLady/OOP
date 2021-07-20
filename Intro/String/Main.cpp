#include <iostream>
#include <string>
using namespace std;
#define tab "\n \n"

class String
{
	int size;
	char* str;

public:
	int get_size() const
	{
		return size;
	}
	char* get_str()
	{
		return str;
	}
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Default_Construction: " << this << endl;
		cout << sizeof(str) << endl;
	}
};
	int main()
	{
		String str;

	}