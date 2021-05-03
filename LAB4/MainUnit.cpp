// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include <string.h>
#include <System.hpp>
#include "SysUtils.hpp"
#include "Brain.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

Brain brain;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (Edit1->Text != "") {
		Label1->Caption = Edit1->Text;
		Label2->Caption = brain.parseRPN2(Edit1->Text);
	}
	else {
		ShowMessage("NothingToParse");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender) {
	brain.clearOutput();
	brain.cleanUP();

	Label1->Caption = "";
	Label2->Caption = "";

	calcRPN->Caption = "";
	calcORIGINAL->Caption = "";

	aValue->Text = "";
	bValue->Text = "";
	cValue->Text = "";
	dValue->Text = "";
	eValue->Text = "";
}

// --------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {

	if (Label1->Caption == "" && Label2->Caption == "") {
		ShowMessage("NothingToCalculate");
	}
	else {
		float a = StrToFloat(aValue->Text);
		float b = StrToFloat(bValue->Text);
		float c = StrToFloat(cValue->Text);
		float d = StrToFloat(dValue->Text);
		float e = StrToFloat(eValue->Text);

		double aD = aValue->Text.ToDouble();
		double bD = bValue->Text.ToDouble();
		double cD = cValue->Text.ToDouble();
		double dD = dValue->Text.ToDouble();
		double eD = eValue->Text.ToDouble();

		std::wstring your_wchar_in_ws(Edit1->Text.c_str());
		string your_wchar_in_str(your_wchar_in_ws.begin(),
			your_wchar_in_ws.end());
		char const * EX = your_wchar_in_str.c_str();

		calcRPN->Caption = brain.calculateRPN(a, b, c, d, e);
		calcORIGINAL->Caption = brain.test(EX, aD, bD, cD, dD, eD);
	}

}
// ---------------------------------------------------------------------------
