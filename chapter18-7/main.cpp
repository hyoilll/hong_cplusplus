/*
	파일의 임의 위치 접근하기
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs(filename);

		ifs.seekg(5); //ifs.seekg(5, ios::beg); //처음부터 5byte이동하고 읽어라
		cout << (char)ifs.get() << endl;

		ifs.seekg(5, ios::cur); //현재의 커서에서 5byte이동하고 읽어라
		cout << (char)ifs.get() << endl;

		ifs.seekg(-5, ios::end); //마막에서 5byte 뒤로 이동
		cout << (char)ifs.get() << endl;

		cout << ifs.tellg() << endl; //현재 커서 위치 출력

	}

	//input / output
	{
		//fstream iofs(filename, ios::in | ios::out)
		fstream iofs(filename); 

		iofs.seekg(5);
		cout << (char)iofs.get() << endl;

		iofs.seekg(5);
		iofs.put('A');
	}

	return 0;
}