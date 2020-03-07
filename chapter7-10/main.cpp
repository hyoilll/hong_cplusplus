/*
	Stack vs Heap
*/

#include <iostream>
using namespace std;

int main()
{
	/*
		메모리 구조

		Heap
		 - '힙(heap) 메모리'의 '힙'은 '힙 자료구조와'는 상관없음
		 - 사이즈가 큼
		 - 스택은 연속적으로 메모리에 쌓이지만, 힙은 메모리의 어느 구간에 잡힐지 알 수 없음.
			큰 데이터를 한꺼번에 넣을 수 있는 메모리 주소를 찾기 때문에 다른 변수들과 연속적일 수 없음.
		 - 메모리 누수
			사용 한 메모리는 반납해야 하는데 반납을 안하고 계속적으로 할당만 받게 되면 heap의 사이즈가 꽉차
			더 이상 할당 받을 수 없는 상황에 이르게 됨.
		Stack
		 - 지역 변수
		 - 현재 실행 시켜야 하는 것이 가장 위에 있기에 비교적 속도가 빠름.
		 - 사이즈가 작음
			ex) 스텍의 사이즈 보다 큰 정적배열을 할당할 경우 stack overflow발생
			ex) 재귀함수의 stack overflow도 마찬가지
		
		Data
		 - initialized data segement
		 - Initialized global and static variables

		BSS(Block started by symbol)
		 - uninitialized data segement
		 - Zero-Initialized global and static variables

		Code
	*/
	return 0;
}