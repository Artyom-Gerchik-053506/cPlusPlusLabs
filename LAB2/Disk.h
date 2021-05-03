// ---------------------------------------------------------------------------

#ifndef DiskH
#define DiskH

#include <string>
#include <System.hpp>
#include "SysUtils.hpp"

using namespace std;

class Disk {

public:
	static const int fields = 6;
	UnicodeString typeOfDisk;
	UnicodeString typeOfInformation;
	int price;
	UnicodeString nameOfDisk;
	UnicodeString author;
	UnicodeString note;

	Disk() {
		typeOfDisk = "";
		typeOfInformation = "";
		price = 0;
		nameOfDisk = "";
		author = "";
		note = "";
	}

	UnicodeString description() {
		UnicodeString joinedInfo = typeOfDisk + " " + typeOfInformation + " " +
			IntToStr(price) + " " + nameOfDisk + " " + author + " " + note;
		return joinedInfo;
	}

	~Disk() {
	}

};
// ---------------------------------------------------------------------------
#endif
