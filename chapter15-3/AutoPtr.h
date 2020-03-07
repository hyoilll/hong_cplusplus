#pragma once


template <class T>
class AutoPtr
{
private:
	T* m_ptr;

public:
	AutoPtr(T* const ptr = nullptr) : m_ptr(ptr)
	{
		std::cout << "AutoPtr defalut constructor" << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;

		if (m_ptr != nullptr)
			delete m_ptr;
	}

	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		//deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	AutoPtr& operator=(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment" << std::endl;

		if (this == &a)
			return *this;

		if (m_ptr != nullptr)
			delete m_ptr;

		//deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	AutoPtr(AutoPtr&& a) : m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; //기존의 ptr변수는 nullptr해주는게 안전함. 완전한 소유권 이동

		std::cout << "AutoPtr move constructor" << std::endl;
	}

	AutoPtr& operator=(AutoPtr&& a)
	{
		std::cout << "AutoPtr move assignment" << std::endl;
		
		if (this == &a)
			return *this;

		if (m_ptr != nullptr)
			delete m_ptr;

		//shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		/*
			l-value이기 때문에 다른 곳에 영향을 주지 않으므로 deep copy할 필요없이, shallow copy를 해도 무방함.
			속도 향상.
			기존의 ptr변수는 nullptr해주는게 안전함. 완전한 소유권 이동
		*/

		return *this;

	}

	T& operator*()const { return *m_ptr; }
	T* operator->()const { return m_ptr; }
};