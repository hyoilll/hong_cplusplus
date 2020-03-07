/*
	std::exception 소개
*/

#include <iostream>
#include <exception>
#include <string>
using namespace std;

//exception class 상속
class CustomException : public exception
{
public:
	//virtual const char* what() const throw(); what()의 원형

	virtual const char* what() const noexcept override //noexcept - 적어도 이 함수 안에서는 예외를 던지지 않겠다.
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		/*std::string s;
		s.resize(-1);*/
		
		throw CustomException();
		//throw std::runtime_error("Bad thing happened");
	}
	catch (std::length_error & l)
	{
		std::cout << "length_error" << endl;
		std::cout << typeid(l).name() << endl;
		std::cout << l.what() << endl;
	}
	catch (std::exception & e)
	{
		std::cout << "exception" << endl;
		std::cout << typeid(e).name() << endl;
		std::cout << e.what() << endl;
	}

	return 0;
}