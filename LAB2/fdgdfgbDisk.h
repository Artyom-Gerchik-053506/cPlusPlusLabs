#include <string>
#include <System.hpp>

using namespace std;

class Disk {

public:
	static const int fields = 6;
	int typeOfDisk;
	int typeOfInformation;
	int price;
	UnicodeString nameOfDisk;
	UnicodeString author;
	UnicodeString note;

	Disk() {
		typeOfDisk = 0;
		typeOfInformation = 0;
		price = 0;
		nameOfDisk = "";
		author = "";
		note = "";
	}

	~Disk() {
	}

};
