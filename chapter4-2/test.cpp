#include <iostream>
#include "MyConstant.h"

extern int z;
extern void print()
{
	using namespace std;

	cout << "Hello" << endl;

	cout << "In test.cpp " << Constants::pi << " " << &Constants::pi << endl;
}