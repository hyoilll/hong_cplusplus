/*
	메모리 동적할당 new / delete

	정적 - stack - 용량이 작음
	동적 - heap - 용량이 큼
*/

#include <iostream>
using namespace std;

int main()
{
	int* i_ptr = new int(7);

	/*
		int* i_ptr = new (std::nothrow) int(7);
		메모리 할당이 실패하면 nullptr을 가르킴.
		https://m.blog.naver.com/PostView.nhn?blogId=njh0602&logNo=220597201402&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	*/
	cout << &i_ptr << endl;
	cout << i_ptr << endl;
	cout << *i_ptr << endl << endl;
	
	*i_ptr = 10;

	cout << &(*i_ptr) << endl;
	cout << *i_ptr << endl << endl;

	delete i_ptr;
	i_ptr = nullptr;	//delete 후에는 nullptr을 넣어주는게 좋음 (표시)

	if (i_ptr != nullptr)
	{
		cout << i_ptr << endl;
		cout << *i_ptr << endl;
	}
	else
		cout << "nullptr" << endl << endl;

	//-----------------------------------------------------------------------
	//주의사항

	int* ptr = new (std::nothrow) int(7);
	int** ptr2 = &ptr;

	cout << ptr << endl;
	cout << ptr2 << endl;
	cout << &ptr << endl;
	//같은 메모리를 가르킴

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
		ptr2는 여전히 가르키고 반납한 메모리를 가르키고 있기에 ptr2도 같이 nullptr해주는게 좋음
	*/
	ptr2 = nullptr;
	
	cout << endl;

	//----------------------------------------------------------------------
	//memory leak 메모리 누수

	/*while (true)
	{
		int* ptr = new int;
		cout << ptr << endl;

		delete ptr;
	}*/
	return 0;
}