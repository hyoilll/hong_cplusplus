/*
	정규 표현식 소개

	string 입력을 받는데 내가 원하는 형식에 맞는지 아닌지 확인하기 위한 것
*/

#include <iostream>
#include <regex> //regular expression
#include <string>
using namespace std;



int main()
{
	{
		regex re("\\d+"); //\d : 숫자냐 아니냐 (숫자 1개)
						  //\d+ : 1개 이상의 글자
		
		//regex re("[ab]"); //a, b 만 통과함
		//regex re("[[:digit:]]{3}"); //{}안의 숫자만큼의 길이를 받겠다
		//regex re("[A-Z]+");
		//regex re("[A-Z]{1,5}"); //{} 1개 이상 5개 이하
		//regex re("([0-9]{1})([-]?)([0-9]{1,4})"); //0~9 숫자를 1개 받고, -가 있어도 되고 없어도 되고, 0~9 숫자를 1개이상 4개 이하
		
		string str;

		while (true)
		{
			getline(cin, str);

			if (std::regex_match(str, re))
				cout << "Match" << endl;
			else
				cout << "No match" << endl;

			//print matches
			{
				auto begin = std::sregex_iterator(str.begin(), str.end(), re);
				auto end = std::sregex_iterator();

				for (auto itr = begin; itr != end; ++itr)
				{
					std::smatch match = *itr;
					cout << match.str() << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}