/*
	������
	overflow, underflow, error of divide 
*/

#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;
	cout << "short" << endl;
	short s = 1; // 2bytes = 2 * 8 = 16bits(2^16)
	
	cout << std::pow(2, sizeof(s) * 8 - 1) - 1 << endl;
	cout << std::numeric_limits<short>::max() << endl;
	cout << std::numeric_limits<short>::min() << endl;
	cout << std::numeric_limits<short>::lowest() << endl;
	
	s = 32767; //short�� max��
	s = s + 1; //overflow

	cout << s << endl;

	s = -32768; //short�� min��
	s = s - 1;  //underflow

	cout << s << endl;

	//---------------------------------------
	cout << endl << "sigend int" << endl;

	int i = 0; // 4 bytes = 4 * 8 = 32bit(2 ^ 32)
	
	cout << sizeof(i) << endl;
	cout << std::pow(2, sizeof(i) * 8 - 1) -1 << endl;
	cout << std::numeric_limits<int>::max() << endl;
	cout << std::numeric_limits<int>::lowest() << endl;

	i = 2147483647; // max
	i = i + 1; //overflow

	cout << i << endl; //-2147483648

	// i = -2147483648; error
	//���� ��ũ
	//https://docs.microsoft.com/ko-kr/cpp/error-messages/compiler-warnings/compiler-warning-level-2-c4146?view=vs-2019
	
	i = -2147483647 - 1; //min
	i = i - 1;
	
	cout << i << endl;
	
	//------------------------------------------------
	cout << endl <<"unsigend int" << endl;

	unsigned int ui = 1; // 4bytes = 4 * 8 = 32bit(2^32)

	cout << sizeof(ui) << endl;
	cout << std::pow(2, sizeof(ui) * 8) - 1 << endl;
	cout << std::numeric_limits<unsigned int>::max() << endl;
	cout << std::numeric_limits<unsigned int>::min() << endl;

	ui = 4294967295;
	ui = ui + 1;

	cout << ui << endl;

	ui = 0;
	ui = ui - 1;

	cout << ui << endl;

	//-----------------------
	cout << endl << "divide" << endl;

	double d = 22 / 4;
	cout << d << endl; // 5
	// => ���� / ���� �� ��� ����� ������ �����ϱ� ������ double�� �޾Ƶ� ������ ĳ���� �� �Ķ� �߷��� ����

	d = (double)22 / 4;
	cout << d << endl; // 5.5
	// => �Ǽ� / ���� or ���� / �Ǽ� �� ��� ������ �Ǽ��� ĳ���� �� ����ϱ⿡ ����� �Ǽ��� ����
	
	return 0;
}