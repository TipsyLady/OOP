#include <iostream>
using namespace std;
#define tab "\n \n"
class Fraction; //Объявление класса 
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
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
	explicit Fraction(int integer)
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
	Fraction operator*=(const Fraction& other)
	{	
	/*	int a = 2;
		int b = 3;
		a *= b;
		a = a * b;*/
		return *this = *this * other;
	}
	Fraction operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction operator/=(const Fraction& other)
	{
		return *this = *this / other;
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

	///////////////////////////////////Type-cast operators:
	operator int()
	{
		return integer;
	}

	///////////////////////////////////Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		return Fraction(denominator, numerator);
	/*	int temp = numerator;
		numerator = denominator;
		denominator = temp;
		return *this; */
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
	return left * right.inverted();
	/*left.to_improper();
	right.to_improper();
	right.for_divide();
	return Fraction 
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/
}
Fraction operator+(Fraction left, Fraction right) 
{
	left.to_improper();
	right.to_improper();
	return Fraction 
	((left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),
	left.get_denominator() * right.get_denominator());
}
Fraction operator-(Fraction left, Fraction right) 
{
	left.to_improper();
	right.to_improper();
	return Fraction
	((left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()).to_proper();
}

bool operator==(Fraction left, Fraction right) 
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator())
	return true;
	
	else return false;
}
bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator() != right.get_numerator() && left.get_denominator() != right.get_denominator())
		return true;

	else return false;
}
bool operator>(Fraction left, Fraction right)
{
	Fraction buf = left * right.inverted();
	if(buf.get_numerator() > buf.get_denominator())
		return true;

	else return false;
}
bool operator<(Fraction left, Fraction right)
{
	Fraction buf = left * right.inverted();
	if (buf.get_numerator() < buf.get_denominator())
		return true;

	else return false;
}
bool operator>=(Fraction left, Fraction right)
{
	Fraction buf = left * right.inverted();
	if (buf.get_numerator() < buf.get_denominator() || buf.get_numerator() == buf.get_denominator())
		return true;

	else return false;
}
bool operator<=(Fraction left, Fraction right)
{
	Fraction buf = left * right.inverted();
	if (buf.get_numerator() < buf.get_denominator() || buf.get_numerator() == buf.get_denominator())
		return true;

	else return false;
}

int dvaplusdva()
{
	return 2 + 2;
}

//#define CONSTRUCTION_CHECK
//#define INCREMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
#define OPTIMISATION_CHECK
//#define TYPE_CONVERSION
#define TYPE_CONVERSION_HOMEWORK

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

#endif CONSTRUCTION_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A / B;
		/*A.print();
		B.print();
		A.to_improper();
		A.print();
		A.to_proper();
		A.print();*/
	C.print();
	Fraction E = A + B;
	E.print();
	(A + B).print();

#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef OPTIMISATION_CHECK
	Fraction A(2, 3, 4);
	Fraction B(2, 3, 4);
	if (A >= B)
		cout << "Первая дробь больше или равна второй" <<endl;
	A.print();

#endif // OPTIMISATION_CHECK

#ifdef TYPE_CONVERSION
	//int a = 2; // нет преобразования
//double b = 3; //from int to double (from less to more)
//int c = 4.5; //from double to int (from more to less with data loss)
//int d = b; //from double to int (no data loos)
//double e = 5.3;
//int f = a + e; //a+e - double, f - int
	int a = 2;
	Fraction A = (Fraction)5; //from int to fraction (from less to more)
	A.print();
	Fraction B;
	B = (Fraction)3;
	B.print();
	int b = B;
	cout << b << endl;
#endif // TYPE_CONVERSION

#ifdef TYPE_CONVERSION_HOMEWORK

#endif // TYPE_CONVERSION_HOMEWORK


	//if (A == B)
	//	cout << "Дроби равны" << endl;
	//if (A!=B)
	//	cout << "Дроби неравны" << endl;
	//return ;

#ifdef INCREMENT_CHECK
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

#endif // INCREMENT_CHECK

}