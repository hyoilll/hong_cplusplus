/*
	흐름 상태와 입력 유효성 검증
*/

#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printStates(const std::ios& stream)
{
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

void printStatesBitset(const std::ios& stream)
{
	cout << boolalpha;
	cout << std::bitset<8>(stream.rdstate()) << endl; //good bit는 true - 0, false - 1

	cout << std::bitset<8>(std::istream::goodbit) << " "; //bit mask
	if ((stream.rdstate() & std::istream::goodbit) == 0)
		cout << "good()=" << true << endl;
	else
		cout << "good()=" << false << endl;

	cout << std::bitset<8>(std::istream::eofbit) << " ";
	if ((stream.rdstate() & std::istream::eofbit) == 0)
		cout << "eofbit()=" << false << endl;
	else
		cout << "eofbit()=" << true << endl;

	cout << std::bitset<8>(std::istream::failbit) << " ";
	if ((stream.rdstate() & std::istream::failbit) == 0)
		cout << "failbit()=" << false << endl;
	else
		cout << "failbit()=" << true << endl;

	cout << std::bitset<8>(std::istream::badbit) << " ";
	if ((stream.rdstate() & std::istream::badbit) == 0)
		cout << "badbit()=" << false << endl;
	else
		cout << "badbit()=" << true << endl;
}

void printCharacterClassification(const int& i)
{
	cout << boolalpha;
	//반환 값이 int라서 bool로 형변환함
	cout << "isalnum " << bool(std::isalnum(i)) << endl; //#include <cctype> 
	cout << "isblank " << bool(std::isblank(i)) << endl;
	cout << "isdigit " << bool(std::isdigit(i)) << endl;
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;
}

bool isAllDigit(const string& str)
{
	for (const auto& e : str)
	{
		if ((std::isdigit(e)) == false)
			return false;
	}

	return true;
}

int main()
{
	/*{
		while (true)
		{
			char i;
			cin >> i;

			printStates(cin);		//이렇게 하는게 보기도, 하기도 편함

			//printStatesBitset(cin); //최적화

			printCharacterClassification(i);

			cin.clear();

			cin.ignore(1024, '\n');

			cout << endl;

		}
	}*/

	{
		cout << boolalpha;

		cout << isAllDigit("1234") << endl;
		cout << isAllDigit("a1234") << endl;

		//여기서 배운 것들은 한글자씩 비교하는 방법, 앞에서 정규식을 이용한 더 편한 방법이 따로 있음.
	}

	
	return 0;
}