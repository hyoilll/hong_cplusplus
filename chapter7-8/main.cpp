/*
	����Ʈ �Ű�����
*/

#include <iostream>
#include <string>
using namespace std;

//����Ʈ �Ű������� ����� ���� �ѱ��������� ����, ���� ����ο� �־��
void print(int x, int y = 3, int z = 5);

void print(int x, int y, int z)
{
	cout << x << " " << y << " " << z << endl;
	return;
}

void print(std::string str) {}
void print(char ch = ' ') {}
void print(int x) {}
void print(int x, int y = 20) {}


int main()
{
	/*
		print(10);

		error.
		void print(int x, int y = 3, int z = 5);
		void print(int x) {}

		�浹, �����ε� ��ȣ��
	*/
	print(1,2,3);

	print(); //print(char)

	return 0;
}