// ---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH
#include "MainUnit.h"

class Password {
private:
	int ID;
	String description;
	String password;

public:
	Password* nextElement = nullptr;

	Password(int IDInput, String descriptionInput, String passwordInput)
		: ID(IDInput), description(descriptionInput), password(passwordInput) {
	};

	int GetID(Password* element) {
		return element->ID;
	}

	String GetDescription(Password* element) {
		return element->description;
	}

	String GetPassword(Password* element) {
		return element->password;
	}

	void SetDescription(String description) {
		this->description = description;
	}

	void SetPassword(String password) {
		this->password = password;
	}

};

class PasswordList {
protected:
	int count;

	Password* head = nullptr;
	Password* tail = nullptr;

public:

	PasswordList() : count(0) {
	};

	Password* getHead() {
		Password* temp = head;
		return temp;
	}

	void addPassword(Password* numberToAdd) {

		if (!head) {
			head = numberToAdd;
		}
		else {
			tail->nextElement = numberToAdd;
		}
		tail = numberToAdd;
		this->count++;
	}

	Password* Search(int IDToSearch) {
		Password* kursor = head;
		while (kursor) {
			if (kursor->GetID(kursor) == IDToSearch) {
				return kursor;
			}
			kursor = kursor->nextElement;
		}
		return nullptr;
	}

	void Remove() {
		Password* kursor = head;
		Password* oldTail;

		if (!kursor) {
			return;
		}
		if (kursor == tail) {
			oldTail = kursor;
			delete oldTail;
			head = nullptr;
			tail = nullptr;
			count--;
		}
		while (kursor->nextElement) {
			if (kursor->nextElement == tail) {
				oldTail = tail;
				tail = kursor;
				tail->nextElement = nullptr;
				delete oldTail;
				count--;
				break;
			}
			kursor = kursor->nextElement;
		}
	}

	void Search() {

		if (tail) {
			String Output;
			Output += "|KEY: ";
			Output += tail->GetID(tail);
			Output += ", Description: ";
			Output += tail->GetDescription(tail);
			Output += ", Password: ";
			Output += tail->GetPassword(tail);
			Output += "| ";
			ShowMessage(Output);
		}
		else {
			return;
		}

		// Password* kursor = head;
		// Password* oldTail;
		//
		//
		// if (!kursor) {
		// return;
		// }
		// if (kursor == tail) {
		// Output += "|KEY: ";
		// Output += kursor->ID;
		// Output += ", Description: ";
		// Output += kursor->description;
		// Output += ", Password: ";
		// Output += kursor->password;
		// Output += "| ";
		// ShowMessage(Output);
		// }
		// while (kursor->nextElement) {
		// if (kursor->nextElement == tail) {
		// oldTail = tail;
		//
		// break;
		// }
		// kursor = kursor->nextElement;
		// }
	}

	int GetCount() {
		return this->count;
	}

	~PasswordList();
};

class PasswordListHashTable {
private:
	int tableSize;
	int tableCount;
	PasswordList** items;

public:

	PasswordListHashTable(int tableSize) {
		this->tableSize = tableSize;
		this->tableCount = 0;

		items = (PasswordList * *)malloc(tableSize*sizeof(PasswordList*));
		for (int index = 0; index < tableSize; index++) {
			PasswordList* passwordList = new PasswordList();
			items[index] = passwordList;
		}
	};

	int calculateHash(int ID) {

		return ID % tableSize;
	}

	void insertElement(int IDToAdd, String descriptionToAdd,
		String passwordToAdd) {

		if (tableCount == tableSize) {
			ShowMessage("tableSize == tableCount ? :)");
			return;
		}
		int indexToInsert = calculateHash(IDToAdd);

		PasswordList* passwordList = items[indexToInsert];

		Password* existingPassword = passwordList->Search(IDToAdd);
		if (existingPassword) {
			existingPassword->SetDescription(descriptionToAdd);
			existingPassword->SetPassword(passwordToAdd);
		}
		else {
			if (passwordList->GetCount() == 0) {
				this->tableCount++;
			}

			Password *newPassword = new Password(IDToAdd, descriptionToAdd,
				passwordToAdd);
			passwordList->addPassword(newPassword);
		}
	}

	String Print(int index) {
		String Output;

		Password* temp = items[index]->getHead();

		Output += index;
		Output += "(";
		Output += items[index]->GetCount();
		Output += ")";
		Output += ": ";

		for (int counter = 0; counter < items[index]->GetCount(); counter++) {
			Output += " ";
			Output += "|KEY: ";
			Output += temp->GetID(temp);
			Output += ", Description: ";
			Output += temp->GetDescription(temp);
			Output += ", Password: ";
			Output += temp->GetPassword(temp);
			Output += "| ";
			temp = temp->nextElement;
		}
		return Output;
	}

	float calculateNumberOfElements() {
		float count = 0;
		for (int index = 0; index < tableSize; index++) {
			count += items[index]->GetCount();
		}
		return count;
	}

	float calculateSumOfKeys() {
		float sum = 0;
		for (int index = 0; index < tableSize; index++) {
			Password* temp = items[index]->getHead();
			while (temp) {
				sum += temp->GetID(temp);
				temp = temp->nextElement;
			}
		}
		return sum;
	}

	float calculateAVG() {
		if (calculateNumberOfElements() != 0) {
			return calculateSumOfKeys() / calculateNumberOfElements();
		}
		else {
			return 0;
		}
	}

	int countKeysWichBiggerThanAVG() {
		int count = 0;
		float AVG = calculateAVG();
		for (int index = 0; index < tableSize; index++) {
			Password* temp = items[index]->getHead();
			while (temp) {
				if (temp->GetID(temp) > AVG) {
					count++;
				}
				temp = temp->nextElement;
			}
		}
		return count;
	}

	void Remove(int Key) {
		int index = calculateHash(Key);
		PasswordList* passToDelete = items[index];
		passToDelete->Remove();
	}

	void Search(int Key) {
		int index = calculateHash(Key);
		PasswordList* passToSearch = items[index];
		passToSearch->Search();
	}

	~PasswordListHashTable() {
		free(items);
	};
};

// ---------------------------------------------------------------------------
#endif
