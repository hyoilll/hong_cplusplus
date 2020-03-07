/*
	÷�� ������ �����ε�
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

	//��ȯŸ���� int&�� ������ �ش� index�� �ּҸ� �Ѱܼ� ���԰� ����� �����ϰ� �ϱ� ����
	int& operator[](const int& index)
	{
		assert(index >= 0);
		assert(index < 10);
		//if���� assert����ϴ� ������ []�����ڴ� ���� ����ϴµ� if�� �ϰԵǸ� �ӵ��� �ʾ���

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