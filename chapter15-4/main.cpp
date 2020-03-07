/*
	std::move
*/

#include "AutoPtr.h"
#include "Resource.h"
#include <vector>
#include <string>

using namespace std;

template <class T>
void MySwap(T& a, T& b)//std::swap
{
	/*T temp = a;
	a = b;
	b = temp;*/

	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

int main()
{
	/*{
		AutoPtr<Resource> res1(new Resource(100000000));

		cout << res1.m_ptr << endl;

		//AutoPtr<Resource> res2 = res1; 복사생성자
		AutoPtr<Resource> res2 = std::move(res1); //std::movd()의 반환 값으로 r-vlaue값으로 반환됨 / res1은 이제 죽은 변수
		
		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}*/

	{
		AutoPtr<Resource> res1(new Resource(3));
		res1->setAll(3);

		AutoPtr<Resource> res2(new Resource(5));
		res2->setAll(5);

		res1->print();
		res2->print();

		MySwap(res1, res2);
		
		res1->print();
		res2->print();
	}

	{
		vector<string> v;
		string str = "hello";

		v.push_back(str);

		cout << str << endl;
		cout << v[0] << endl;

		v.push_back(std::move(str)); //str소유권 박탈, r-value로 받아들임

		cout << str << endl;
		cout << v[0] << " " << v[1] << endl;
	}

	{
		string x = "abc";
		string y = "de";

		cout << "x : " << x << endl;
		cout << "y : " << y << endl;

		MySwap(x, y);

		cout << "x : " << x << endl;
		cout << "y : " << y << endl;

	}
	return 0;
}