/*
	���� ǥ���� �Ұ�

	string �Է��� �޴µ� ���� ���ϴ� ���Ŀ� �´��� �ƴ��� Ȯ���ϱ� ���� ��
*/

#include <iostream>
#include <regex> //regular expression
#include <string>
using namespace std;



int main()
{
	{
		regex re("\\d+"); //\d : ���ڳ� �ƴϳ� (���� 1��)
						  //\d+ : 1�� �̻��� ����
		
		//regex re("[ab]"); //a, b �� �����
		//regex re("[[:digit:]]{3}"); //{}���� ���ڸ�ŭ�� ���̸� �ްڴ�
		//regex re("[A-Z]+");
		//regex re("[A-Z]{1,5}"); //{} 1�� �̻� 5�� ����
		//regex re("([0-9]{1})([-]?)([0-9]{1,4})"); //0~9 ���ڸ� 1�� �ް�, -�� �־ �ǰ� ��� �ǰ�, 0~9 ���ڸ� 1���̻� 4�� ����
		
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