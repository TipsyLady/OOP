#define _CRT_SECURE_NO_WARNINGS //for strtok
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
	int integer;//Целая часть
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
	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+8;
		numerator = decimal * denominator;
		reduce();
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
	explicit operator int() const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
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

	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do {
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD - Greatest Common Diviser - наибольший общий делитель
		numerator /= GCD;
		denominator /= GCD;
		return *this;
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

ostream& operator<<(ostream& out, const Fraction& x)
{
	if (x.get_integer())out << x.get_integer();
	if (x.get_integer() && x.get_numerator()) out << "(";
	if (x.get_numerator())out << x.get_numerator() << "/" << x.get_denominator();
	if (x.get_integer() && x.get_numerator())out << ")";
	if (x.get_integer() == 0 && x.get_numerator() == 0) out << 0;
	return out;
}
istream& operator>>(istream& in, Fraction& x)
{
	/*int integer, numerator, denominator;
	in >> integer >> numerator >> denominator;
	x.set_integer(integer);
	x.set_numerator(numerator);
	x.set_denominator(denominator);*/

	const int n = 32;
	char buff[n] = {};
	char delimiters[] = "(/) +";
	char* numbers[5] = {};
	cin.getline(buff, n);
	int i = 0;
	for (char* pch = strtok(buff, delimiters); pch; pch = strtok(NULL, delimiters), i++)
	{
		numbers[i] = pch;
	}
	switch (i)
	{
	case 1: x.set_integer(atoi(numbers[0])); break;

	case 2: x.set_numerator(atoi(numbers[0]));
		x.set_denominator(atoi(numbers[1])); break;

	case 3: x.set_integer(atoi(numbers[0]));
		x.set_numerator(atoi(numbers[1]));
		x.set_denominator(atoi(numbers[2])); break;

	default: cout << "Ошибка" << endl;
		break;
	}
	return in;
}

bool operator==(const Fraction& left, const Fraction& right) 
{
//	left.to_improper();
//	right.to_improper();
//	/*if (left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator())*/
//	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
//
	return(double)left == (double)right;
}
bool operator!=(const Fraction& left, const Fraction& right) //Берет копии из оператора "равно" по константной ссылке
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	/*Fraction buf = left * right.inverted();
	if(buf.get_numerator() > buf.get_denominator())
		return true;

	else return false;*/
	return (double)left > (double)right;
}
bool operator<(const Fraction& left, const Fraction& right)
{/*
	Fraction buf = left * right.inverted();
	if (buf.get_numerator() < buf.get_denominator())
		return true;

	else return false;*/
	return (double)left < (double)right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	/*Fraction buf = left * right.inverted();
	if (buf.get_numerator() < buf.get_denominator() || buf.get_numerator() == buf.get_denominator())
		return true;

	else return false;*/
	/*return left > right || left == right;*/
	return !(left < right);//больше или равно - это НЕ меньше
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	/*Fraction buf = left * right.inverted();
	if (buf.get_numerator() < buf.get_denominator() || buf.get_numerator() == buf.get_denominator())
		return true;

	else return false;*/
	/*return left < right || left == right;*/
	return !(left > right); //больше или равно - это НЕ больше
}


int dvaplusdva()
{
	return 2 + 2;
}

//#define CONSTRUCTION_CHECK
//#define INCREMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define OPTIMISATION_CHECK
//#define TYPE_CONVERSION
#define TYPE_CONVERSION_HOMEWORK
//#define COMPARISON
//#define OUTPUT_CHECK
//#define INPUT_CHECK

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

#ifdef COMPARISON

	Fraction A(1, 2);
	Fraction B(5,10);
	//if (A != B)
	//{
	//	cout << "Дроби НЕ равны" << endl;
	//}
	//else {
	//	cout << "Дроби равны" << endl;
	//}
	cout << (A==B) << endl;
	cout << (A!=B) << endl;
	cout << (A>B) << endl;
	cout << (A>=B) << endl;


#endif // COMPARISON


#ifdef TYPE_CONVERSION_HOMEWORK

	//Task1
	Fraction A(2, 3, 4);
	double a = (double)A;
	cout << a << endl;

	//Task2
	double b = 2.75;
	Fraction B = b;
	B.print();

	

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

#ifdef OUTPUT_CHECK
	Fraction A;
	cout << A << endl;
	Fraction B(5);
	cout << B << endl;
	Fraction C(1, 2);
	cout << C << endl;
	Fraction D(2, 3, 4);
	cout << D << endl;
#endif // OUTPUT_CHECK

#ifdef INPUT_CHECK

	Fraction A;
	cout << "Введите простую дробь: " << endl;
	cin >> A;
	cout << "Вы ввели: " << A <<endl;
	cout << "Сокращенная дробь: " << A.reduce() << endl;

#endif // INPUT_CHECK

}