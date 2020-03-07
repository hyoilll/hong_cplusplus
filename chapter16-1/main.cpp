/*
	표준 템플릿 라이브러리와 컨테이너 소개
	Standard Template Libraries Containers
*/

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <queue>
using namespace std;

void sequence_containers()
{
	// vecotr #include <vector>
	{
		std::vector<int> vec;
		for (unsigned int i = 0; i < 10; ++i)
			vec.push_back(i);
		
		for (const auto& e : vec)
			std::cout << e << " ";
		std::cout << std::endl;
	}

	//deque #include <deque>
	{
		std::deque<int> deq;
		for (unsigned int i = 0; i < 10; ++i)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (const auto& e : deq)
			std::cout << e << " ";
		std::cout << std::endl;
	}
}

void associative_containers()
{
	//set #include <set>
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		str_set.insert("world");

		cout << str_set.size() << endl;

		for (const auto& e : str_set)
			std::cout << e << " ";
		std::cout << std::endl;
	}

	//multiset : duplication is allowed
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		str_set.insert("world");

		cout << str_set.size() << endl;

		for (const auto& e : str_set)
			std::cout << e << " ";
		std::cout << std::endl;
	}

	//map : key/value #include <map>
	{
		std::map<char, int> map;

		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;
		map.insert(std::pair<char, int>('d', 50));

		cout << map['a'] << endl;

		map['a'] = 100;
		//해당 키가 있으면 그 값을 수정해주고 키가가 없으면 새로운 키를 갖는 데이터를 추가함

		cout << map['a'] << endl;
		cout << map.size() << endl;

		for (const auto& e : map)
			std::cout << e.first << " " << e.second << " ";
		std::cout << std::endl;
	}

	//multimap : duplicated keys
	{
		std::multimap<char, int> map;

		map.insert(std::pair<char, int>('a', 10));
		map.insert(std::pair<char, int>('b', 100));
		map.insert(std::pair<char, int>('c', 1000));
		map.insert(std::pair<char, int>('a', 10000));

		cout << map.count('a') << endl;
		cout << map.size() << endl;

		for (const auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}
}

void contatiner_adapters()
{
	//stack #include <stack>
	{
		std::stack<int> stack;

		stack.push(1);		//push adds a copy
		stack.emplace(2);	//emplace constructs a new object
		stack.emplace(3);

		/*
			클래스의 기존 인스턴스를 추가하려면 push를 사용하고,
			처음부터 클래스의 새 인스턴스를 만들려면 emplace를 사용하는게 좋음.
			emplace는 객체를 만들고 넣기 때문에 push처럼 copy에 드는 비용이 없음. = > 성능이 좋음
		*/

		cout << stack.top() << endl;

		stack.pop();

		cout << stack.top() << endl;
	}

	//queue #include <queue>
	{
		std::queue<int> queue;

		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << " " << queue.back() << endl;

		queue.pop();

		cout << queue.front() << " " << queue.back() << endl;
	}

	//Priority queue 
	{
		std::priority_queue<int> queue;

		for (const int& n : { 1,8,5,6,3,4,0,9,7,2 })
			queue.push(n);

		for (unsigned int i = 0; i < 10; ++i)
		{
			cout << queue.top() << endl;
			queue.pop();
		}
	}
}

int main()
{
	//sequence_containers();

	//associative_containers();

	contatiner_adapters();

	return 0;
}