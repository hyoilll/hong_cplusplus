/*
	����ó���� �⺻

	�ӵ��� ������. �ӵ��� �߿��� ���α׷��� try-catch ��� ����

	������ �� ���� ���� �������� ��쿡 ���� ��� (���Ӽ���, �����ϴ� �ɷ��� �� ���ϰ� ����)

	throw�� ���� ������ error�� �޾� �� catch���� ������ runtime error�߻�

	��Ȯ�� �´� �ڷ����� �ƴ϶�� runtime error�߻�, �ڵ�����ȯ ������ ����.(�Լ��ʹ� �ٸ�)
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
			//throw "Negative input" => string�� �ƴ� const char*������ throw�ϸ� catch���� ���� �� ����. �ڵ�����ȯ������ ����.
		
		cout << std::sqrt(x) << endl; //x�� 0���� ������ ���� �Ұ�
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