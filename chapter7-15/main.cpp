/*
	����� �μ� command line arguments

	Boost.Program_options => command line���� �� ���ϰ� ���ִ� ���̺귯��
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) //argc : ����, argv : ����
{
	for (int cnt = 0; cnt < argc; ++cnt)
	{
		std::string argv_single = argv[cnt];

		if (cnt == 1)
		{
			int input_num = std::stoi(argv_single);
		}

		cout << argv_single << endl;
	}


	return 0;
}