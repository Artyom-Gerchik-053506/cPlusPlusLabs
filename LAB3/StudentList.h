// ---------------------------------------------------------------------------

#ifndef StudentListH
#define StudentListH

#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"

// ---------------------------------------------------------------------------
using namespace std;

class StudentList {
public:

	// properties
	UnicodeString name;
	UnicodeString city;

	int mark1 = 0;
	int mark2 = 0;
	int mark3 = 0;
	float avgMark = 0;

	StudentList *pointerToNextStudent; // ptr to next element

	// methods
	static StudentList *addStudent(StudentList * list, StudentList* student) {

		StudentList *currentPointer;

		currentPointer = list->pointerToNextStudent;
		list->pointerToNextStudent = student;
		student->pointerToNextStudent = currentPointer;

		return student;
	}

	static StudentList * deleteNose(StudentList *noseElement) {
		StudentList * newNose;
		newNose = noseElement->pointerToNextStudent;
		delete noseElement;
		return newNose;
	}

	static StudentList * deleteTail(StudentList *noseElement) {
		StudentList * previous = noseElement;
		StudentList * current = noseElement->pointerToNextStudent;

		while (current->pointerToNextStudent != 0) {
			previous = current;
			current = current->pointerToNextStudent;
		}

		delete current;
		previous->pointerToNextStudent = 0;
		return previous;
	}

	static void deleteStudent(StudentList* noseElement, StudentList* student) {
		StudentList* previousStudent = noseElement;
		StudentList* currentStudent = noseElement->pointerToNextStudent;

		while (currentStudent != student) {
			previousStudent = currentStudent;
			currentStudent = currentStudent->pointerToNextStudent;
		}
		previousStudent->pointerToNextStudent =
			currentStudent->pointerToNextStudent;
		delete currentStudent;
	}

};

#endif
