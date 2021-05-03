#include <cmath>

class Pryamougolnik : public Mnogougolnik {
private:
	float x1, y1;
	float x2, y2;

	float x3, y3;
	float x4, y4;

	float square;
	float perimetr;

	float xCenterMass;
	float yCenterMass;

public:
	Pryamougolnik(float xFirstP, float yFirstP, float xSecondP, float ySecondP,
		float xThirdP, float yThirdP, float xFourthP, float yFourthP)
		: x1(xFirstP), y1(yFirstP), x2(xSecondP), y2(ySecondP), x3(xThirdP),
		y3(yThirdP), x4(xFourthP), y4(yFourthP) {

		background = clRed;

	}

	void prisvoenie(float xFirst, float yFirst, float xSecond, float ySecond) {

		this->x1 = xFirst;
		this->y1 = yFirst;

		this->x2 = xSecond;
		this->y2 = yFirst;

		this->x3 = xSecond;
		this->y3 = ySecond;

		this->x4 = xFirst;
		this->y4 = ySecond;

	}

	void hide(TCanvas * Canvas) {

		Canvas->Pen->Color = clActiveCaption;

		Canvas->MoveTo(x1, y1);
		Canvas->LineTo(x2, y2);
		Canvas->LineTo(x3, y3);
		Canvas->LineTo(x4, y4);
		Canvas->LineTo(x1, y1);

		Canvas->Pen->Color = clActiveCaption;

	}

	void draw(TCanvas * Canvas) {

		Canvas->Pen->Color = background;

		Canvas->MoveTo(x1, y1);
		Canvas->LineTo(x2, y2);
		Canvas->LineTo(x3, y3);
		Canvas->LineTo(x4, y4);
		Canvas->LineTo(x1, y1);

		Canvas->Pen->Color = clActiveCaption;

	}

	float getSquare() {
		this->square = abs((x2 - x1)) * abs((y3 - y1));
		return square;
	}

	float getPerimeter() {
		this->perimetr = (abs((x2 - x1)) + abs((y3 - y1))) * 2;
		return perimetr;
	}

	float centerMassX() {
		this->xCenterMass = ((x2 - x1) / 2.0) + x1;

		return xCenterMass;

	}

	float centerMassY() {
		this->yCenterMass = ((y3 - y1) / 2.0) + y1;

		return yCenterMass;
	}

	void rotateAtCenter(TCanvas * Canvas) {

		float angleRotate1 = sin(M_PI / 180.0);
		float angleRotate2 = cos(M_PI / 180.0);

		hide(Canvas);

		x1 = xCenterMass + (((x1 - xCenterMass) * angleRotate2) -
			((y1 - yCenterMass) * angleRotate1));

		x2 = xCenterMass + (((x2 - xCenterMass) * angleRotate2) -
			((y2 - yCenterMass) * angleRotate1));

		x3 = xCenterMass + (((x3 - xCenterMass) * angleRotate2) -
			((y3 - yCenterMass) * angleRotate1));

		x4 = xCenterMass + (((x4 - xCenterMass) * angleRotate2) -
			((y4 - yCenterMass) * angleRotate1));

		y1 = yCenterMass + (((y1 - yCenterMass) * angleRotate2) +
			((x1 - xCenterMass) * angleRotate1));

		y2 = yCenterMass + (((y2 - yCenterMass) * angleRotate2) +
			((x2 - xCenterMass) * angleRotate1));

		y3 = yCenterMass + (((y3 - yCenterMass) * angleRotate2) +
			((x3 - xCenterMass) * angleRotate1));

		y4 = yCenterMass + (((y4 - yCenterMass) * angleRotate2) +
			((x4 - xCenterMass) * angleRotate1));

		draw(Canvas);

	}

	void changeScalePlus(TCanvas * Canvas) {
		hide(Canvas);

		x1--;
		y1--;

		x2++;
		y2--;

		x3++;
		y3++;

		x4--;
		y4++;

		draw(Canvas);
	}

	void changeScaleMinus(TCanvas * Canvas) {
		hide(Canvas);

		x1++;
		y1++;

		x2--;
		y2++;

		x3--;
		y3--;

		x4++;
		y4--;

		draw(Canvas);
	}

	void moveRightCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x1++;
		x2++;
		x3++;
		x4++;
		draw(Canvas);
	}

	void moveLeftCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x1--;
		x2--;
		x3--;
		x4--;
		draw(Canvas);
	}

	void moveUpCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y1--;
		y2--;
		y3--;
		y4--;
		draw(Canvas);
	}

	void moveDownCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y1++;
		y2++;
		y3++;
		y4++;
		draw(Canvas);
	}

	~Pryamougolnik() {
	}

};
