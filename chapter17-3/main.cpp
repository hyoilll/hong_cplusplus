/*
	std::string의 길이와 용량
*/

#include <iostream>
#include <string>
using namespace std;



int main()
{
	{
		string str("012345678");
		string emptyStr("");
		cout << str.size() << endl;

		//char처럼 마지막에 null을 갖고 있지 않음, 클래스이기 때문에 length를 따로 갖고 있어서 굳이 null이 필요없음.

		cout << std::boolalpha;

		cout << str.empty() << endl; //true - 비어있음, false - 비어있지 않음.
		cout << emptyStr.empty() << endl;
		//""대입시 cosnt char*로는 사이즈 1로 되지만 string은 비어있는 걸로 처리가 됨
	}

	{
		string str("01234567");

		//str.reserve(1000);
		str.resize(1000);

		/*
		reserve - 아직 사용은 않하지만 용량만 확보해놓자.
		resize - 지금 바로 사용하니까 length에도 값이 영향을 미침
		*/

		cout << std::boolalpha;
		cout << str.length() << endl;
		cout << str.size() << endl;
		cout << str.capacity() << endl;
		cout << str.max_size() << endl;
	}

	{

	}

	return 0;
}