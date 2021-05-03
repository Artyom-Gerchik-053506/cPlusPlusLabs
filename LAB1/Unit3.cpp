// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender) {
	FileOpenDialog1->Execute();
	// Memo1->Lines->Add(FileOpenDialog1->FileName);
	TFileStream *tfile = new TFileStream(FileOpenDialog1->FileName,
		fmOpenReadWrite);
	TStringList *ts = new TStringList();

	ts->LoadFromStream(tfile);
	Memo1->Lines = ts;

	tfile->Free();
	//delete tfile;
	delete ts;
}
// ---------------------------------------------------------------------------
