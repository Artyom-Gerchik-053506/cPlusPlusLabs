#include <array>
#include "System.SysUtils.hpp"

using namespace std;

class DisksContainer {
private:
	array<Disk*, 100>disksArray;

public:
	int countOfDisks = 0;

	void addDisk(Disk *disk) {
		disksArray[countOfDisks] = disk;
		countOfDisks++;
	}

	void saveToFile(System::UnicodeString filename) {
		TStringList *ts = new TStringList;
		for (int index = 0; index < countOfDisks; index++) {
			Disk *disk = disksArray[index];
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

	void readFromFile(System::UnicodeString filename) {
		TStringList *ts = new TStringList;
		ts->LoadFromFile(filename);
		for (int index = 1; index < ts->Count; index += Disk::fields) {
			Disk *disk = new Disk;
            int i = StrToInt("100");
			//disk->typeOfDisk = ts[index].ToInt();
			// disk->typeOfInformation = ts[index + 1];
			// disk->price = ts[index + 2];
			 disk->nameOfDisk = ts[index + 3];
//			 disk->author = ts[index + 4];
//			 disk->note = ts[index + 5];

		}
		ts->Free();

	}
};
