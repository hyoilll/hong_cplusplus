/*
	ostream���� ����ϱ�
*/

#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
	//{
	//	//+��ȣ ����
	//	cout.setf(std::ios::showpos);

	//	cout << 108 << endl;

	//	//��ȣ ����
	//	cout.unsetf(std::ios::showpos);

	//	cout << 108 << endl;
	//}

	//{
	//	cout.setf(std::ios::uppercase);// �빮�� ǥ��

	//	//1. 16������ ǥ�� (���� 10���� ǥ���� ���ְ� 16���� ����)
	//	cout.unsetf(std::ios::dec);

	//	cout.setf(std::ios::hex);

	//	cout << 108 << endl;

	//	//2. �ι�° ���
	//	//cout << std::hex;
	//	//cout << std::hex << std::uppercase; #include <iomanip>

	//	//1. 10���� ����
	//	cout.setf(std::ios::dec);

	//	//2. �ι�° ���
	//	cout << std::dec;

	//	cout << 10 << endl;
	//}

	/*{
		cout << std::boolalpha;

		cout << true << " " << false << endl;
	}*/

	{
		//cout << std::defaultfloat;

		//��ȿ����
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout << endl;

		//�Ҽ��� ǥ��
		cout << std::showpoint;
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout << endl;

		//�Ҽ��� ���� ǥ���ڸ�
		cout << std::fixed;
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout << endl;

		cout << std::scientific;
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout.unsetf(std::ios::scientific);
		cout << endl;
	}

	{
		cout << -12345 << endl;
		cout.fill('*');
		cout << std::setw(10) << -12345 << endl; // 10�ڸ��� ä����
		cout << std::setw(10) << std::left << -12345 << endl;
		cout << std::setw(10) << std::right << -12345 << endl;
		cout << std::setw(10) << std::internal << -12345 << endl;
		
	}
	return 0;
}