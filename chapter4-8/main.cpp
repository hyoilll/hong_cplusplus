/*
	영역 제한 열거형 (열거형 클래스) enum class

	[참조] https://blog.seulgi.kim/2015/11/cpp-enum-class.html
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
		서로다른 enum이 비교를 해버리게 되면 내부적으로 int로 돌아가기에
		0 == 0 처럼	되어버려 원치 않는 결과가 나옴.
		그래서 나온게 enum class, 아예 다른 enum끼리는 비교를 못하게 함
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
		error발생 다른 enum class끼리는 서로 비교를 못하게 해버림

		if (color == fruit)
			cout << "Color is Fruit ? " << endl;
	*/

	Color color1 = Color::RED;
	Color color2 = Color::BLUE;

	if (color1 == color2)
		cout << "Same color" << endl;

	return 0;
}