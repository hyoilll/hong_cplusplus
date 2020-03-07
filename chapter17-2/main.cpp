/*
	std::string의 생성자들과 형변환
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

template <class T>
std::string ToString(T x)
{
	std::ostringstream osstream;

	osstream << x;

	return osstream.str(); //string으로 변환 후 리턴
}

template <class T>
bool FromString(const std::string& str, T& x)
{
	std::istringstream isstream(str);

	//str의 값을 x로 넣어줌
	return (isstream >> x) ? true : false;
}

int main()
{
	{
		std::string str("my string");

		const char* ctr = "my string";

		std::string copy_str(ctr, 4, 2);

		std::cout << str << std::endl;

		std::cout << copy_str << std::endl;
	}

	//----------------------------------------

	{
		std::vector<char> vec;

		for (const auto& e : "Today is a good day.")
			vec.push_back(e);

		std::string copy(vec.begin(), vec.end());

		std::cout << copy << std::endl;

		std::string f_str(vec.begin(), std::find(vec.begin(), vec.end(), 'g'));

		std::cout << f_str << std::endl;
	}

	//---------------------------------------------------------------------------

	{
		std::string my_str(std::to_string(4));

		int i = std::stoi(my_str);

		double d = std::stod(my_str);

		std::cout << my_str << std::endl;

		std::cout << i << std::endl;

		std::cout << d << std::endl;
	}

	//----------------------------------------------------------------

	{
		std::string my_str(ToString(3.141592));

		double d;

		if (FromString(my_str, d))
			std::cout << d << std::endl;
		else
			std::cout << "Cannot convert string to double" << std::endl;

		std::cout << my_str << std::endl;
	}
	return 0;
}