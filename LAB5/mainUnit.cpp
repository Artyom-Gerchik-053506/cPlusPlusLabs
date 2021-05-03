// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
#include "MyOwnQueue.h"
#include "MyDeque.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

MyOwnQueue q;
MyDeque d;

void TForm1::UpdateUIForQueue() {
	ListBox1->Items->Clear();
	ListBox1->Items->Add(q.Content());
}

void TForm1::UpdateUIForDeque() {
	ListBox2->Items->Clear();
	ListBox2->Items->Add(d.showContent());
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::pushClick(TObject *Sender) {
	MyOwnList *tempElement = new MyOwnList;
	tempElement->anyNumber = StrToInt(intForQueue->Text);
	q.Push(tempElement);
	UpdateUIForQueue();
	intForQueue->Text = "";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::popClick(TObject *Sender) {
	if (q.Empty()) {
		ShowMessage("Empty.");
	}
	else {
		q.Pop();
		UpdateUIForQueue();
		intForQueue->Text = "";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::sizeClick(TObject *Sender) {
	ShowMessage(q.Size());
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::isEmptyClick(TObject *Sender) {
	if (q.Empty()) {
		ShowMessage("Empty.");
	}
	else {
		ShowMessage("Not Empty.");
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::peekClick(TObject *Sender) {
	if (q.Empty()) {
		ShowMessage("Empty.");
	}
	else {
		ShowMessage(q.Peek());
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	d.push_left(StrToInt(test->Text));
	UpdateUIForDeque();
	test->Text = "";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	d.push_right(StrToInt(test->Text));
	UpdateUIForDeque();
	test->Text = "";

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	d.pop_left();
	UpdateUIForDeque();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	d.pop_right();
	UpdateUIForDeque();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	if (d.isEmpty()) {
		ShowMessage("Deque Empty.");
	}
	else {
		ShowMessage("Deque Are Not Empty");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	ShowMessage(d.size());
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	d.peek_left();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender) {
	d.peek_right();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender) {
	d.performMyTask();
    UpdateUIForDeque();
}
// ---------------------------------------------------------------------------
