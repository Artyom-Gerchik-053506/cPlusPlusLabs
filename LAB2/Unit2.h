// ---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "DisksContainer.h"
#include "Disk.h"

// ---------------------------------------------------------------------------
class TForm2 : public TForm {
__published: // IDE-managed Components
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label1;
	TEdit *Edit2;
	TLabel *Label2;
	TEdit *Edit3;
	TLabel *Label3;
	TEdit *Edit4;
	TLabel *Label4;
	TEdit *Edit5;
	TLabel *Label5;
	TEdit *Edit6;
	TLabel *Label6;

	void __fastcall Button1Click(TObject *Sender);

private: // User declarations
	DisksContainer *dContainer;
	int selectedIndex;

public: // User declarations
	__fastcall TForm2(TComponent* Owner, DisksContainer *dContainer,
		int selectedIndex);
	void FillDisk(Disk* disk);

};

// ---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
// ---------------------------------------------------------------------------
#endif
