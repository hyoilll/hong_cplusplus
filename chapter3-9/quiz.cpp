#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	//1.
	unsigned char option_viewd = 0x01;
	unsigned char option_edited = 0x02;
	unsigned char option_liked = 0x04;
	unsigned char option_shared = 0x08;
	unsigned char option_deleted = 0x80;

	unsigned char options_flag = 0;

	cout << "Current bit " << bitset<8>(options_flag) << endl;

	//��縦 ���� ��
	options_flag = options_flag | option_viewd;

	cout << "option_viewd " << bitset<8>(options_flag) << endl;

	//����� ���ƿ並 Ŭ������ ��
	options_flag = options_flag | option_liked;

	cout << "option_liked " << bitset<8>(options_flag) << endl;

	//����� ���ƿ並 �ٽ� Ŭ������ ��
	options_flag = options_flag ^ option_liked;

	cout << "togle option_liked " << bitset<8>(options_flag) << endl;

	//�� ��縸 ������ ��
	if ((options_flag & option_viewd) != 0)
		options_flag = options_flag | option_deleted;

	cout << "option_deleted " << bitset<8>(options_flag) << endl;

	//2.
	unsigned char option4 = 1 << 3;
	unsigned char option5 = 1 << 4;
	
	cout << "option4 " << bitset<8>(option4) << endl;
	cout << "option5 " << bitset<8>(option5) << endl;

	unsigned char myFlags = 0;

	//��𸣰�
	//myFlags = myFlags & ~(option4 | option5);
	myFlags = myFlags & ~option4 & ~option5;

	cout << "myFlags " << bitset<8>(myFlags) << endl;

	

	return 0;
}