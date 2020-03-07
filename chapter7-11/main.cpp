/*
	std::vactor�� ����ó�� ����ϱ�

*/

#include <iostream>
#include <vector>
using namespace std;

void printStack(const std::vector<int>& stack)
{
	for (const auto& e : stack)
		cout << e << " ";
	cout << endl;
}

int main()
{
	// int* v = new int[3]{1,2,3};
	std::vector<int> v{ 1,2,3 };
	
	/*
		new delete��ɾ�� �ӵ��� ���� �۾���.
		vector�� �� ����ϴ� ����� ���ο��� �̷������ new, delete�� ���� ���ǰ� �ϴ� ��
	*/
	
	//size, capacity
	for (const auto& element : v) // size����ŭ ��
		cout << element << " ";
	cout << endl;

	cout << v.size() << endl;				//3
	cout << v.capacity() << endl << endl;	//3

	v.resize(10);		//1 2 3 0 0 0 0 0 0 0
	//v.reserve(10);	//1 2 3
						//=> reserve(ũ�⸸ �÷����ڴ�.) / resize(�ش� ũ�⸸ŭ ����ϱ⿡ �ʱ�ȭ���� 0���� ����)

	for (const auto& element : v) // size����ŭ ��
		cout << element << " ";
	cout << endl;

	cout << v.size() << endl;				//10
	cout << v.capacity() << endl << endl;	//10

	v.resize(2);

	for (const auto& element : v) // size����ŭ ��
		cout << element << " ";
	cout << endl;

	cout << v.size() << endl;				//2
	cout << v.capacity() << endl << endl;;	//10

	//cout << v[2] << endl; runtime error => 2ĭ�� ������ resize�ߴµ� 3��° ĭ ���� �����Ϸ��� error
	//cout << v.at(2) <<endl; error

	int* ptr = v.data(); //vector�� �ּҰ� ��ȯ

	cout << ptr[2] << endl << endl;

	/*
		=> ���� new, delete����Ͽ� �����Ҵ� ���� ���� ����� �ø���, ���� �� ���ο� �޸� �Ҵ� �ް� ���� �޸𸮴�
		   �ݳ��ϰ� �Ǵµ� �̷��� ������ �ݺ��Ǹ� ���α׷��� ������ ������. �׷��� vector�� �̷��� ������ �����ϰ���,
		   resize�� �̿��Ͽ� ����� �ø� �� �ø���, ���� �� �ܼ��� ���ٸ� ���ϰ� �ؼ� �޸𸮰� �پ�� ô�� ��.
		   delete�� �ִ��� ���� �����. �ӵ� ���

		=> size, capacity�� ���̴� ���� �����ؼ�, capacity�� ó�� �޸𸮸� �Ҵ� ���� ���� ũ�⸦ ��Ÿ����, size��
		   ������ ���� ����� ������ ũ��,
		   
		   size()��, ���� ���Ϳ� ����ִ� ������ ũ�⸦ ������ �شٸ�, 
		   capacity�� �󸶸�ŭ�� ���Ұ� �� �� �ִ����� ��Ÿ�� �ش�.

		   reserve ���� ���ô�. �� ����� �� �Լ��� '�����Ѵ�'�� �� ������ ������ �ִµ���. 
		   ���ุ �� ����, ������ �ǹ��ִ� ���� ��������� �ʽ��ϴ�. �� �״��, ������ ����� ���� ���Դϴ�.

		   [����] https://chogahui05.blog.me/221362790655
	*/


	//----------------------------------------------------------
	
	//vector�� ����ó�� ���
	std::vector<int> stack;
	
	cout << stack.size() << endl;				//0
	cout << stack.capacity() << endl << endl;	//0

	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);
	
	stack.push_back(7);
	printStack(stack);

	//cout << stack.size() << endl;			//3
	//cout << stack.capacity() << endl;		//3

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	cout << stack.size() << endl;		//0
	cout << stack.capacity() << endl;	//3 capacity�� �þ ����, pop�� �ص� ������.

	/*
		vector�� stack���� ���� ����
		=> reserve�� �� ������ push�� �� capacity�� �ø� �ʿ䰡 ����, new-delete�� ȣ���� �ʿ䰡 ��� ���� ���
		   pop�� �� ������ capasity�� �״�� size�� �پ��� ���·� ����ϱ⿡ new-deleteȣ�� ����.

		=> ������ reserve�� �ʹ� ũ�� �س����� �޸𸮰� ����� �� �ִ�.
	*/

	return 0;
}