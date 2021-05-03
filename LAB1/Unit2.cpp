// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "krug.h"
#include "mnogougolnik.h"
#include "treugolnik.h"
#include "pryamougolnik.h"
#include "square.h"
#include "ellipse.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;

float xFirst, yFirst, xSecond, ySecond, xThird, yThird, xFourth, yFourth,
	storona, x, y, radius, xCenterMass, yCenterMass, angle, scale;

Krug circle(x, y, radius);

class Ellipse elips(xFirst, yFirst, xSecond, ySecond);

Treugolnik triangle(xFirst, yFirst, xSecond, ySecond, xThird, yThird);

Pryamougolnik rectangle(xFirst, yFirst, xSecond, ySecond, xThird, yThird,
	xFourth, yFourth);

Square kvadrat(xFirst, yFirst, xSecond, ySecond, storona, xThird, yThird,
	xFourth, yFourth);

// triangle.draw(Canvas);
// rectangle.draw(Canvas);
// circle.draw(Canvas);
// kvadrat.draw(Canvas);
// elips.draw(Canvas);

// --------------------------------------------------------------------------

__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender) {

	rectangle.hide(Canvas);

	xFirst = StrToFloat(Edit1->Text);
	yFirst = StrToFloat(Edit2->Text);

	xSecond = StrToFloat(Edit3->Text);
	ySecond = StrToFloat(Edit4->Text);

	rectangle.prisvoenie(xFirst, yFirst, xSecond, ySecond);

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender) {
	rectangle.draw(Canvas);
	Label1->Caption = rectangle.getSquare();
	Label2->Caption = rectangle.getPerimeter();
	Label17->Caption = rectangle.centerMassX();
	Label18->Caption = rectangle.centerMassY();

}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender) {

	circle.draw(Canvas);
	Label7->Caption = circle.getSquare();
	Label8->Caption = circle.getLenght();
	Label13->Caption = circle.centerMassX();
	Label14->Caption = circle.centerMassY();

}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender) {
	kvadrat.hide(Canvas);

	storona = StrToFloat(Edit7->Text);

	xFirst = StrToFloat(Edit5->Text);
	yFirst = StrToFloat(Edit6->Text);

	xSecond = xFirst + storona;
	ySecond = yFirst;

	xThird = xSecond;
	yThird = ySecond + storona;

	xFourth = xFirst;
	yFourth = yThird;

	kvadrat.prisvoenie(xFirst, yFirst, xSecond, ySecond, xThird, yThird,
		xFourth, yFourth, storona);
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender) {
	kvadrat.draw(Canvas);
	Label5->Caption = kvadrat.getPerimeter();
	Label6->Caption = kvadrat.getSquare();
	Label15->Caption = kvadrat.centerMassX();
	Label16->Caption = kvadrat.centerMassY();
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender) {
	circle.hide(Canvas);
	x = StrToFloat(Edit8->Text);
	y = StrToFloat(Edit9->Text);
	radius = StrToFloat(Edit10->Text);
	circle.prisvoenie(x, y, radius);
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender) {

	triangle.hide(Canvas);

	xFirst = StrToFloat(Edit11->Text);
	yFirst = StrToFloat(Edit12->Text);

	xSecond = StrToFloat(Edit13->Text);
	ySecond = StrToFloat(Edit14->Text);

	xThird = StrToFloat(Edit15->Text);
	yThird = StrToFloat(Edit16->Text);

	triangle.prisvoenie(xFirst, yFirst, xSecond, ySecond, xThird, yThird);

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender) {
	triangle.draw(Canvas);
	Label10->Caption = triangle.getPerimeter();
	Label9->Caption = triangle.getSquare();
	Label11->Caption = triangle.centerMassX();
	Label12->Caption = triangle.centerMassY();

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender) {
	angle = StrToFloat(Edit17->Text);
	if (angle > 0) {
		for (int i = 0; i <= angle; i++) {
			triangle.rotateAtCenter(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(15);

		}
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender) {
	angle = StrToFloat(Edit18->Text);
	if (angle > 0) {
		for (int i = 0; i <= angle; i++) {

			kvadrat.rotateAtCenter(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(15);

		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button12Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {
			kvadrat.changeScalePlus(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}

		Label5->Caption = kvadrat.getPerimeter();
		Label6->Caption = kvadrat.getSquare();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button13Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {
			kvadrat.changeScaleMinus(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label5->Caption = kvadrat.getPerimeter();
		Label6->Caption = kvadrat.getSquare();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button14Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			triangle.changeScalePlus(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label10->Caption = triangle.getPerimeter();
		Label9->Caption = triangle.getSquare();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button15Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			triangle.changeScaleMinus(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label10->Caption = triangle.getPerimeter();
		Label9->Caption = triangle.getSquare();

	}
}

void __fastcall TForm2::Button10Click(TObject *Sender) {
	angle = StrToFloat(Edit19->Text);
	if (angle > 0) {
		for (int i = 0; i <= angle; i++) {

			rectangle.rotateAtCenter(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(15);

		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button16Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			rectangle.changeScalePlus(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label1->Caption = rectangle.getSquare();
		Label2->Caption = rectangle.getPerimeter();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button17Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			rectangle.changeScaleMinus(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label1->Caption = rectangle.getSquare();
		Label2->Caption = rectangle.getPerimeter();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button18Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			circle.changeScalePlus(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label7->Caption = circle.getSquare();
		Label8->Caption = circle.getLenght();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button19Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			circle.changeScaleMinus(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label7->Caption = circle.getSquare();
		Label8->Caption = circle.getLenght();

	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button20Click(TObject *Sender) {
	elips.hide(Canvas);

	xFirst = StrToFloat(Edit20->Text);
	yFirst = StrToFloat(Edit21->Text);

	xSecond = StrToFloat(Edit22->Text);
	ySecond = StrToFloat(Edit23->Text);

	elips.prisvoenie(xFirst, yFirst, xSecond, ySecond);
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button21Click(TObject *Sender) {
	Canvas->Pen->Color = clGreen;

	elips.draw(Canvas);
	Label19->Caption = elips.getSquare();
	Label20->Caption = elips.getLenght();
	Label21->Caption = elips.centerMassX();
	Label22->Caption = elips.centerMassY();

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button22Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.changeScalePlus(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label19->Caption = elips.getSquare();
		Label20->Caption = elips.getLenght();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button23Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.changeScaleMinus(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label19->Caption = elips.getSquare();
		Label20->Caption = elips.getLenght();

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button24Click(TObject *Sender) {
	angle = StrToFloat(Edit24->Text);
	if (angle > 0) {
		for (int i = 0; i <= angle; i++) {

			elips.rotateAtCenter(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(15);

		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button25Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.changeScalePlusRadiusHorizontal(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label19->Caption = elips.getSquare();
		Label20->Caption = elips.getLenght();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button26Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.changeScaleMinusRadiusHorizontal(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label19->Caption = elips.getSquare();
		Label20->Caption = elips.getLenght();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button27Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.changeScalePlusRadiusVertical(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label19->Caption = elips.getSquare();
		Label20->Caption = elips.getLenght();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button28Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.changeScaleMinusRadiusVertical(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label19->Caption = elips.getSquare();
		Label20->Caption = elips.getLenght();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button29Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			triangle.moveUpCenterMassY(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label11->Caption = triangle.centerMassX();
		Label12->Caption = triangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button32Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			triangle.moveDownCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label11->Caption = triangle.centerMassX();
		Label12->Caption = triangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button30Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			triangle.moveLeftCenterMassX(Canvas);
			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label11->Caption = triangle.centerMassX();
		Label12->Caption = triangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button31Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			triangle.moveRightCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label11->Caption = triangle.centerMassX();
		Label12->Caption = triangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button33Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			kvadrat.moveUpCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label15->Caption = kvadrat.centerMassX();
		Label16->Caption = kvadrat.centerMassY();

	}
}

void __fastcall TForm2::Button35Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			kvadrat.moveDownCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label15->Caption = kvadrat.centerMassX();
		Label16->Caption = kvadrat.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button34Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			kvadrat.moveRightCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label15->Caption = kvadrat.centerMassX();
		Label16->Caption = kvadrat.centerMassY();

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button36Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			kvadrat.moveLeftCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label15->Caption = kvadrat.centerMassX();
		Label16->Caption = kvadrat.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button37Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			circle.moveUpCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label13->Caption = circle.centerMassX();
		Label14->Caption = circle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button38Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			circle.moveDownCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label13->Caption = circle.centerMassX();
		Label14->Caption = circle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button40Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			circle.moveLeftCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label13->Caption = circle.centerMassX();
		Label14->Caption = circle.centerMassY();

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::Button39Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			circle.moveRightCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label13->Caption = circle.centerMassX();
		Label14->Caption = circle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button42Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			rectangle.moveUpCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label17->Caption = rectangle.centerMassX();
		Label18->Caption = rectangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button43Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			rectangle.moveDownCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label17->Caption = rectangle.centerMassX();
		Label18->Caption = rectangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button44Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			rectangle.moveRightCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label17->Caption = rectangle.centerMassX();
		Label18->Caption = rectangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button41Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			rectangle.moveLeftCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label17->Caption = rectangle.centerMassX();
		Label18->Caption = rectangle.centerMassY();

	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button45Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.moveUpCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label21->Caption = elips.centerMassX();
		Label22->Caption = elips.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button47Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.moveDownCenterMassY(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label21->Caption = elips.centerMassX();
		Label22->Caption = elips.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button46Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.moveRightCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label21->Caption = elips.centerMassX();
		Label22->Caption = elips.centerMassY();

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button48Click(TObject *Sender) {
	scale = 10;
	if (scale > 0) {
		for (int i = 0; i <= scale; i++) {

			elips.moveLeftCenterMassX(Canvas);

			triangle.draw(Canvas);
			rectangle.draw(Canvas);
			circle.draw(Canvas);
			kvadrat.draw(Canvas);
			elips.draw(Canvas);

			Sleep(30);
		}
		Label21->Caption = elips.centerMassX();
		Label22->Caption = elips.centerMassY();

	}
}
// ---------------------------------------------------------------------------
