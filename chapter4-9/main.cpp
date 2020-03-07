/*
	�ڷ��� ���� ���̱� (Type aliases)
*/

#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
	typedef double distance_t;

	std::int8_t i(97); // == typedef double

	//���� ���� 2���� Ÿ�� (����)
	double my_distance = 0.0;
	distance_t home2work = 0.0;
	
	/*
		���� ���߿� distance�� ��Ÿ���� ������ �ڷ����� 
		double > float�� ���� �Ǹ� typedef�����ϸ� ���� ���� ���� = ���������� ���� 
	*/

	//---------------------------------------------------------------------

	using namespace std;

	vector<pair<string, int>> pairlist1;
	vector<pair<string, int>> pairlist2;
	vector<pair<string, int>> pairlist3;

	typedef vector<pair<string, int>> pairlist_t;
	// == using pairlist_t = vector<pair<string, int>>; '�����Ϸ����� �̷� ������ ���̰ڴ�' ��� �޼���

	pairlist_t pairlist4;
	pairlist_t pairlist5;

	//�� �� �������

	return 0;
}