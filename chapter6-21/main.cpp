/*
	std::vector //동적할당
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> arr;

	std::vector<int> arr2 = { 1,2,3,4,5 };

	cout << arr2.size() << endl;

	std::vector<int> arr3 = { 1,2,3, };

	cout << arr3.size() << endl;

	std::vector<int> arr4 { 1,2,3, };
	
	cout << arr4.size() << endl;

	cout << arr4[1] << endl;
	cout << arr4.at(1) << endl << endl;

	//----------------------------------------------------

	arr = { 1,2,3,4,5 };

	for (const auto& itr : arr)
		cout << itr << " ";
	cout << endl;

	cout << arr.size() << endl; // 5

	arr = { 1,2 };

	for (const auto& itr : arr)
		cout << itr << " ";
	cout << endl;

	cout << arr.size() << endl; //2

	arr.resize(10);

	for (const auto& itr : arr)
		cout << itr << " ";
	cout << endl;

	cout << arr.size() << endl; //10


	//auto delete

	return 0;
}