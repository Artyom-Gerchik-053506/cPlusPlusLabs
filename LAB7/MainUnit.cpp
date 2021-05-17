// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "HashTable.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
PasswordListHashTable* myTable = nullptr;
int tableSize = 10;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void TForm1::UpdateUI() {
	Memo1->Lines->Clear();
	Edit2->Text = "";
	Edit3->Text = "";
	for (int index = 0; index < tableSize; index++) {
		Memo1->Lines->Add(myTable->Print(index));
	}
	Label1->Caption = myTable->calculateNumberOfElements();
	Label2->Caption = myTable->calculateSumOfKeys();
	Label3->Caption = myTable->calculateAVG();
	Label4->Caption = myTable->countKeysWichBiggerThanAVG();

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (myTable == nullptr) {
		myTable = new PasswordListHashTable(tableSize);
	}
	if (Edit2->Text == "") {
		ShowMessage("Enter Password");
	}
	else {
		String Desc = Edit3->Text;
		String Pass = Edit2->Text;
		int KEY = 0;

		for (int index = 1; index < Pass.Length() + 1; index++) {
			KEY += Pass[index];
		}

		myTable->insertElement(KEY, Desc, Pass);
		UpdateUI();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	if (Edit2->Text == "") {
		ShowMessage("Enter Password");
	}
	else {
		String Pass = Edit2->Text;
		int KEY = 0;

		for (int index = 1; index < Pass.Length() + 1; index++) {
			KEY += Pass[index];
		}
		myTable->Remove(KEY);
		UpdateUI();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	if (Edit2->Text == "") {
		ShowMessage("Enter Password");
	}
	else {
		String Pass = Edit2->Text;
		int KEY = 0;

		for (int index = 1; index < Pass.Length() + 1; index++) {
			KEY += Pass[index];
		}
		myTable->Search(KEY);
		UpdateUI();
	}
}
// ---------------------------------------------------------------------------
