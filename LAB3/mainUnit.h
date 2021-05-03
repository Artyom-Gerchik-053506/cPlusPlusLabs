// ---------------------------------------------------------------------------

#ifndef mainUnitH
#define mainUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TStringGrid *StringGrid1;
	TButton *Button2;
	TButton *Button1;
	TEdit *Edit1;
	TButton *Button3;
	TEdit *Edit2;
	TButton *Button4;
	TEdit *Edit3;
	TButton *Button5;
	TButton *Button6;

	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private: // User declarations

public: // User declarations
	__fastcall TForm1(TComponent* Owner);
	void UpdateUI();
    void ClearGrid();
	void ClearGridRow(int);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
