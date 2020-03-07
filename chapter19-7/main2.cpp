#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

class CustomVector
{
public:
	unsigned int n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned int& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;

		init(_n_data, _init);
	}

	CustomVector(CustomVector& l_input)
	{
		cout << "Copy Constructor" << endl;

		init(l_input.n_data);

		for (unsigned int i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector&& r_input)
	{
		cout << "Move Constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}
	void init(const unsigned int& _n_data, const int& _init = 0)
	{
		n_data = _n_data;

		ptr = new int[n_data];

		for (unsigned int i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

void doSomething(CustomVector& vec)
{
	cout << "Pass by L-refernce" << endl;

	CustomVector new_vec(vec);
}

void doSomething(CustomVector&& vec)
{
	cout << "Pass by R-refernce" << endl;

	CustomVector new_vec(std::move(vec)); //vec가 r-value로 선언됐음에도 전달할 때 std::move가 없다면 ㅣ-value로 받아짐
										  // => vec 자체는 l-value변수라서
}

template <class T>
void doSomthingTemp(T&& vec)
{
	doSomething(std::forward<T>(vec));
}

int main()
{
	/*{
		CustomVector my_vec(10, 1024);

		CustomVector temp(std::move(my_vec));

		cout << my_vec.n_data << endl;
	}*/

	{
		CustomVector my_vec(10, 1024);

	//	doSomething(my_vec);

	//	doSomething(CustomVector(10, 8));

		doSomthingTemp(my_vec);

		doSomthingTemp(CustomVector(10, 8));
	}
	return 0;
}