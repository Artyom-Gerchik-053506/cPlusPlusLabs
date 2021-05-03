//---------------------------------------------------------------------------

#ifndef mainUnitH
#define mainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *intForQueue;
	TButton *push;
	TButton *pop;
	TButton *size;
	TButton *isEmpty;
	TStaticText *StaticText1;
	TListBox *ListBox1;
	TButton *peek;
	TEdit *test;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TListBox *ListBox2;
	TStaticText *StaticText2;
	TButton *Button9;
	void __fastcall pushClick(TObject *Sender);
	void __fastcall popClick(TObject *Sender);
	void __fastcall sizeClick(TObject *Sender);
	void __fastcall isEmptyClick(TObject *Sender);
	void __fastcall peekClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void UpdateUIForQueue();
    void UpdateUIForDeque();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
