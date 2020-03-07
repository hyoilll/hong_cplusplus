#include "MyArray.h"

template <class T>
void MyArray<T>::print()
{
	for (unsigned int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

//template class MyArray<char>;			//class자체를 link
template void MyArray<char>::print();	//function각각을 link