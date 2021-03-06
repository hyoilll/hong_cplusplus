/*
	입출력 연산자 오버로딩
*/

#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(const double x = 0.0, const double y = 0.0, const double z = 0.0)
		:m_x(x), m_y(y), m_z(z) {}

	double getX()const { return m_x; }
	double getY()const { return m_y; }
	double getZ()const { return m_z; }

	/*void print()const
	{
		cout << m_x << " " << m_y << " " << m_z << endl;
	}*/

	friend std::ostream& operator <<(std::ostream& out, const Point& point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z << endl;
		return out;
	}

	friend std::istream& operator >>(std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;
		return in;
	}
	
};

int main()
{
	ofstream of("out.txt");

	Point p1(0.0, 0.1, 0.2);
	Point p2(3.4, 1.5, 2.0);

	cin >> p1 >> p2;

	/*
	p1.print();
	p2.print();
	*/

	cout << p1 << " " << p2 << endl;
	of << p1 << " " << p2 << endl;

	of.close();

	return 0;
}