/*
	std::array 정적할당
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void printLength(const std::array<int, 5>& my_arr) //매개변수 copy에 드는 비용을 reference로 보완해주고, const붙임
{
	cout << my_arr.size() << endl;
}

int main()
{
	int arr[5]{ 1,2,3,4,5 };
	
	std::array<int, 5> my_arr{ 1,2,3,4,5 };

	cout << my_arr[0] << endl;
	cout << my_arr.at(0) << endl;
	cout << my_arr.size() << endl;

	printLength(my_arr);
	cout << endl;
	
	//--------------------------------------------------
	
	my_arr = { 1,11,23,2,5 };

	for (const auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.begin(), my_arr.end()); //오름차순 정렬

	for (const auto& element : my_arr)
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.rbegin(), my_arr.rend()); //내림차순 정렬
	
	for (const auto& element : my_arr)
		cout << element << " ";
	cout << endl;


	return 0;
}