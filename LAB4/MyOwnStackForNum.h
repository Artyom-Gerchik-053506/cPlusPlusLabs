//---------------------------------------------------------------------------

#ifndef MyOwnStackForNumH
#define MyOwnStackForNumH
//---------------------------------------------------------------------------
#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"

class MyOwnStackForNum {
private:

	float *nums;

	int capacity = 0;
	int top = 0;

public:

	bool isStackFull() {
		return top == capacity - 1;
	}

	bool isStackEmpty() {
		return top == -1;
	}

	int stackSize() {
		return top + 1;
	}

	void performStack(int size) {
		top = -1;
		capacity = size;
		nums = new float[size];

	}

	void push(float numToPush) {
		if (isStackFull()) {
			return;
		}
		else {
			top++;
			nums[top] = numToPush;
		}

	}

	float pop() {
		if (isStackEmpty()) {
			return NULL;
		}
		else {
			return nums[top--];

		}
	}

	float peek() {
		if (isStackEmpty()) {
			return NULL;
		}
		else {
			return nums[top];
		}

	}

    void clearMemory() {
		delete[]nums;
	}
};

#endif
