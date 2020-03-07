/*
	istream으로 입력받기
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
	//	char buf[10]; //null문자 까지 포함한 10글자

	//	//cin >> buf; 입력한 글자 그대로 가져와서 error

	//	cin >> setw(10) >> buf; //최대 10글자만 받을 수 있도록 방지해줌 (10글자 넘게 입력해도) #include <iomanip>
	//	/*
	//		입력한 문자가 버퍼에 들어가는데 inputstream 버퍼에 그 중 10개만 가져옴 (9개 + null)
	//	*/

	//	cout << buf << endl;

	//	cin >> setw(10) >> buf; //새로 입력을 받아도 기존의 버퍼에 있는 값을 그대로 가져오기에 새로 입력 받지 않음.

	//	cout << buf << endl;
	//}

	/*{
		char c;

		while (cin >> c) //문자를 받고 싶을 때
			cout << c;
	}*/

	/*{
		char ch;

		while (cin.get(ch)) //문자열을 받고 싶을때
			cout << ch;

		
	}*/

	//{
	//	char buf[5];

	//	cin.get(buf, 5);

	//	cout << buf << endl;
	//	cout << cin.gcount() << endl; //buffer에서 몇글자 읽어 왔나 확인

	//	cin.get(buf, 5);

	//	cout << buf << endl;

	//	/*
	//		getline - 해당 크기만큼 읽어들인 후 나머지는 버림 , 줄바꿈 문자까지 같이 읽어들임
	//		get - 해당 크기만큼 읽어들인 후 나머지는 그대로 buffer에 남겨둠

	//		[참조] https://m.blog.naver.com/PostView.nhn?blogId=daimon123&logNo=220465985570&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	//	*/
	//}

	/*{
		string buf;

		getline(cin, buf);

		cout << " " << buf << endl;
	}*/

	{
		char buf[1024];

		cin.ignore(0); //매개변수의 int만큼 무시함

		cin >> buf;

		cout << buf << endl;
	}

	{
		char buf[1024];

		cout << (char)cin.peek() << endl; //다음에 올 글자가 먼지 확인만함. buffer에서 사라지진 않음
	}

	{
		char buf[1024];

		cin >> buf;

		cout << buf << endl;

		cin.unget(); //마지막에 읽어 들인 값을 다시 buffer에 넣어줌

		cin >> buf;

		cout << buf << endl;
	}

	{
		cin.putback('A'); // 원하는 문자를 buffer에 넣음
	}

	return 0;
}