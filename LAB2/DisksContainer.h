// ---------------------------------------------------------------------------

#ifndef DisksContainerH
#define DisksContainerH

#include <array>
#include "Disk.h"
#include <vcl.h>

using namespace std;

struct Range {

	int begin = 0;
	int end = 0;

};

class Ranges {
public:
	Range* rangesArray;

	int lenght = 0;
};

class DisksContainer {
private:
	Disk **disksArray;

	int countOfDisks = 0;
	void resizeArray(int newSize);
	void sortByType();
	Ranges* detectRanges();

	void sortByAuthorInRanges(Ranges *ranges);
	void sortByAuthorInRange(Range range);

	void sortByNameInRanges(Ranges* ranges);
	void sortByNameInRange(Range range);
	void cleanUpMemory(Ranges* ranges);

	void smartSortByClosureInRanges(Ranges* ranges,
		void(__closure sorterForRange)(Range));

public:
	Disk* operator[](int index);

	int Count();
	void sortAll();
	void sortAll2();

	void addDisk(Disk* disk);
	void deleteDisk(int index);
	void saveToFile(System::UnicodeString filename);
	void readFromFile(System::UnicodeString filename);
	TStringList* memoPresentation();
	TStringList* searchByAuthor(System::UnicodeString);
	TStringList* searchByName(UnicodeString userInput);
	TStringList* searchByType(UnicodeString userInput);
	TStringList* comboBoxAuthors();
	TStringList* comboBoxTypes();
};
// ---------------------------------------------------------------------------
#endif
