/*
	비트 플래그, 비트 마스크
*/

#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	//item 4
	bool item1_flag = false;
	bool item2_flag = false;
	bool item3_flag = false;
	bool item4_flag = false;

	//event get item 1
	item1_flag = true;

	//event lost item 1
	item1_flag = false;

	//open the door condition
	if (item2_flag == true)
	{
		//
	}

	//invokeEvnet(item1_flag, item2_flag, item3_flag) ... 해당 아이템이 있는지 확인하려면 매개변수가 너무 길어짐


	//bitmask
	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;
	const unsigned char opt4 = 1 << 4;
	const unsigned char opt5 = 1 << 5;
	const unsigned char opt6 = 1 << 6;
	const unsigned char opt8 = 1 << 7;

	unsigned char items_flag = 0;
	
	cout << "No item " << std::bitset<8>(items_flag) << endl;
	
	// get - item0 on
	items_flag = items_flag | opt0;

	cout << "Item0 obtained " << std::bitset<8>(items_flag) << endl;

	// get - item3 on
	items_flag = items_flag | opt3;

	cout << "Item3 obtained " << std::bitset<8>(items_flag) << endl;

	// lost - item3 off
	items_flag = items_flag & (~opt3);

	cout << "Item3 lost" << std::bitset<8>(items_flag) << endl;

	// has item1 ?
	if ((items_flag & opt1) != 0)
		cout << "Has item1 " << endl;
	else
		cout << "Has not item1" << endl;

	// get items 2, 3 on
	items_flag = items_flag | (opt2 | opt3);

	cout << bitset<8>(opt2 | opt3) << endl;
	cout << "Item 2, 3 obtained " << std::bitset<8>(items_flag) << endl;

	// get - opt1 / lost - opt2
	if (((items_flag & opt2) != 0) && ((items_flag & opt1) == 0))
	{
		items_flag = items_flag ^ (opt1 ^ opt2);
		//items_flag = items_flag ^ opt2;
	}

	cout << "Current items " << std::bitset<8>(items_flag) << endl;
	return 0;
}