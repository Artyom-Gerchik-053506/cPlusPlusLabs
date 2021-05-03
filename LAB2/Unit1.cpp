// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Disk.h"
#include "DisksContainer.h"
#include <array>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TForm1 *Form1;
DisksContainer* dContainer = new DisksContainer;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (FileSaveDialog1->Execute()) {
		dContainer->saveToFile(FileSaveDialog1->FileName);
	}
	else {
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject * Sender) {

	if (FileOpenDialog1->Execute()) {
		dContainer->readFromFile(FileOpenDialog1->FileName);

		UpdateUI();
	}
	else {
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	int selectedIndex = StrToInt(Edit1->Text);
	if (selectedIndex == 0 || selectedIndex > dContainer->Count()) {
		ShowMessage("Enter Proper Index.");
	}
	else {
		TForm2 *Form = new TForm2(this, dContainer, selectedIndex - 1);
		Form->ShowModal();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	TForm2 *Form = new TForm2(this, dContainer, -1);
	Form->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	int indexForDelete = StrToInt(Edit1->Text);
	if (indexForDelete == 0 || indexForDelete > dContainer->Count()) {
		ShowMessage("Enter Proper Index.");
	}
	else {
		dContainer->deleteDisk(indexForDelete - 1);
		UpdateUI();
	}

}

// ---------------------------------------------------------------------------

void TForm1::UpdateUI() {

	TStringList *temp = dContainer->memoPresentation();
	Memo1->Lines = temp;
	temp->Free();
	Label1->Caption = dContainer->Count();
	Edit1->Text = "";

	TStringList *cbSource = dContainer->comboBoxAuthors();
	ComboBox1->Items = cbSource;
	cbSource->Free();

	TStringList *cbSourceSecond = dContainer->comboBoxTypes();
	ComboBox2->Items = cbSourceSecond;
	cbSourceSecond->Free();

}

void __fastcall TForm1::Button6Click(TObject *Sender) {
	dContainer->sortAll();
	UpdateUI();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	dContainer->sortAll2();
	UpdateUI();
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender) {
	ComboBox1->Text = "";
	ComboBox2->Text = "";
	TStringList *tmp = dContainer->searchByAuthor(SearchField->Text);
	Memo2->Lines = tmp;
	tmp->Free();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender) {
	ComboBox1->Text = "";
	ComboBox2->Text = "";
	TStringList *tmp = dContainer->searchByName(SearchField->Text);
	Memo2->Lines = tmp;
	tmp->Free();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::onSelect(TObject *Sender) {
	ComboBox2->Text = "";
	SearchField->Text = "";
	UnicodeString authorName = ComboBox1->Text;
	TStringList *tmp = dContainer->searchByAuthor(authorName);
	Memo2->Lines = tmp;
	tmp->Free();
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::onSelectSecond(TObject *Sender) {
	ComboBox1->Text = "";
	SearchField->Text = "";
	UnicodeString typeOfDisk = ComboBox2->Text;
	TStringList *tmp = dContainer->searchByType(typeOfDisk);
	Memo2->Lines = tmp;
	tmp->Free();
}
// ---------------------------------------------------------------------------
