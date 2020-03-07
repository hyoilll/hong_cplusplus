/*
	첨자 연산자 오버로딩
*/

#include <iostream>
#include <cassert>

using namespace std;

class IntList
{
private:
	int m_list[10];

public:
	void setItem(const int index, const int value)
	{
		m_list[index] = value;
	}

	int getItem(const int index)const
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;
	}

	//반환타입이 int&인 이유는 해당 index의 주소를 넘겨서 대입과 출력을 가능하게 하기 위해
	int& operator[](const int& index)
	{
		assert(index >= 0);
		assert(index < 10);
		//if말고 assert사용하는 이유는 []연산자는 많이 사용하는데 if를 하게되면 속도가 늦어짐

		return m_list[index];
	}
	
};

int main()
{
	IntList list;
	list.setItem(3, 1);
	cout << list.getItem(3) << endl;

	*(list.getList() + 3) = 10;
	cout << *(list.getList() + 3) << endl;
	/*
		==
		list.getList()[3] = 10;
		cout << list.getList()[3]<<endl;
	*/

	//----------------------------------------------------------

	int& temp = list[3];
	temp = 100;
	// ==	list[3] = 100;

	cout << list[3] << endl;
	
	//----------------------------------------------------------

	IntList* pList = new IntList;

	pList->operator[](3) = 1000;
	cout << pList->operator[](3) << endl;

	//pList[3] x
	(*pList)[3] = 10000;
	cout << (*pList)[3] << endl;


	delete pList;
	return 0;
}