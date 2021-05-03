// ---------------------------------------------------------------------------

#ifndef MyOwnStackH
#define MyOwnStackH
// ---------------------------------------------------------------------------

#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"

class MyOwnStack {
private:

	UnicodeString *chars;

	int capacity = 0;
	int top = 0;

public:

	// MyOwnStack() {
	// this->top = -1;
	// };

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
		chars = new UnicodeString[size];

	}

	void push(UnicodeString charToPush) {
		if (isStackFull()) {
			return;
		}
		else {
			top++;
			chars[top] = charToPush;
		}

	}

	UnicodeString pop() {
		if (isStackEmpty()) {
			return NULL;
		}
		else {
			return chars[top--];

		}
	}

	UnicodeString peek() {
		if (isStackEmpty()) {
			return NULL;
		}
		else {
			return chars[top];
		}

	}

	UnicodeString viewStack() {
		UnicodeString test;
		if (isStackEmpty()) {
			return NULL;
		}
		else {

			for (int index = 0; index < top + 1; index++) {
				test = test + chars[index];
			}
		}
		return test;

	}

	void clearMemory() {
		delete[]chars;
	}

	// ~MyOwnStack() {

	// };
};

#endif
