/*
	�޸� �����Ҵ� new / delete

	���� - stack - �뷮�� ����
	���� - heap - �뷮�� ŭ
*/

#include <iostream>
using namespace std;

int main()
{
	int* i_ptr = new int(7);

	/*
		int* i_ptr = new (std::nothrow) int(7);
		�޸� �Ҵ��� �����ϸ� nullptr�� ����Ŵ.
		https://m.blog.naver.com/PostView.nhn?blogId=njh0602&logNo=220597201402&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	*/
	cout << &i_ptr << endl;
	cout << i_ptr << endl;
	cout << *i_ptr << endl << endl;
	
	*i_ptr = 10;

	cout << &(*i_ptr) << endl;
	cout << *i_ptr << endl << endl;

	delete i_ptr;
	i_ptr = nullptr;	//delete �Ŀ��� nullptr�� �־��ִ°� ���� (ǥ��)

	if (i_ptr != nullptr)
	{
		cout << i_ptr << endl;
		cout << *i_ptr << endl;
	}
	else
		cout << "nullptr" << endl << endl;

	//-----------------------------------------------------------------------
	//���ǻ���

	int* ptr = new (std::nothrow) int(7);
	int** ptr2 = &ptr;

	cout << ptr << endl;
	cout << ptr2 << endl;
	cout << &ptr << endl;
	//���� �޸𸮸� ����Ŵ

	if (ptr != nullptr)
	{
		cout << *ptr << endl;
		cout << **ptr2 << endl;
		
		*ptr = 5;
		cout << *ptr << endl;

		**ptr2 = 10;
		cout << **ptr2 << endl;
	}
	else
		cout << "nullptr" << endl;
	

	delete ptr;
	ptr = nullptr;
	/*
		ptr2�� ������ ����Ű�� �ݳ��� �޸𸮸� ����Ű�� �ֱ⿡ ptr2�� ���� nullptr���ִ°� ����
	*/
	ptr2 = nullptr;
	
	cout << endl;

	//----------------------------------------------------------------------
	//memory leak �޸� ����

	/*while (true)
	{
		int* ptr = new int;
		cout << ptr << endl;

		delete ptr;
	}*/
	return 0;
}