#include <iostream>
using namespace std;
#define tab "\n \n"


class Fraction
{
	int integer;      //Целая часть
	int numerator;    //Числитель
	int denominator;  //Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1; //фильтрация данных
		this->denominator = denominator;
	}

	/////////////////////////////////////Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default_Construction: " << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1_Arg_Construction " << this << endl;


	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "2_Arg_Construction: \t" << this << endl;

	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "3_Arg_Constructor: \t" << this << endl;

	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy_Constructor: " << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor: \t" << this << endl;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy_Assignment: \t" << this << endl;
		return *this;
	}
	///////////////////////////////////Incterement/Decrement:
	Fraction& operator++() //Префиксный инкремент
	{
		integer++;
		return *this;
	}
	Fraction operator++(int) // Постфиксный инкремент
	{
		Fraction old = *this; // Сохраняем старое значение + Copy_Constructor
		integer++;
		return old; //Copy_Constructor
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	///////////////////////////////////Methods:
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void for_divide()
	{
		int temp = numerator;
		numerator = denominator;
		denominator = temp;
	}
	void for_add()
	{
		if (denominator = !denominator)
		{
			numerator += denominator * numerator + denominator * numerator;
			denominator += denominator * denominator;
		}
		numerator += numerator + numerator;
		denominator == denominator;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (integer && numerator) cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0) cout << 0;
		cout << endl;
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	//Fraction result
	//(
	//	left.get_numerator() * right.get_numerator(),
	//	left.get_denominator() * right.get_denominator()
	//);
	//return result;
	return Fraction // Вызван явный конструктор, который создает временный объектб с нужным результатом
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	right.for_divide();
	return Fraction 
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}
Fraction operator+(Fraction left, Fraction right) //Не поняла, как сделать проверку на одинаковый знаменатель!!!(((
{
	left.to_improper();
	right.to_improper();
	Fraction res((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator());
		return res;
}
Fraction operator-(Fraction left, Fraction right) //Не поняла, как вернуть "не отрицательный" результат !!!(((
{
	left.to_improper();
	right.to_improper();
	Fraction res((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator());
	return res;
}
bool operator==(const Fraction left, Fraction right) 
{
	return (left == right);
}
bool operator!=(const Fraction left, Fraction right)
{
	return !(left == right);
}


int dvaplusdva()
{
	return 2 + 2;
}

//#define CONSTRUCTION_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTION_CHECK

	Fraction A; //конструктор по-умолчанию
	A.print();
	Fraction B(3); //Конструктор с одним параметром
	B.print();
	Fraction C(3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D; //Конструктор копирования
	E.print();
	Fraction F; // Конструктор по-умолчанию
	F = E;      // Оператор =(присваивания) CopyAssignment
	F.print();
	cout << dvaplusdva() << endl;

#endif // CONSTRUCTION_CHECK

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A + B;
		/*A.print();
		B.print();
		A.to_improper();
		A.print();
		A.to_proper();
		A.print();*/
	C.print();

	if (A == B)
		cout << "Дроби равны" << endl;
	if (A!=B)
		cout << "Дроби неравны" << endl;
	return ;

	for (double i = .25; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (Fraction i (8, 5, 6);  i.get_integer () > 0; --i)
	{
		i.print();
	}
	cout << endl;
}