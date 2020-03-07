/*
	자료형 추론 auto와 decltype

	[ auto ]
	
	const, &, volatile를 다 떼버리고 자료형 추론함

	const &를 같이 추론하고 싶다면 ex) const auto&

	volatile - 값이 자주 변하기에 최적화시 빼달라는 명령어

	volatile를 같이 추론하고 싶다면 ex) volatile auto

	=> 가장 기본적인 자료형만 추론가능
*/

#include <iostream>

void ex2()
{
	int x = int();

	auto auto_x = x;

	const int& crx = x;

	auto auto_crx1 = crx;

	const auto& auto_crx2 = crx;

	volatile int vx = 1024;

	auto avx = vx;

	volatile auto vavx = vx;
}

template <class T>
void func_ex3(T arg) // -> const T& arg
{

}

void ex3()
{
	const int& crx = 123;

	func_ex3(crx);
	//const, &, volatile를 다 떼버리고 자료형 추론함
}

void ex4()
{
	const int c = 0;

	auto& rc = c;

//	rc = 123; error
}

void ex5()
{
	int i = 42;

	auto&& ri_1 = i;	//l-value
	
	auto&& ri_2 = 42;	//r-value
}

void ex6()
{
	int x = 42;

	const int* p1 = &x;

	auto p2 = p1;

	//*p2 = 42; error
}

template <class T, class S>
void func_ex7(T lhs, S rhs)
{
	auto prod1 = lhs * rhs; //어떤 값인지 auto가 추론이 불가

	typedef decltype(lhs* rhs) product_type;

	product_type prod2 = lhs * rhs;

	// == 

	decltype(lhs * rhs) prod3 = lhs * rhs;

}

template <class T, class S>
auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)
{
	return lhs * rhs;
}

void ex7_8()
{
	std::cout << typeid(func_ex8(1.0, 345)).name() << std::endl;
	func_ex8(1.2, 345);
}

struct S
{
	int m_x;

	S()
	{
		m_x = 45;
	}
};

void ex9()
{
	int x;
	const int cx = 42;
	const int& crx = x;
	const S* p = new S();

	auto a = x;
	auto b = cx;
	auto c = crx;
	auto d = p;
	auto e = p->m_x;

	typedef decltype(x)			x_type;
	typedef decltype(cx)		cx_type;
	typedef decltype(crx)		crx_type;
	typedef decltype(p->m_x)	m_x_type;	// 'declared' type

	typedef decltype((x))			x_with_parens_type;	//add references
	typedef decltype((cx))			cx_with_parens_type;
	typedef decltype((crx))			crx_with_parens_type;
	typedef decltype((p->m_x))		m_x_with_parens_type; //const까지 추가적으로 붙음
}

const S foo()
{
	return S();
}

const int& foobar()
{
	return 123;
}

#include <vector>
void ex10()
{
	std::vector<int> vect = { 42, 43 };

	auto a = foo();\
	typedef decltype(foo()) foo_type;

	auto b = foobar();
	typedef decltype(foobar()) foobar_type;

	auto itr = vect.begin();
	typedef decltype(vect.begin()) iterator_type;

	auto first_element = vect[0];
	decltype(vect[1]) second_element = vect[1]; //operator[] - return type이 reference
}

void ex11()
{
	int x = 0;
	int y = 0;
	const int cx = 42;
	const int cy = 43;
	double d1 = 3.14;
	double d2 = 2.72;

	typedef decltype(x* y) prod_xy_type;
	auto a = x * y;

	typedef decltype(cx* cy) prod_cxcy_type; // result is prvalue
	auto b = cx * cy;

	typedef decltype(d1 < d2 ? d1 : d2) cond_type; // result is lvalue. & is added
	auto c = d1 < d2 ? d1 : d2;

	typedef decltype(x < d2 ? x : d2) cond_type_mixed; // promotion of x to double
	auto d = x < d2 ? x : d2;

	//auto d = std::min(x, dbl); // error 매개변수 타입이 같아야만 작동
}

template <class T, class S> // ->뒤에 함수의 실제 리턴 타입을 지정해주는
auto fpmin_wrong(T x, S y) -> decltype (x < y ? x : y) // line 185 -> l-value 경우 &가 붙여짐
{
	return x < y ? x : y;
}

template <class T, class S>
auto fpmin(T x, S y) -> typename std::remove_reference<decltype(x < y ? x : y)>::type // 붙여진 &를 제거하기 위한 것
{
	return x < y ? x : y;
}

#include <algorithm>
void ex12()
{
	int i = 42;
	double d = 45.1;

	auto a = std::min(static_cast<double>(i), d);

	int& j = i;

	typedef decltpye(fpmin_wrong(d, d)) fpmin_return_type1;
	typedef decltpye(fpmin_wrong(i, d)) fpmin_return_type2;
	typedef decltpye(fpmin_wrong(j, d)) fpmin_return_type3;
}

void ex13()
{
	std::vector<int> vec; //empty
	typedef decltype(vec[0]); //integer 실제 수행하진 않기에 error는아님
}

template <class T>
class SomeFunctor
{
public:
	typedef R result_type;

	SomeFunctor() {}

	result_type operaotr() ()
	{
		return R();
	}
};

void ex14()
{
	SomeFunctor<int> func;
	typedef decltype(func)::result_type interger; // nested type
}

void ex15()
{
	auto lambda = []() {return 42; };

	decltype(lambda) lambda2(lambda);
	decltype((lambda)) lambda3(lambda);

	std::cout << "Lambda functions" << std::endl;
	std::cout << &lambda << " " << &lambda2 << std::endl; //다른 주소
	std::cout << &lambda << " " << &lambda3 << std::endl; //같은 주소
}

void ex16()
{
	//generic lambda
	auto lambda = [](auto x, auto y)
	{
		return x + y;
	};

	std::cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << std::endl;
}
int main()
{
	ex7_8();

	return 0;
}