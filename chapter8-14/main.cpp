/*
	클래스 안에 포함된 자료형 nested types

	해당 클래스에서만 사용하고 다른 곳에선 쓰이지 않을 떄
*/

#include <iostream>
using namespace std;

/*
enum class FruitType
{
	APPLE,
	BANANA,
	CHERRY,
};
*/

class Fruit
{
public:
	enum class FruitType
	{
		APPLE,
		BANANA,
		CHERRY,
	};

	class InnerClass
	{

	};

	struct InnerSturct
	{

	};

private:
	FruitType m_type;

public:
	Fruit(FruitType type) : m_type(type) {}

	FruitType getType()const { return m_type; }
};

int main()
{
	/*Fruit apple(FruitType::APPLE);

	if (apple.getType() == FruitType::APPLE)
	{
		std::cout << "Apple" << std::endl;
	}*/

	//----------------------------------------------------------

	//nested enum class
	Fruit apple(Fruit::FruitType::APPLE);

	if (apple.getType() == Fruit::FruitType::APPLE)
	{
		std::cout << "Apple" << std::endl;
	}

	return 0;
}