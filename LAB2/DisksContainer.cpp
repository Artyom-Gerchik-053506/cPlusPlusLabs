// ---------------------------------------------------------------------------

#pragma hdrstop

#include "DisksContainer.h"
#include <vcl.h>
#include "SysUtils.hpp"
#include <string.h>
// #include<bits/stdc++.h>

// ---------------------------------------------------------------------------
#pragma package(smart_init)

int DisksContainer::Count() {
	return countOfDisks;
}

void DisksContainer::sortByType() {
	for (int firstIndex = 0; firstIndex < countOfDisks; firstIndex++) {
		Disk* disk = disksArray[firstIndex];
		for (int secondIndex = firstIndex; secondIndex < countOfDisks;
		secondIndex++) {

			Disk* diskTest = disksArray[secondIndex];

			if (disk->typeOfDisk > diskTest->typeOfDisk) {
				Disk* temp;
				temp = disk;
				disk = diskTest;
				diskTest = temp;
				disksArray[firstIndex] = disk;
				disksArray[secondIndex] = diskTest;

			}

		}
	}

}

Ranges* DisksContainer::detectRanges() {
	int rangeStartingPos = 0;
	int rangesLenght = 0;

	Range* rangesArray = new Range[countOfDisks];

	Disk* localDisk = disksArray[rangeStartingPos];
	UnicodeString currentType = localDisk->typeOfDisk;

	for (int index = 0; index < countOfDisks; index++) {
		Disk* disk = disksArray[index];

		if (disk->typeOfDisk != currentType) {
			currentType = disk->typeOfDisk;
			Range currentRange;
			currentRange.begin = rangeStartingPos;
			currentRange.end = index - 1;
			rangeStartingPos = index;
			rangesArray[rangesLenght] = currentRange;
			rangesLenght++;
		}
	}

	Range closingRange;
	closingRange.begin = rangeStartingPos;
	closingRange.end = countOfDisks - 1;
	rangesArray[rangesLenght] = closingRange;
	rangesLenght++;

	Ranges* ranges = new Ranges;
	ranges->lenght = rangesLenght;
	ranges->rangesArray = rangesArray;
	return ranges;
}

void DisksContainer::sortByAuthorInRanges(Ranges* ranges) {
	for (int index = 0; index < ranges->lenght; index++) {
		Range currentRange = ranges->rangesArray[index];
		sortByAuthorInRange(currentRange);
	}

}

void DisksContainer::sortByAuthorInRange(Range range) {
	for (int firstIndex = range.begin; firstIndex <= range.end; firstIndex++) {
		Disk* disk = disksArray[firstIndex];
		for (int secondIndex = firstIndex; secondIndex <= range.end;
		secondIndex++) {

			Disk* diskTest = disksArray[secondIndex];

			if (disk->author > diskTest->author) {
				Disk* temp;
				temp = disk;
				disk = diskTest;
				diskTest = temp;
				disksArray[firstIndex] = disk;
				disksArray[secondIndex] = diskTest;

			}

		}
	}
}

void DisksContainer::sortByNameInRanges(Ranges* ranges) {
	for (int index = 0; index < ranges->lenght; index++) {
		Range currentRange = ranges->rangesArray[index];
		sortByNameInRange(currentRange);
	}

}

void DisksContainer::sortByNameInRange(Range range) {
	for (int firstIndex = range.begin; firstIndex <= range.end; firstIndex++) {
		Disk* disk = disksArray[firstIndex];
		for (int secondIndex = firstIndex; secondIndex <= range.end;
		secondIndex++) {

			Disk* diskTest = disksArray[secondIndex];

			if (disk->nameOfDisk > diskTest->nameOfDisk) {
				Disk* temp;
				temp = disk;
				disk = diskTest;
				diskTest = temp;
				disksArray[firstIndex] = disk;
				disksArray[secondIndex] = diskTest;

			}

		}
	}
}

void DisksContainer::cleanUpMemory(Ranges* ranges) {
	delete[]ranges->rangesArray;
	delete[]ranges;
}

void DisksContainer::smartSortByClosureInRanges(Ranges* ranges,
	void(__closure *sorterForRange)(Range)) {
	for (int index = 0; index < ranges->lenght; index++) {
		Range currentRange = ranges->rangesArray[index];
		sorterForRange(currentRange);
	}

}

void DisksContainer::sortAll() {

	// 1. Sort by type
	sortByType();
	// 2. Detect ranges
	Ranges* ranges = detectRanges();
	// 3. Sort by author in ranges
	// sortByAuthorInRanges(ranges);
	smartSortByClosureInRanges(ranges, sortByAuthorInRange);
	// 4. Clean up memory
	cleanUpMemory(ranges);
}

void DisksContainer::sortAll2() {

	// 1. Sort by type
	sortByType();
	// 2. Detect ranges
	Ranges* ranges = detectRanges();
	// 3. Sort by name in ranges
	// sortByNameInRanges(ranges);
	smartSortByClosureInRanges(ranges, sortByNameInRange);
	// 4. Clean up memory
	cleanUpMemory(ranges);
}

void DisksContainer::resizeArray(int newSize) {
	Disk** tempArray = new Disk*[newSize];
	for (int index = 0; index < countOfDisks; index++) {

		tempArray[index] = disksArray[index];

	}

	delete[]disksArray;
	disksArray = tempArray;

}

void DisksContainer::addDisk(Disk* disk) {

	resizeArray(countOfDisks + 1);
	disksArray[countOfDisks] = disk;
	countOfDisks++;
}

Disk* DisksContainer:: operator[](int index) {
	assert(index >= 0 && index < countOfDisks);
	return disksArray[index];
}

void DisksContainer::deleteDisk(int indexForDelete) {
	Disk** tempArray = new Disk*[countOfDisks - 1];

	for (int index = 0; index < indexForDelete; index++) {
		tempArray[index] = disksArray[index];
	}
	for (int index = indexForDelete + 1; index < countOfDisks; index++) {
		tempArray[index - 1] = disksArray[index];
	}

	delete[]disksArray;
	disksArray = tempArray;
	countOfDisks--;
}

void DisksContainer::saveToFile(System::UnicodeString filename) {
	TStringList *ts = new TStringList;
	for (int index = 0; index < countOfDisks; index++) {
		Disk* disk = disksArray[index];
		ts->Add(disk->typeOfDisk);
		ts->Add(disk->typeOfInformation);
		ts->Add(disk->price);
		ts->Add(disk->nameOfDisk);
		ts->Add(disk->author);
		ts->Add(disk->note);
	}
	ts->SaveToFile(filename);
	ts->Free();
}

void DisksContainer::readFromFile(System::UnicodeString filename) {
	countOfDisks = 0;

	TStringList *ts = new TStringList;
	ts->LoadFromFile(filename);
	for (int index = 0; index < ts->Count; index += Disk::fields) {
		Disk *disk = new Disk;
		disk->typeOfDisk = ts->Strings[index];
		disk->typeOfInformation = ts->Strings[index + 1];
		disk->price = StrToInt(ts->Strings[index + 2]);
		disk->nameOfDisk = ts->Strings[index + 3];
		disk->author = ts->Strings[index + 4];
		disk->note = ts->Strings[index + 5];

		addDisk(disk);
	}
	ts->Free();

}

TStringList* DisksContainer::memoPresentation() {
	TStringList *ts = new TStringList;

	for (int index = 0; index < countOfDisks; index++) {
		Disk* disk = disksArray[index];
		ts->Add(disk->description());
	}
	return ts;
}

TStringList* DisksContainer::searchByAuthor(UnicodeString userInput) {
	UnicodeString userInputLower = userInput.LowerCase();
	TStringList *ts = new TStringList;

	for (int index = 0; index < countOfDisks; index++) {

		Disk* disk = disksArray[index];
		UnicodeString currentAuthorLower = disk->author.LowerCase();

		if (wcsstr(currentAuthorLower.c_str(), userInputLower.c_str()) != NULL)
		{
			ts->Add(disk->description());
		}

	}
	return ts;

}

TStringList* DisksContainer::searchByType(UnicodeString userInput) {
	UnicodeString userInputLower = userInput.LowerCase();
	TStringList *ts = new TStringList;

	for (int index = 0; index < countOfDisks; index++) {

		Disk* disk = disksArray[index];
		UnicodeString currentAuthorLower = disk->typeOfDisk.LowerCase();

		if (wcsstr(currentAuthorLower.c_str(), userInputLower.c_str()) != NULL)
		{
			ts->Add(disk->description());
		}

	}
	return ts;
}

TStringList* DisksContainer::searchByName(UnicodeString userInput) {
	UnicodeString userInputLower = userInput.LowerCase();
	TStringList *ts = new TStringList;

	for (int index = 0; index < countOfDisks; index++) {

		Disk* disk = disksArray[index];
		UnicodeString currentAuthorLower = disk->nameOfDisk.LowerCase();

		if (wcsstr(currentAuthorLower.c_str(), userInputLower.c_str()) != NULL)
		{
			ts->Add(disk->description());
		}

	}
	return ts;

}

TStringList* DisksContainer::comboBoxAuthors() {
	TStringList *ts = new TStringList;
	ts->Duplicates = TDuplicates::dupIgnore;
	ts->Sorted = true;

	for (int index = 0; index < countOfDisks; index++) {

		Disk* disk = disksArray[index];

		ts->Add(disk->author);
	}
	return ts;

}

TStringList* DisksContainer::comboBoxTypes() {
	TStringList *ts = new TStringList;
	ts->Duplicates = TDuplicates::dupIgnore;
	ts->Sorted = true;

	for (int index = 0; index < countOfDisks; index++) {

		Disk* disk = disksArray[index];

		ts->Add(disk->typeOfDisk);
	}
	return ts;

}
