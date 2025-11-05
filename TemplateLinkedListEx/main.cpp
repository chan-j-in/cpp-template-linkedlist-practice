#include <iostream>
#include "CLinkedList.h"

using namespace std;

int main() {
	CLinkedList<int> listInt;
	CLinkedList<float> listFloat;

	cout << listInt.getSize() << endl;
	return 0;
}