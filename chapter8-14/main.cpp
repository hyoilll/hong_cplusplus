/*
	Ŭ���� �ȿ� ���Ե� �ڷ��� nested types

	�ش� Ŭ���������� ����ϰ� �ٸ� ������ ������ ���� ��
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