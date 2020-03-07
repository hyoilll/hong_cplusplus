#include <iostream>
#include <memory>
#include <string>
#include <vector>

class A {
	std::string s;
	std::weak_ptr<A> other;

public:
	A(const std::string& s) : s(s) 
	{
		std::cout << "�ڿ��� ȹ����!" << std::endl; 
	}

	~A() 
	{
		std::cout << "�Ҹ��� ȣ��!" << std::endl; 
	}

	void set_other(std::weak_ptr<A> o) 
	{
		other = o; 
	}
	
	void access_other() 
	{
		std::shared_ptr<A> o = other.lock();
	
		if (o) 
		{
			std::cout << "���� : " << o->name() << std::endl;
		}
		else 
		{
			std::cout << "�̹� �Ҹ�� ��" << std::endl;
		}
	}

	std::string name() { return s; }
};

int main() {
	std::vector<std::shared_ptr<A>> vec;
	vec.push_back(std::make_shared<A>("�ڿ� 1"));
	vec.push_back(std::make_shared<A>("�ڿ� 2"));

	vec[0]->set_other(vec[1]);
	vec[1]->set_other(vec[0]);

	// pa �� pb �� ref count �� �״�δ�.
	std::cout << "vec[0] ref count : " << vec[0].use_count() << std::endl;
	std::cout << "vec[1] ref count : " << vec[1].use_count() << std::endl;

	// weak_ptr �� �ش� ��ü �����ϱ�
	vec[0]->access_other();

	// ���� ������ ���� ���� (vec[1] �Ҹ�)
	vec.pop_back();
	vec[0]->access_other();  // ���� ����!
}