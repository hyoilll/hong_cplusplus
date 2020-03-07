/*
	예외처리의 기본

	속도가 느려짐. 속도가 중요한 프로그램은 try-catch 사용 안함

	예측할 수 없는 일이 벌어지는 경우에 많이 사용 (게임서버, 몰컴하다 걸렸을 때 급하게 종료)

	throw를 통해 던져진 error를 받아 줄 catch문이 없으면 runtime error발생

	정확히 맞는 자료형이 아니라면 runtime error발생, 자동형변환 해주지 않음.(함수와는 다름)
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//try, catch, throw
	double x;
	cin >> x;

	try
	{
		if (x < 0.0) 
			throw std::string("Negative input");
			//throw "Negative input" => string이 아닌 const char*형으로 throw하면 catch에서 받을 수 없음. 자동형변환해주지 않음.
		
		cout << std::sqrt(x) << endl; //x가 0보다 작으면 실행 불가
	}
	catch (std::string error_message)
	{
		//do something to respond
		cout << error_message << endl;
	}

	//----------------------------------------------------------------------------------

	try
	{
		// something happend
		throw "hi";
	}
	catch (int x)
	{
		cout << "Catch interger " << x << endl;
	}
	catch (double x)
	{
		cout << "Catch double " << x << endl;
	}
	catch (const char* ctr)
	{
		cout << "Char * "<< ctr << endl;
	}
	return 0;
}