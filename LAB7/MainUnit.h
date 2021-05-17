// ---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXCtrls.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TButton *Button1;
	TMemo *Memo1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label1;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TLabel *Label2;
	TStaticText *StaticText3;
	TLabel *Label3;
	TStaticText *StaticText4;
	TLabel *Label4;
	TButton *Button2;
	TButton *Button3;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
	void UpdateUI();
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
