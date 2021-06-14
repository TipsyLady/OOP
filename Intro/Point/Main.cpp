#include <iostream>
using namespace std;
#define tab "\t"
//#define STRUCT_POINT

class Point
{
public:
	double x;
	double y;

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

	double Lenght(double x, double y)
	{
		double L;
		L = sqrt(x * x + y * y);
		return L;
	}
};
double Range_AB(Point A, Point B);

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
#endif // STRUCT_POINT

	Point A, B; // создано в поле видимости main и будет уничтожено при завершении функции main
	
	cout << "Введите координаты точки A(x): "; cin >> A.x;
	cout << "Введите координаты точки A(y): "; cin >> A.y;
	cout << "Введите координаты точки B(x): "; cin >> B.x;
	cout << "Введите координаты точки B(y): "; cin >> B.y;

	
	cout << A.get_x() << tab << A.get_y() << endl;
	cout << "Расстояние до точки А: " << A.Lenght(A.x,A.y) << endl;
	cout << "Расстояние между точкой А и точкой B: " << Range_AB (A,B) << endl;
		
}
double Range_AB(Point A, Point B)
{
	double R;
	R = sqrt(((B.x - A.x) * (B.x - A.x)) + ((B.y - A.y) * (B.y - A.y)));
	return R;
}