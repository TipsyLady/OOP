#include <iostream>
using namespace std;
#define tab "\t"
#define delimiter "\n-----------------------------------------------"
//#define STRUCT_POINT
//#define DISTANCE_CHECK
#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define CONSTRUCTORS_OVERLOADING

class Point
{
	double x;
	double y;
public:

	double get_x()const
	{

		return x;
	}
	double get_y()const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	 /////////////////////////////////// Constructors:ПЕРЕГРУЗКА КОНСТРУКТОРОВ

	Point() //Конструктор по-умолчанию
	{
		x = y = 0;
		cout << "DefaultConstructor: \t\t" << this << endl;
	}
	Point(double x) //Конструктор с одним параметром
	{
		this->x = x;
		this->y = 0;
		cout << "Single_Argument_Constructor: \t\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
			this->y = y;
			cout << "Constructor: \t\t" << this << endl;
	}
	Point(const Point& other) //Поверхностное копирование объекта Shallow copy
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy_Constructor: \t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	////////////////////Operators:
	Point& operator= (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy_Assignment: \t\t" << this << endl;
		return *this;
	}


	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;

	}

	double Distance (Point& other)
	{
		//B - this
		//A - other
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;

		/*double L;
		L = sqrt(x * x + y * y);
		return L;*/
	}
};
//double Range_AB(Point A, Point B);

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT


	Point A; //создание объекта, объявляем переменную А типа Point
             // Объявляем объект А структуры Point
	         // Создаем экземпляр А структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; //Объвляем указатель на Point и берем адрем точки А
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif  STRUCT_POINT
#ifdef DISTANCE_CHECK
	Point A;
	Point B;// создано в поле видимости main и будет уничтожено при завершении функции main
	
	A.set_x(2);
	A.set_y(3);
	B.set_x(4);
	B.set_y(5);
	//cout << "Введите координаты точки A(x): "; cin >> A.x;
	//cout << "Введите координаты точки A(y): "; cin >> A.y;
	//cout << "Введите координаты точки B(x): "; cin >> B.x;
	//cout << "Введите координаты точки B(y): "; cin >> B.y;

	
	cout << A.get_x() << tab << A.get_y() << endl;
	cout << "Расстояние до точки А: " << B.Distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние до точки B: " << A.Distance(B) << endl;
	//cout << "Расстояние между точкой А и точкой B: " << Range_AB (A,B) << endl;
#endif DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A; //Вызывается default constructor
	A.print();
	Point B = 3;// Конструктор с одним параметром
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C; //Copy Constructor
	D.print();
	Point E; //Default Constructor
	E = C;  //Copy Assignment
	E.print();
#endif CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << "\n----------------------------------------\n";
	A = B = C = Point(4, 5);
	cout << "\n----------------------------------------\n";
	A.print();
	B.print();
	C.print();

#endif ASSIGNMENT_CHECK

}
////double Range_AB(Point& A, Point& B)
//{
//	double R;
//	R = sqrt(((B.x - A.x) * (B.x - A.x)) + ((B.y - A.y) * (B.y - A.y)));
//	return R;
//}