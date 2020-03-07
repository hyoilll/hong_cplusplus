/*
	std::vactor를 스택처럼 사용하기

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
		new delete명령어는 속도가 느린 작업임.
		vector를 잘 사용하는 방법은 내부에서 이루어지는 new, delete가 적게 사용되게 하는 것
	*/
	
	//size, capacity
	for (const auto& element : v) // size번만큼 돔
		cout << element << " ";
	cout << endl;

	cout << v.size() << endl;				//3
	cout << v.capacity() << endl << endl;	//3

	v.resize(10);		//1 2 3 0 0 0 0 0 0 0
	//v.reserve(10);	//1 2 3
						//=> reserve(크기만 늘려놓겠다.) / resize(해당 크기만큼 사용하기에 초기화까지 0으로 해줌)

	for (const auto& element : v) // size번만큼 돔
		cout << element << " ";
	cout << endl;

	cout << v.size() << endl;				//10
	cout << v.capacity() << endl << endl;	//10

	v.resize(2);

	for (const auto& element : v) // size번만큼 돔
		cout << element << " ";
	cout << endl;

	cout << v.size() << endl;				//2
	cout << v.capacity() << endl << endl;;	//10

	//cout << v[2] << endl; runtime error => 2칸만 쓰려고 resize했는데 3번째 칸 까지 접근하려니 error
	//cout << v.at(2) <<endl; error

	int* ptr = v.data(); //vector의 주소값 반환

	cout << ptr[2] << endl << endl;

	/*
		=> 직접 new, delete사용하여 동적할당 받을 때는 사이즈를 늘리고, 줄일 때 새로운 메모리 할당 받고 기존 메모리는
		   반납하게 되는데 이러한 과정이 반복되면 프로그램이 굉장히 느려짐. 그래서 vector는 이러한 단점을 보완하고자,
		   resize를 이용하여 사이즈를 늘릴 땐 늘리고, 줄일 땐 단순히 접근만 못하게 해서 메모리가 줄어든 척을 함.
		   delete를 최대한 적게 사용함. 속도 향상

		=> size, capacity의 차이는 쉽게 생각해서, capacity는 처음 메모리를 할당 받을 때의 크기를 나타내고, size는
		   실제로 내가 사용할 데이터 크기,
		   
		   size()가, 실제 벡터에 들어있는 원소의 크기를 리턴해 준다면, 
		   capacity는 얼마만큼의 원소가 들어갈 수 있는지를 나타내 준다.

		   reserve 먼저 봅시다. 한 마디로 이 함수는 '예약한다'는 뜻 정도를 가지고 있는데요. 
		   예약만 해 놓지, 실제로 의미있는 값을 집어넣지는 않습니다. 말 그대로, 공간만 만들어 놓을 뿐입니다.

		   [참고] https://chogahui05.blog.me/221362790655
	*/


	//----------------------------------------------------------
	
	//vector를 스택처럼 사용
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
	cout << stack.capacity() << endl;	//3 capacity가 늘어나 있음, pop을 해도 유지함.

	/*
		vector가 stack으로 좋은 이유
		=> reserve를 해 놓으면 push할 때 capacity를 늘릴 필요가 없음, new-delete를 호출할 필요가 없어서 성능 향상
		   pop을 할 때에도 capasity는 그대로 size만 줄어드는 형태로 사용하기에 new-delete호출 안함.

		=> 단점은 reserve를 너무 크게 해놓으면 메모리가 낭비될 수 있다.
	*/

	return 0;
}