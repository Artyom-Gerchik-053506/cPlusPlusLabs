// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

TForm1* Form1;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner, DisksContainer *dContainer,
	int selectedIndex) : TForm(Owner) {
	Form1 = (TForm1*)Owner;
	this->dContainer = dContainer;
	this->selectedIndex = selectedIndex;
	if (selectedIndex != -1) {
		Edit1->Text = (*dContainer)[selectedIndex]->typeOfDisk;
		Edit2->Text = (*dContainer)[selectedIndex]->typeOfInformation;
		Edit3->Text = (*dContainer)[selectedIndex]->price;
		Edit4->Text = (*dContainer)[selectedIndex]->nameOfDisk;
		Edit5->Text = (*dContainer)[selectedIndex]->author;
		Edit6->Text = (*dContainer)[selectedIndex]->note;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender) {
	if (selectedIndex != -1) {
		Disk* disk = (*dContainer)[selectedIndex];
		FillDisk(disk);
	}
	else {
		Disk * disk = new Disk;
		FillDisk(disk);
		dContainer->addDisk(disk);
	}
	Form1->UpdateUI();
	this->Close();

}

void TForm2::FillDisk(Disk* disk) {
	disk->typeOfDisk = Edit1->Text;
	disk->typeOfInformation = Edit2->Text;
	disk->price = StrToInt(Edit3->Text);
	disk->nameOfDisk = Edit4->Text;
	disk->author = Edit5->Text;
	disk->note = Edit6->Text;

}
