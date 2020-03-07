/*
	���� �ʺ� ���� c++ 11 <cstdint>
	�ּ� ����� �����ϰ� �ֱ⿡ �ü���� ���� ����� �ٸ� ���� �ִ�. 
	�� ��Ȯ�Ǽ��� �ذ��ϱ� ���� �Ȱ��� ����� ����ϴ� '���� �ʺ� ����'�� ����
*/
#include <iostream>

int main()
{
	using namespace std;

	std::int16_t i(5); //16bit�� �Ҵ��ϰڴ�. = short
	std::int8_t myint = 65; //8bit�� �Ҵ��Ѵ�. = char

	cout << myint << endl; //A

	cout << sizeof(i) << endl; //2bytes
	cout << sizeof(myint) << endl; //1bytes

	std::int_fast8_t fi(5); //int 8bit �߿��� ���� ���� ������ Ÿ������ �Ҵ�
	std::int_least64_t fl(5); //��� 64bit�� �Ҵ�

	cout << sizeof(fi) << endl; //1bytes
	cout << sizeof(fl) << endl; //8bytes

	return 0;
}