#include <iostream>
#include "CLinkedList.h"

using namespace std;

int main() {
	CLinkedList<int> listInt;
	CLinkedList<float> listFloat;

	CLinkedList<int>::iterator iter;
	CLinkedList<int>::riterator riter;

	for (int i = 0; i < 100; i++) {
		listInt.push_back(i + 1);
	}

	cout << listInt.getSize() << endl;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter) {
		cout << *iter << endl;
	}

	cout << "==================" << endl;
	for (riter = listInt.rbegin(); riter != listInt.rend(); ++riter) {
		cout << *riter << endl;
	}
	return 0;
}