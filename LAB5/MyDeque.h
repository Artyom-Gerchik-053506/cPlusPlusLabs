// ---------------------------------------------------------------------------

#ifndef MyDequeH
#define MyDequeH

#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"

#include <vcl.h>

class node {
public:

	int anyValue = 0;
	node* nextNode;
	node* previousNode;

};

class MyDeque {
private:

	node *noseElement = nullptr; // right
	node *tailElement = nullptr; // left
	int dequeSize = 0;

public:

	UnicodeString showContent() {
		UnicodeString dequeContent;
		node* localTail = tailElement;
		while (localTail != nullptr) {
			dequeContent += localTail->anyValue;
			localTail = localTail->nextNode;
		}
		return dequeContent;

	}

	bool isEmpty() {
		return dequeSize == 0;
	}

	int size() {
		return dequeSize;
	}

	void push_left(int value) {

		node *nodeToPush = new node;
		nodeToPush->anyValue = value;

		if (dequeSize == 0) {
			noseElement = tailElement = nodeToPush;
			nodeToPush->nextNode = nullptr;
			nodeToPush->previousNode = nullptr;
		}
		else {
			tailElement->previousNode = nodeToPush;
			nodeToPush->nextNode = tailElement;
			tailElement = nodeToPush;
			nodeToPush->previousNode = nullptr;
		}

		dequeSize++;
	}

	void pop_left() {
		if (!isEmpty()) {
			if (dequeSize == 1) {
				delete tailElement;
				noseElement = nullptr;
				tailElement = nullptr;
			}
			else {
				node *nodeToPop = new node;

				nodeToPop = tailElement;
				tailElement = tailElement->nextNode;
				tailElement->previousNode = nullptr;

				delete nodeToPop;
			}

			dequeSize--;
		}
		else {
			ShowMessage("pop_left unavailable. deque empty.");
		}

	}

	void peek_left() {
		if (!isEmpty()) {
			ShowMessage(tailElement->anyValue);
		}
		else {
			ShowMessage("peek_left unavailable. deque empty.");
		}
	}

	void push_right(int value) {

		node *nodeToPush = new node;
		nodeToPush->anyValue = value;

		if (dequeSize == 0) {
			noseElement = tailElement = nodeToPush;
			nodeToPush->nextNode = nullptr;
			nodeToPush->previousNode = nullptr;
		}
		else {
			nodeToPush->previousNode = noseElement;
			noseElement->nextNode = nodeToPush;
			nodeToPush->nextNode = nullptr;
			noseElement = nodeToPush;
		}

		dequeSize++;

	}

	void pop_right() {
		if (!isEmpty()) {
			if (dequeSize == 1) {
				delete noseElement;
				noseElement = nullptr;
				tailElement = nullptr;
			}
			else {
				node *nodeToPop = new node;

				nodeToPop = noseElement;
				noseElement = noseElement->previousNode;
				noseElement->nextNode = nullptr;

				delete nodeToPop;
			}

			dequeSize--;
		}
		else {
			ShowMessage("pop_right unavailable. deque empty.");
		}

	}

	void peek_right() {
		if (!isEmpty()) {
			ShowMessage(noseElement->anyValue);
		}
		else {
			ShowMessage("peek_right unavailable. deque empty.");
		}
	}

	void performMyTask() {

		node* localTail = new node;
		node* previousLocal = new node;
		node* nextLocal = new node;

		localTail = tailElement;
		previousLocal = localTail->previousNode;
		nextLocal = localTail->nextNode;

		while (localTail != nullptr) {
			if (localTail->anyValue < 0) {
				if (previousLocal == nullptr) {
					ShowMessage(localTail->anyValue);
					nextLocal->previousNode = previousLocal;
					tailElement = localTail->nextNode;
					delete localTail;
					dequeSize--;
				}
				else if (nextLocal == nullptr) {
					ShowMessage(localTail->anyValue);
					previousLocal->nextNode = nextLocal;
					noseElement = localTail->previousNode;
					delete localTail;
					dequeSize--;
				}
				else {
					ShowMessage(localTail->anyValue);
					nextLocal->previousNode = previousLocal;
					previousLocal->nextNode = nextLocal;
					delete localTail;
					dequeSize--;
				}
			}
			localTail = localTail->nextNode;
			if (localTail != nullptr) {
				previousLocal = localTail->previousNode;
				nextLocal = localTail->nextNode;
			}
		}

	}

};

// ---------------------------------------------------------------------------
#endif
