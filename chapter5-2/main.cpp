/*
	goto
*/

#include <iostream>
#include <cmath> // sqrt()
using namespace std;

int main()
{
	double x;

tryAgain : //label
	cout << "Enter a non-negative number" << endl;
	cin >> x;

	if (x < 0.0)
		goto tryAgain; // -> label�� �̵� , ����� ������ ���� goto - �ݺ��� ����
	
	cout << sqrt(x) << endl;

	//--------------------------------------------------------------------------------------

	/*
		goto skip;

		x = 5; ������ goto�� ���� label�� �����ϱ⿡ �ʱ�ȭ�� �� �� ����.

	skip :

		x = x + 3; �ʱ�ȭ �� �� ������ ����ϱ⿡ ����
		
	*/


	return 0;
}