//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TButton *Button2;
	TEdit *aValue;
	TEdit *bValue;
	TEdit *cValue;
	TEdit *dValue;
	TEdit *eValue;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TLabel *calcRPN;
	TLabel *calcORIGINAL;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
