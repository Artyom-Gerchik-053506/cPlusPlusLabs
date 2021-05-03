// ---------------------------------------------------------------------------

#ifndef MyOwnListH
#define MyOwnListH

#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"

// ---------------------------------------------------------------------------
using namespace std;

class MyOwnList {
public:
	// properties
		int anyNumber = 0;

	MyOwnList *pointerToNextElement = nullptr; // ptr to next element

	// methods
	static MyOwnList* addElement(MyOwnList * list, MyOwnList* element) {

		if (list != nullptr) {
			list->pointerToNextElement = element;
		}
		return element;
	}

	static MyOwnList * deleteNose(MyOwnList *noseElement) {
		MyOwnList * newNose;
		newNose = noseElement->pointerToNextElement;
		delete noseElement;
		return newNose;
	}

	static MyOwnList * deleteTail(MyOwnList *noseElement) {
		MyOwnList * previous = noseElement;
		MyOwnList * current = noseElement->pointerToNextElement;

		while (current->pointerToNextElement != 0) {
			previous = current;
			current = current->pointerToNextElement;
		}

		delete current;
		previous->pointerToNextElement = 0;
		return previous;
	}

	static void deleteElement(MyOwnList* noseElement, MyOwnList* element) {
		MyOwnList* previousElement = noseElement;
		MyOwnList* currentElement = noseElement->pointerToNextElement;

		while (currentElement != element) {
			previousElement = currentElement;
			currentElement = currentElement->pointerToNextElement;
		}
		previousElement->pointerToNextElement =
			currentElement->pointerToNextElement;
		delete currentElement;
	}

	static UnicodeString outputList(MyOwnList* noseElement) {
		UnicodeString listContent;
		MyOwnList* localNose = noseElement;
		while (localNose != nullptr) {
			listContent += localNose->anyNumber;
			localNose = localNose->pointerToNextElement;
		}

		return listContent;

	}

};

// ---------------------------------------------------------------------------
#endif
