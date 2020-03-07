/*
	���� ���� ������ (������ Ŭ����) enum class

	[����] https://blog.seulgi.kim/2015/11/cpp-enum-class.html
*/

#include <iostream>
using namespace std;

int main()
{
	enum Color
	{
		RED,
		BLUE
	};
	
	enum Fruit
	{
		BANANA,
		APPLE
	};
	
	Color color = RED;
	Fruit fruit = BANANA;
	
	if (color == fruit) 
		cout << "Color is Fruit ? " << endl;
	/*
		���δٸ� enum�� �񱳸� �ع����� �Ǹ� ���������� int�� ���ư��⿡
		0 == 0 ó��	�Ǿ���� ��ġ �ʴ� ����� ����.
		�׷��� ���°� enum class, �ƿ� �ٸ� enum������ �񱳸� ���ϰ� ��
	*/

	//---------------------------------------------------------------------------

	enum class Color
	{
		RED,
		BLUE
	};

	enum class Fruit
	{
		BANANA,
		APPLE
	};

	Color color = Color::RED;
	Fruit fruit = Fruit::BANANA;

	/*
		error�߻� �ٸ� enum class������ ���� �񱳸� ���ϰ� �ع���

		if (color == fruit)
			cout << "Color is Fruit ? " << endl;
	*/

	Color color1 = Color::RED;
	Color color2 = Color::BLUE;

	if (color1 == color2)
		cout << "Same color" << endl;

	return 0;
}