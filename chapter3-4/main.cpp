/*
	sizeof 연산자 (함수가 아님), (comma operator)쉼표 연산자, (conditional operator == 삼항연산자)조건부 연산자
*/

#include <iostream>
using namespace std;

int main()
{
	//szieof (bytes단위)

	float a = 0.0f; 

	sizeof(float);
	sizeof(a); // = sizeof a;

	//쉼표 연산자

	int x = 3;
	int y = 10;
	int z = (++x, ++y);
	/* ==
		++x;
		++y;
		int z = y;

		=> 마지막 값만 대입되는 듯
	*/

	cout << x << " " << y << " " << z << endl;

	int n1 = 1, n2 = 10;
	int n3 = 0;

	n3 = n1, n2; // 1
	n3 = (n1, n2); // 10
	//괄호의 유무에 따라 값이 달라지네?
	//,연산자의 우선순위가 대입연산자= 보다 낮음 그래서 n1의 값을 먼저 대입함 (n3 = n1), n2;

	cout << n3 << endl;
	
	//조건부 연산자

	bool onSale = true;

	int price = 0; // const int price (x) 
	
	if (onSale == true)
		price = 10;
	else
		price = 100;

	cout << price << endl;
	/* ==
		const int price = (onSale == true) ? 10 : 100; 
		if문에서는 price를 const선언할 수 없는데 삼항연산자는 const 변수에 초기화할 때 좋음 / 간단한 경우만 사용할 것
		but 굳이 if를 활용하고 싶다면 함수를 하나 만들어서 const int price = getPrice(); 이렇게 할 수도 있음
	*/

	cout << ((10 % 2 == 0) ? "짝수" : "홀수") << endl; 
	// 우선순위 때문에 에러가남 ?:연산자는 우선순위가 굉장히 낮아서 << 연산자가 먼저 실행이됨

	return 0;
}