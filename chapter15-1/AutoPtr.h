#pragma once


template <class T>
class AutoPtr
{
public:
	T* m_ptr;

public:
	AutoPtr(T* const ptr_i = nullptr) :m_ptr(ptr_i) {}
	
	~AutoPtr() 
	{
		if (m_ptr != nullptr)
			delete m_ptr;
	}
	
	AutoPtr(AutoPtr& a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	//res3 = res2 = res1 ��ó�� ���� ȣ���� ���� return *this, AutoPtr&�� ��ȯ��.
	AutoPtr& operator = (AutoPtr& a)
	{
		if (&a == this)
			return *this;

		delete m_ptr;

		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	
};