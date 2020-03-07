/*
	명령줄 인수 command line arguments

	Boost.Program_options => command line사용시 더 편리하게 해주는 라이브러리
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) //argc : 개수, argv : 내용
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