/*
	열거형 enumerated types
*/

#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

//general
int computeDamage(int weapon_id)
{
	if (weapon_id == 0) //sword
	{
		return 1;
	}
	else if(weapon_id == 1) //hammer
	{
		return 2;
	}
	//...
}

//enum user - defined data types
enum Color
{
	COLOR_BLACK,	// 0 내부적으로는 int로 저장됨
	COLOR_RED,		// 1
	COLOR_BLUE,		// 2
	COLOR_GREEN		// 3
	//BLUE
}; //;필수

enum Feeling
{
	FEELING_HAPPY,
	FEELING_JOY,
	FEELING_TIRED,
	FEELING_BLUE
	//BLUE
};
// => Color, Feeling에 똑같은 변수 이름이 있으면 에러, 전역변수처럼 작동

int selectColor(int color_id)
{
	if (color_id == COLOR_RED) //red
	{
		return COLOR_RED;
	}
	else if (color_id == COLOR_BLUE) //blue
	{
		return COLOR_BLUE;
	}
	//...
}

int main()
{
	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED };

	cout << paint << endl;

	//cin >> paint; x
	int in_number;
	cin >> in_number;

	if (in_number == 0)
		paint = COLOR_BLACK;
	//...

	return 0;
}