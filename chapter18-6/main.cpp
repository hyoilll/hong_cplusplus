/*
	기본적인 파일 입출력
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	//writing
	{
		ofstream ofs("my_first_file.dat");

		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}

		//ascii 포멧 겁내 느림
		/*{
			ofs << "Line 1" << endl;
			ofs << "Line 2" << endl;
			ofs << "hello world" << endl;
		}*/

		//binary 포멧 좀 더 빠름
		/*{
			//데이터가 어디까지인지 알 수 없음, 얼마만큼 저장할 건지 알고 있어야함.
			const unsigned num_data = 10; //data 갯수
			ofs.write((char*)&num_data, sizeof(num_data));

			for (unsigned int i = 0; i < num_data; ++i)
				ofs.write((char*)&i, sizeof(i));
		}*/

		//stirngstream
		{
			stringstream ss;
			ss << "Line 1" << endl;
			ss << "Line 2" << endl;

			string str = ss.str();
			unsigned int str_length = str.size();

			ofs.write((char*)&str_length, sizeof(str_length));
			ofs.write(str.c_str(), str_length);
		}
	}

	//reading
	{
		ifstream ifs("my_first_file.dat");

		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		//ascii
		/*{
			while (!ifs.eof())
			{
				std::string str;
				getline(ifs, str);

				std::cout << str << endl;
			}
		}*/
		
		//binary
		/*{
			unsigned int num_data = 0;
			ifs.read((char*)&num_data, sizeof(num_data));

			for (unsigned int i = 0; i < num_data; ++i)
			{
				int num;
				ifs.read((char*)&num, sizeof(num));

				cout << num << endl;
			}
		}*/

		//stringstream
		{
			unsigned int str_len = 0;
			ifs.read((char*)&str_len, sizeof(str_len));

			string str;
			str.resize(str_len);
			ifs.read(&str[0], str_len);

			cout << str << endl;
		}
	}
	return 0;
}