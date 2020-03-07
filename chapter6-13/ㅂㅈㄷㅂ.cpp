#include <iostream>
using namespace std;

int main()
{
	int n = 5;
	int* p = &n;

	cout << &n << endl;				
	cout << p << endl;
	cout << (&n) + 1 << endl;
	cout << p + 1 << endl << endl;
	
	int arr[] = { 1,2,3,4 };

	cout << *arr << endl;		//1
	cout << *(arr + 1) << endl;	//2
	cout << arr[0] << endl;		//1
	cout << arr[1] << endl << endl;		//2

	const char* const pCity = "Dallas";
	cout << pCity << endl;			//Dallas
	cout << *pCity << endl;			//D
	cout << *(pCity + 1) << endl;	//a
	cout << *(pCity + 2) << endl;	//l
	cout << *(pCity + 3) << endl << endl;	//l

	const char* city = "Dallas";
	cout << city[0] << endl;		//D

	const char* cities[] = { "Dallas", "Atlanta", "Houston" };
	cout << cities[0] << endl;		//Dallas
	cout << cities[0][0] << endl;	//D

	return 0;
}