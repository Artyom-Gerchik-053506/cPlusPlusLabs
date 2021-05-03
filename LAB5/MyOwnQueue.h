// ---------------------------------------------------------------------------

#ifndef MyOwnQueueH
#define MyOwnQueueH

#include "MyOwnList.h"

class MyOwnQueue : public MyOwnList {

protected:
	MyOwnList* noseElement = nullptr;
	MyOwnList* tailElement = nullptr;

public:

	void Push(MyOwnList* elementToAdd) {

		tailElement = this->addElement(tailElement, elementToAdd);
		if (noseElement == nullptr) {
			noseElement = tailElement;
		}
	}

	void Pop() {
		noseElement = this->deleteNose(noseElement);
		if(noseElement == nullptr){
		tailElement = nullptr;
		}
	}

	UnicodeString Content() {
		return outputList(noseElement);
	}

	int Size() {
		int size = 0;
		MyOwnList* localNose = noseElement;
		while (localNose != nullptr) {
			localNose = localNose->pointerToNextElement;
			size++;
		}
		return size;
	}

	bool Empty() {
		return noseElement == nullptr;
	}

	int Peek() {
		return noseElement->anyNumber;
	}

};

// ---------------------------------------------------------------------------
#endif
