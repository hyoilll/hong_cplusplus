/*
	템플릿을 부분적으로 특수화하기
*/

#include <iostream>

using namespace std;

template <class T, int size>
class StaticArray
{
private:
	T m_arr[size];

public:
	StaticArray<T, size>() {}

	T* getArray() { return m_arr; }

	T& operator[](const int index)
	{
		return m_arr[index];
	}

	void print();
};

template <class T, int size>
void StaticArray<T, size>::print()
{
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << m_arr[i] << " ";
	}
	cout << endl;
}

// 멤버함수의 특수화는 상속을 통해서 구현하면 손쉽게 구현 가능.
template <class T, int size>
class StaticArray_Der : public StaticArray<T, size>
{
public:
	StaticArray_Der<T,size>() :StaticArray<T, size>() {}
};

template <int size>
class StaticArray_Der<char, size> : public StaticArray<char, size>
{
public:
	void print()
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			//if protected
			//std::cout << StaticArray<char, size>::m_arr[i];

			//if private
			//std::cout << (*this)[i];
			std::cout<<(*this).operator[](i);
		}
		cout << endl;

		cout << this << endl;
	}

};

/*
전역함수 부분적 특수화

template <class T, int size>
void print(StaticArray<T, size>& arr)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	cout << endl;
}

template <int size>
void print(StaticArray<char, size>& arr)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << arr[i];
	}
	cout << endl;
}
*/

int main()
{
	StaticArray_Der<int, 4> int4;

	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;
	
	//print(int4);

	int4.print();

	StaticArray_Der<char, 14> char14;

	strcpy_s(char14.getArray(),14,"Hello, world");

	char14.print();

	cout << &char14 << endl;

	return 0;
}