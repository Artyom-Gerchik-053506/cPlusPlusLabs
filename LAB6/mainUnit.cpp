// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainUnit.h"
#include "MyOwnAVLTree.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AVLNode* rootToWork;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void ViewTree(AVLNode *t, int kl, TTreeView *TreeView1) {
	if (t == NULL) { // проверка узла дерева на пустоту
		return; // завершаем текущую функцию
	}
	if (kl == -1) { // если корневой элемент
		TreeView1->Items->AddFirst(NULL, t->text + " = " + IntToStr(t->key));
		// создание корневого элемента Treeview
	}
	else { // если дочерний узел
		TreeView1->Items->AddChildFirst(TreeView1->Items->Item[kl],
			t->text + " = " + IntToStr(t->key));
	}

	kl++; // переход на следующий узел

	ViewTree(t->left_child, kl, TreeView1);
	// выполняем для левого поддерева, пока не дойдем до конца
	ViewTree(t->right_child, kl, TreeView1);
	// выполняем для правого поддерева, пока не дойдем до конца

	kl--; // возвращаемся на предыдущий уровень

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	StringGrid1->Cells[0][0] = "Text";
	StringGrid1->Cells[1][0] = "Key";

	StringGrid1->Cells[0][1] = "a";
	StringGrid1->Cells[0][2] = "b";
	StringGrid1->Cells[0][3] = "c";
	StringGrid1->Cells[0][4] = "d";
	StringGrid1->Cells[0][5] = "e";
	StringGrid1->Cells[0][6] = "f";

	StringGrid1->Cells[1][1] = "9";
	StringGrid1->Cells[1][2] = "11";
	StringGrid1->Cells[1][3] = "1";
	StringGrid1->Cells[1][4] = "3";
	StringGrid1->Cells[1][5] = "8";
	StringGrid1->Cells[1][6] = "20";

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	int size = 0;
	for (int i = 1; i < 8; i++) {
		if (StringGrid1->Cells[1][i] != '0') {
			size++;
		}
	}

	for (int i = 1; i < size; i++) {
		rootToWork = addNode(rootToWork, StrToInt(StringGrid1->Cells[1][i]),
			StringGrid1->Cells[0][i]);
	}

	TreeView1->Items->Clear();
	ViewTree(rootToWork, -1, TreeView1);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {

	rootToWork = addNode(rootToWork, StrToInt(Edit2->Text), Edit1->Text);
	TreeView1->Items->Clear();
	ViewTree(rootToWork, -1, TreeView1);
	TreeView1->Items->Item[0]->Expand(rootToWork);

	Edit1->Text = "";
	Edit2->Text = "";

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	TreeView1->Items->Item[0]->Expand(rootToWork);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	TraversPreOrder(rootToWork);
	ShowMessage(printOutput());
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	TraversInOrder(rootToWork);
	ShowMessage(printOutput());
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	TraversPostOrder(rootToWork);
	ShowMessage(printOutput());
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	searchByKey(rootToWork, StrToInt(Edit2->Text));
	Edit2->Text = "";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender) {
	rootToWork = deleteNode(rootToWork, StrToInt(Edit2->Text));
	if (!rootToWork) {
		TreeView1->Items->Clear();
		Edit2->Text = "";
	}
	else {
		rootToWork = balanceFunc(rootToWork);
		Edit2->Text = "";
		TreeView1->Items->Clear();
		ViewTree(rootToWork, -1, TreeView1);
		TreeView1->Items->Item[0]->Expand(rootToWork);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender) {
	int test = performMyTask(rootToWork);
	if (test == 1337) {
		ShowMessage("Left Sub-Tree Absent.");
	}
	else {
		rootToWork = deleteNode(rootToWork, test);
		rootToWork = balanceFunc(rootToWork);
		TreeView1->Items->Clear();
		ViewTree(rootToWork, -1, TreeView1);
		TreeView1->Items->Item[0]->Expand(rootToWork);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender) {
	rootToWork = balanceFunc(rootToWork);
	Edit2->Text = "";
	TreeView1->Items->Clear();
	ViewTree(rootToWork, -1, TreeView1);
	TreeView1->Items->Item[0]->Expand(rootToWork);
}
// ---------------------------------------------------------------------------
