/*
	������ ���� ��ġ �����ϱ�
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

		ifs.seekg(5); //ifs.seekg(5, ios::beg); //ó������ 5byte�̵��ϰ� �о��
		cout << (char)ifs.get() << endl;

		ifs.seekg(5, ios::cur); //������ Ŀ������ 5byte�̵��ϰ� �о��
		cout << (char)ifs.get() << endl;

		ifs.seekg(-5, ios::end); //�������� 5byte �ڷ� �̵�
		cout << (char)ifs.get() << endl;

		cout << ifs.tellg() << endl; //���� Ŀ�� ��ġ ���

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