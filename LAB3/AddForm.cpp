// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddForm.h"
#include "mainUnit.h"
#include "Brain.h"
#include "StudentList.h"
#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"
#include "MyException.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;

TForm1* Form1;

Brain* brain;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner, Brain* brainFromOwner)
	: TForm(Owner) {
	Form1 = (TForm1*)Owner;
	brain = brainFromOwner;
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender) {
	try {
		StudentList* student = new StudentList;
		student->name = Edit1->Text;
		student->city = Edit2->Text;
		student->mark1 = StrToInt(Edit3->Text);
		student->mark2 = StrToInt(Edit4->Text);
		student->mark3 = StrToInt(Edit5->Text);
		if (student->mark1 <= 0 || student->mark1 > 5) {
			Edit3->Text = "";
			throw incorrectMarksException
				("We Study On A Five-Point Scale. Enter Proper Value Of Mark1 (1,2,3,4,5)"
				);

		}
		if (student->mark2 <= 0 || student->mark2 > 5) {
			Edit4->Text = "";
			throw incorrectMarksException
				("We Study On A Five-Point Scale. Enter Proper Value Of Mark2 (1,2,3,4,5)"
				);

		}
		if (student->mark3 <= 0 || student->mark3 > 5) {
			Edit5->Text = "";
			throw incorrectMarksException
				("We Study On A Five-Point Scale. Enter Proper Value Of Mark3 (1,2,3,4,5)"
				);

		}
		student->avgMark =
			(student->mark1 + student->mark2 + student->mark3) / 3.0;
		brain->addStudent(student);

		Form1->UpdateUI();

		this->Close();
	}
	catch (nullStudentsException &E) {
		ShowMessage(String(E.getName()));
	}
	catch (...) {
		ShowMessage(
			"incorrectMarksException doesn't catched! something went wrong! Maybe u forget to enter a mark value!");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender) {
	this->Close();
}
// ---------------------------------------------------------------------------
