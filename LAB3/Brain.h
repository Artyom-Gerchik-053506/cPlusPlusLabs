// ---------------------------------------------------------------------------

#ifndef BrainH
#define BrainH
#include "StudentList.h"
#include <string.h>

class Brain {

private:
	StudentList* noseElement;
	StudentList* tailElement;

public:

	UnicodeString sortName;
	UnicodeString sortCity;

	float sortAvgMark = -1; // -1 - default value means no filtering

	Brain() {
	}

	int numberOfStudents() {
		int numberOfStudents = 0;
		if (noseElement != 0) {
			numberOfStudents++;
			StudentList* temp = noseElement;
			while (temp->pointerToNextStudent != 0) {
				numberOfStudents++;
				temp = temp->pointerToNextStudent;
			}
		}
		return numberOfStudents;
	}

	bool isThisStudentMatchesUIConditions(StudentList* student) {
		if (sortName != "") {
			wchar_t * pch;
			pch = wcsstr(student->name.c_str(), sortName.c_str());
			if (pch == NULL) {
				return false;
			}

		}

		if (sortCity != "") {
			wchar_t * pch;
			pch = wcsstr(student->city.c_str(), sortCity.c_str());
			if (pch == NULL) {
				return false;
			}
		}

		if (sortAvgMark != -1) {

			if (student->avgMark < sortAvgMark) {
				return false;
			}

		}
		return true;

	}

	StudentList* studentAtIndexForUI(int indexForSearch) {
		int currentIndex = 0;

		StudentList* temp = noseElement;
		// searching for first matching student for index == 0;
		//virtualli getting new nose for temp UI;
		while (!isThisStudentMatchesUIConditions(temp)) {
			temp = temp->pointerToNextStudent;
		}
		// searching for proper index;
		while (currentIndex != indexForSearch) {
			temp = temp->pointerToNextStudent;
			// searching for first matching student for currentIndex;
			while (!isThisStudentMatchesUIConditions(temp)) {
				temp = temp->pointerToNextStudent;
			}
			currentIndex++;
		}
		return temp;
	}

	int numberOfStudentsForUI() {
		int numberOfStudentsForUI = 0;

		if (noseElement != 0) {
			if (isThisStudentMatchesUIConditions(noseElement)) {
				numberOfStudentsForUI++;
			}

			StudentList* temp = noseElement->pointerToNextStudent;

			while (temp != 0) {
				if (isThisStudentMatchesUIConditions(temp)) {
					numberOfStudentsForUI++;
				}
				temp = temp->pointerToNextStudent;

			}

		}

		return numberOfStudentsForUI;
	}

	StudentList* studentAtIndex(int indexForSearch) {
		int currentIndex = 0;
		StudentList* temp = noseElement;
		while (currentIndex != indexForSearch) {
			currentIndex++;
			temp = temp->pointerToNextStudent;
		}

		return temp;
	}

	void addStudent(StudentList* student) {
		if (tailElement != 0) {
			tailElement = StudentList::addStudent(tailElement, student);
		}
		else {
			noseElement = student;
			tailElement = student;
		}
	}

	void deleteStudent(StudentList* studentToDelete) {
		if (studentToDelete == noseElement) {
			noseElement = StudentList::deleteNose(noseElement);
			if (noseElement == NULL) {
				tailElement = NULL;
			}
		}
		else if (studentToDelete == tailElement) {
			tailElement = StudentList::deleteTail(noseElement);
		}
		else {
			StudentList::deleteStudent(noseElement, studentToDelete);
		}
	}

	void deleteStudentsWithMarkLowerThanAVG(float minimalAvg) {
		StudentList* studentsArray[numberOfStudents() + 1];
		int studentsArrayIndex = 0;

		for (int index = 0; index < numberOfStudents(); index++) {

			StudentList* tempStudent = studentAtIndex(index);

			float tempStudentAvg = tempStudent->avgMark;

			if (minimalAvg > tempStudentAvg) {
				studentsArray[studentsArrayIndex] = tempStudent;
				studentsArrayIndex++;

			}
		}

		for (int index = 0; index < studentsArrayIndex; index++) {
			deleteStudent(studentsArray[index]);
		}
	}

	~Brain() {
	}

};
// ---------------------------------------------------------------------------
#endif
