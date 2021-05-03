// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "ris.h"
TForm1 *Form1;
// ---------------------------------------------------------------------------
int shag = 10, sleepTimer = 30;
rectangleFather mainBody(0, 250, 200, 313);
flagShtock shtok(95, 95, 110, 250);
flag flajok(110, 230, 20, 180);

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

void __fastcall TForm1::Button1Click(TObject *Sender) {

	shtok.show(Canvas);
	mainBody.show(Canvas);
	flajok.show(Canvas);
	sun(Canvas);
	sea(Canvas);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	for (int i = 0; i < 10; i++) {
		mainBody.moveRight(Canvas, shag, 0, shag, 0);
		shtok.moveRight(Canvas, shag, 0, shag, 0);
		flajok.moveRight(Canvas, shag, 0, shag, 0);
		sea(Canvas);
		Sleep(sleepTimer);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	for (int i = 0; i < 10; i++) {
		mainBody.moveLeft(Canvas, shag, 0, shag, 0);
		shtok.moveLeft(Canvas, shag, 0, shag, 0);
		flajok.moveLeft(Canvas, shag, 0, shag, 0);
		sea(Canvas);
		Sleep(sleepTimer);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	for (int i = 0; i < 10; i++) {
		flajok.moveUp(Canvas, 0, shag, 0, shag);
		shtok.show(Canvas);
		flajok.show(Canvas);
		mainBody.show(Canvas);
		sea(Canvas);
		Sleep(sleepTimer);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	for (int i = 0; i < 10; i++) {
		flajok.moveDown(Canvas, 0, shag, 0, shag);
		shtok.show(Canvas);
		flajok.show(Canvas);
		mainBody.show(Canvas);
		sea(Canvas);
		Sleep(sleepTimer);
	}
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
