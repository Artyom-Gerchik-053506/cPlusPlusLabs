// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
#include "Brain.h"
#include "AddForm.h"
#include "MyException.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Brain* brain = new Brain;
int numberOfRowsForExplanation = 1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void TForm1::UpdateUI() {

	brain->sortName = Edit1->Text;
	brain->sortCity = Edit2->Text;
	if (Edit3->Text != "") {
		brain->sortAvgMark = StrToFloat(Edit3->Text);
	}
	else {
		brain->sortAvgMark = -1;
	}

	StringGrid1->ColCount = 7;
	StringGrid1->RowCount = brain->numberOfStudentsForUI() +
		numberOfRowsForExplanation;
	StringGrid1->Cells[0][0] = "Number";
	StringGrid1->Cells[1][0] = "Name";
	StringGrid1->Cells[2][0] = "City";
	StringGrid1->Cells[3][0] = "Mark1";
	StringGrid1->Cells[4][0] = "Mark2";
	StringGrid1->Cells[5][0] = "Mark3";
	StringGrid1->Cells[6][0] = "AvgMark";

	for (int row = 0; row < brain->numberOfStudentsForUI(); row++) {
		StudentList* tempStudent = brain->studentAtIndexForUI(row);
		int UIRow = numberOfRowsForExplanation + row;
		StringGrid1->Cells[0][UIRow] = row + 1;
		StringGrid1->Cells[1][UIRow] = tempStudent->name;
		StringGrid1->Cells[2][UIRow] = tempStudent->city;
		StringGrid1->Cells[3][UIRow] = tempStudent->mark1;
		StringGrid1->Cells[4][UIRow] = tempStudent->mark2;
		StringGrid1->Cells[5][UIRow] = tempStudent->mark3;
		StringGrid1->Cells[6][UIRow] = tempStudent->avgMark;

	}

}

void TForm1::ClearGridRow(int rowToClear) {

	StringGrid1->Cells[0][rowToClear] = "";
	StringGrid1->Cells[1][rowToClear] = "";
	StringGrid1->Cells[2][rowToClear] = "";
	StringGrid1->Cells[3][rowToClear] = "";
	StringGrid1->Cells[4][rowToClear] = "";
	StringGrid1->Cells[5][rowToClear] = "";
	StringGrid1->Cells[6][rowToClear] = "";

}

void TForm1::ClearGrid() {
	for (int row = 0; row < brain->numberOfStudentsForUI(); row++) {
		int UIRow = numberOfRowsForExplanation + row;
		StringGrid1->Cells[0][UIRow] = "";
		StringGrid1->Cells[1][UIRow] = "";
		StringGrid1->Cells[2][UIRow] = "";
		StringGrid1->Cells[3][UIRow] = "";
		StringGrid1->Cells[4][UIRow] = "";
		StringGrid1->Cells[5][UIRow] = "";
		StringGrid1->Cells[6][UIRow] = "";
	}

}

void __fastcall TForm1::Button2Click(TObject *Sender) {
	TForm2 *addForm = new TForm2(this, brain);
	addForm->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	UpdateUI();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender) {
	if (Edit1->Text == "") {
		UpdateUI();
	}

	ClearGrid();
	int UIRow = 1;
	try {
		if (brain->numberOfStudents() == 0) {
			throw nullStudentsException
				("Number Of Students == NULL! Who U Want To Find?!");
		}

		UpdateUI();
	}

	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
		Edit1->Text = "";
	}

	catch (...) {
		ShowMessage(
			"nullStudentsException doesn't catched! smthng went wrong.");
		Edit1->Text = "";
		UpdateUI();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	ClearGrid();
	int UIRow = 1;
	try {
		if (brain->numberOfStudents() == 0) {
			throw nullStudentsException
				("Number Of Students == NULL! Who U Want To Find?!");
		}

		UpdateUI();
	}

	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
		Edit1->Text = "";
	}

	catch (...) {
		ShowMessage(
			"nullStudentsException doesn't catched! smthng went wrong.");
		Edit1->Text = "";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit2Change(TObject *Sender) {

	if (Edit2->Text == "") {
		UpdateUI();
	}

	ClearGrid();
	int UIRow = 1;

	try {

		if (brain->numberOfStudents() == 0) {
			throw nullStudentsException
				("Number Of Students == NULL! Who U Want To Find?!");
		}
		UpdateUI();

	}
	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
		Edit2->Text = "";
	}

	catch (...) {
		ShowMessage(
			"nullStudentsException doesn't catched! smthng went wrong.");
		Edit2->Text = "";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	ClearGrid();
	int UIRow = 1;

	try {

		if (brain->numberOfStudents() == 0) {
			throw nullStudentsException
				("Number Of Students == NULL! Who U Want To Find?!");
		}
		UpdateUI();

	}
	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
		Edit2->Text = "";
	}

	catch (...) {
		ShowMessage(
			"nullStudentsException doesn't catched! smthng went wrong.");
		Edit2->Text = "";
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Change(TObject *Sender) {
	if (Edit3->Text == "") {
		UpdateUI();
	}

	ClearGrid();
	int UIRow = 1;

	try {

		if (brain->numberOfStudents() == 0) {
			throw nullStudentsException
				("Number Of Students == NULL! Who U Want To Find?!");
		}
		UpdateUI();

	}

	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
		Edit3->Text = "";
	}

	catch (...) {
		ShowMessage(
			"nullStudentsException doesn't catched! smthng went wrong.");
		Edit3->Text = "";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	ClearGrid();
	int UIRow = 1;

	try {

		if (brain->numberOfStudents() == 0) {
			throw nullStudentsException
				("Number Of Students == NULL! Who U Want To Find?!");
		}
		UpdateUI();

	}

	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
		Edit3->Text = "";
	}

	catch (...) {
		ShowMessage(
			"nullStudentsException doesn't catched! smthng went wrong.");
		Edit3->Text = "";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {

	try {
		float minimalAvg = StrToFloat(Edit3->Text);
		if (brain->numberOfStudents() == 0) {
			throw nullStudentsException
				("Number Of Students == NULL! For Who U Want Set MinimalAVG!?");
		}
		if (minimalAvg <= 0 || minimalAvg > 5) {
			throw incorrectAVGMarkException
				("U Entered Incorrect MinimalAVG! Enter proper(1,2,3,4,5)");
		}

		brain->deleteStudentsWithMarkLowerThanAVG(minimalAvg);

		Edit3->Text = "";

		UpdateUI();
	}

	catch (incorrectAVGMarkException &E) {
		ShowMessage(String(E.getName()));
		Edit3->Text = "";
	}

	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
		Edit3->Text = "";
	}

	catch (...) {
		ShowMessage(
			"nullStudentsException doesn't catched! smthng went wrong. maybe u forget to enter a value");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	UpdateUI();
}
// ---------------------------------------------------------------------------
