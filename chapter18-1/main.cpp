/*
	istream���� �Է¹ޱ�
*/

#include <iostream>
#include <iomanip> //input/output/ manipuators
#include <string>
using namespace std;



int main()
{
	/*{
		cout << "Enter a number" << endl;

		int i;

		cin >> i;

		cout << i << endl;
	}*/

	//{
	//	char buf[10]; //null���� ���� ������ 10����

	//	//cin >> buf; �Է��� ���� �״�� �����ͼ� error

	//	cin >> setw(10) >> buf; //�ִ� 10���ڸ� ���� �� �ֵ��� �������� (10���� �Ѱ� �Է��ص�) #include <iomanip>
	//	/*
	//		�Է��� ���ڰ� ���ۿ� ���µ� inputstream ���ۿ� �� �� 10���� ������ (9�� + null)
	//	*/

	//	cout << buf << endl;

	//	cin >> setw(10) >> buf; //���� �Է��� �޾Ƶ� ������ ���ۿ� �ִ� ���� �״�� �������⿡ ���� �Է� ���� ����.

	//	cout << buf << endl;
	//}

	/*{
		char c;

		while (cin >> c) //���ڸ� �ް� ���� ��
			cout << c;
	}*/

	/*{
		char ch;

		while (cin.get(ch)) //���ڿ��� �ް� ������
			cout << ch;

		
	}*/

	//{
	//	char buf[5];

	//	cin.get(buf, 5);

	//	cout << buf << endl;
	//	cout << cin.gcount() << endl; //buffer���� ����� �о� �Գ� Ȯ��

	//	cin.get(buf, 5);

	//	cout << buf << endl;

	//	/*
	//		getline - �ش� ũ�⸸ŭ �о���� �� �������� ���� , �ٹٲ� ���ڱ��� ���� �о����
	//		get - �ش� ũ�⸸ŭ �о���� �� �������� �״�� buffer�� ���ܵ�

	//		[����] https://m.blog.naver.com/PostView.nhn?blogId=daimon123&logNo=220465985570&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	//	*/
	//}

	/*{
		string buf;

		getline(cin, buf);

		cout << " " << buf << endl;
	}*/

	{
		char buf[1024];

		cin.ignore(0); //�Ű������� int��ŭ ������

		cin >> buf;

		cout << buf << endl;
	}

	{
		char buf[1024];

		cout << (char)cin.peek() << endl; //������ �� ���ڰ� ���� Ȯ�θ���. buffer���� ������� ����
	}

	{
		char buf[1024];

		cin >> buf;

		cout << buf << endl;

		cin.unget(); //�������� �о� ���� ���� �ٽ� buffer�� �־���

		cin >> buf;

		cout << buf << endl;
	}

	{
		cin.putback('A'); // ���ϴ� ���ڸ� buffer�� ����
	}

	return 0;
}