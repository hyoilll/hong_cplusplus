/*
	람다 함수 std::function
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye(const string& s)
{
	cout << "goodbye " << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "hello " << s << endl;
	}
};

int main()
{
	auto func = [](const int& i) -> void {cout << "Hello, World" << endl; };

	func(123);

	[](const int& i) -> void {cout << "Hello, World" << endl; }(1234);

	{
		string name = "JackJack";
		[&name]() {cout << name << endl; }();
		//& : reference로 가져옴
		//= : copy로 가져옴
	}

	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);

		for_each(v.begin(), v.end(), [](const int& i) -> void {cout << i << endl; });

		for (const int& e : v)
			[](const int& i) -> void {cout << i << endl; }(e);

		//for_each : 범위안의 원소를 대상으로 하나씩 람다식에 적용
	}

	{
		auto num = []() -> int {return 1; }();
		cout << num << endl;
		cout << typeid(num).name() << endl;
	}

	{
		auto fun1 = [](int val) {cout << val << endl; };
		fun1(123);

		std::function<void(int)> fun2 = fun1;
		fun2(456);

		std::function<void(void)> fun3 = std::bind(fun2, 789);
		fun3();
	}

	{
		Object o;
		auto f1 = std::bind(&Object::hello, &o, std::placeholders::_1);

		f1(string("hi"));

		auto f2 = std::bind(&goodbye, std::placeholders::_1);

		f2(string("bye"));

		auto f3 = f2;

		f3(string("hell"));
	}

	{
		int input = 0;
		cin >> input;

		[](const int& num) {cout << "input : " << num << endl; }(input);
	}
	
	{
		cout << "multiply" << endl;

		int num1 = 0;
		int num2 = 0;
		cin >> num1 >> num2;

		auto result = [](const int& a, const int& b) -> int {return a * b; }(num1, num2);

		cout << "result : " << result << endl;
	}

	{
		int i = 5;
		cout << &i << endl;
		[&]() {cout << &i << endl; }();
	}



	return 0;
}