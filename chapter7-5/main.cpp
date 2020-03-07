/*
	�پ��� ��ȯ ����(��, ����, �ּ�, ����ü, Ʃ��)
*/

#include <iostream>
#include <array>
#include <tuple>
using namespace std;

int* getValue(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemory(int size)
{
	return new int[size];
}

int& getReferenceValue(int x)
{
	int value = x * 2;
	return value;
}

int& get(std::array<int, 100>& my_arr, int ix)
{
	return my_arr[ix];
}

void changeValue(std::array<int, 100>& arr, int ix, int value)
{
	arr[ix] = value;
	return;
}

struct S
{
	int a, b, c, d;
};

S getStruct()
{
	S My_s{ 1,2,3,4 };

	return My_s;
}

std::tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;

	return std::make_tuple(a, d);
}

int main()
{
	//�̷� ������ �ڵ� x
	int* value = getValue(3);

	cout << value << endl;
	cout << *value << endl << endl; // �����Ⱚ

	//---------------------------------------------------------

	//�Լ� ��ȯ�� ���� �����Ҵ�
	int* arr = allocateMemory(1024);

	delete[] arr;

	//----------------------------------------------------------

	int &num = getReferenceValue(5);

	cout << num << endl;
	cout << num << endl << endl;	//�����Ⱚ

	//=> �Լ����� ��� �� ����� ���������� �ּҰ��� ������ �ٸ� �������� ����Ϸ� �ϴ� ���� ������.

	//----------------------------------------------------------

	std::array<int, 100> my_arr;
	
	my_arr[30] = 10;
	
	cout << my_arr[30] << endl;
	
	get(my_arr, 30) = 1024; // my_arr[30] = 1024;
	
	cout << my_arr[30] << endl;
	
	changeValue(my_arr, 30, 100);

	cout << my_arr[30] << endl << endl;

	//-----------------------------------------------------------

	S my_s = getStruct();

	cout << my_s.a << " " << my_s.b << " " << my_s.c << " " << my_s.d << endl << endl;

	//-----------------------------------------------------------

	std::tuple<int, double> tu = getTuple();

	cout << std::get<0>(tu) << endl; // a : 10
	cout << std::get<1>(tu) << endl; // d : 3.14

	/*
		c++11���� �ڵ� ���
		auto [a, d] = getTuple();

		cout << a << endl;
		cout << d << endl;
	*/
	return 0;
}