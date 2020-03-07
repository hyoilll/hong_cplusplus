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
		a.m_ptr = nullptr; //������ ptr������ nullptr���ִ°� ������. ������ ������ �̵�

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
			l-value�̱� ������ �ٸ� ���� ������ ���� �����Ƿ� deep copy�� �ʿ����, shallow copy�� �ص� ������.
			�ӵ� ���.
			������ ptr������ nullptr���ִ°� ������. ������ ������ �̵�
		*/

		return *this;

	}

	T& operator*()const { return *m_ptr; }
	T* operator->()const { return m_ptr; }
};