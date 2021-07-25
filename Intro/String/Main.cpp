#include <iostream>
#include <string>
using namespace std;
#define tab "\n \n"
class String;
String operator+(const String& left, const String& right);
class String
{
	unsigned int size; //размер строки в байтах
	char* str;		   //указатель на строку в динамической памяти

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
		this->str = new char[size] {};// {} обнуляет выделяемую память
		cout << "Default_Constructor:\t" << this << endl;
	}
	String(const char* str)//Константный указатель на char -строковая константа
	{
		this->size = strlen(str) + 1; //+1 потому что this->size хранит размер в байтах,
									  // а strlen() считает размер в символах
		//while (str[size++]);
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
		//0-проверить ,не является ли принятый объект "нашим объектом
		if (this == &other)return *this;
		//1-удалить старое значение объекта, освободить занимаемую им память
		delete[] this->str;
		//2-выполнить deep copy (copy_assignment)
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
		delete[] this->str;			//[] показывает, что удаляется массив
		cout << "Destructor: \t\t" << this << endl;
	}

	//			METHODS
const char& operator[] (unsigned int i)const//i-индекс
{
	return str[i];
}char& operator[] (unsigned int i) //i-индекс
                                   //Оператор квадратные скобки 
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
		/*cat.get_str()[i] = left.get_str()[i];*/
	cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}
//#define CONSTRUCTORS_CHECK
	int main()
	{
		setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK

		//String str = 5;// Преобразование из int в String
		String str(5); //explicit constructor можно вызвать с () и нельзя вызвать
					   // оператором присвоить =

		str.print();
		String str1 = "Hello";
		str1 = str1;
		str1.print();

		String str2 = str1;//Copy_Constructor
		str.print();

		String str3;
		str3 = str2;
		str3.print();
#endif // CONSTRUCTORS_CHECK

		String str1 = "Hello";
		cout << str1 << endl;
		String str2 = "World";
		cout << str2 << endl;
		/*cout << "\n--------------------------\n";
		String str3 = str1 +" "+ str2;
		cout << "\n--------------------------\n";
		cout << str3 << endl;*/
		cout << str1 + str2 << endl;
	}