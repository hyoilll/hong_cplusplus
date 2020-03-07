/*
	std::exception �Ұ�
*/

#include <iostream>
#include <exception>
#include <string>
using namespace std;

//exception class ���
class CustomException : public exception
{
public:
	//virtual const char* what() const throw(); what()�� ����

	virtual const char* what() const noexcept override //noexcept - ��� �� �Լ� �ȿ����� ���ܸ� ������ �ʰڴ�.
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