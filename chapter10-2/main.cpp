/*
	구성 관계
*/

#include "Monster.h"

using namespace std;



int main()
{
	Monster mon1("Sanson",Position(0,0));

	cout << mon1 << endl;

	//while (true) game loop
	{
		//event - rocation
		mon1.moveTo(Position(1,1));
		cout << mon1 << endl;
	}


	return 0;
}