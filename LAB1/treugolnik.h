#include <cmath>

class Treugolnik : Mnogougolnik {
private:
	float x1, y1;
	float x2, y2;
	float x3, y3;

	float square;
	float perimeter;

	float xCenterMass;
	float yCenterMass;

public:
	Treugolnik(float xFirstP, float yFirstP, float xSecondP, float ySecondP,
		float xThirdP, float yThirdP) : x1(xFirstP), y1(yFirstP), x2(xSecondP),
		y2(ySecondP), x3(xThirdP), y3(xThirdP) {
		background = clYellow;
	}

	void draw(TCanvas * Canvas) {

		Canvas->Pen->Color = background;

		Canvas->MoveTo(x1, y1);
		Canvas->LineTo(x2, y2);
		Canvas->LineTo(x3, y3);
		Canvas->LineTo(x1, y1);

		Canvas->Pen->Color = clActiveCaption;

	}

	void hide(TCanvas * Canvas) {
		Canvas->Pen->Color = clActiveCaption;

		Canvas->MoveTo(x1, y1);
		Canvas->LineTo(x2, y2);
		Canvas->LineTo(x3, y3);
		Canvas->LineTo(x1, y1);

		Canvas->Pen->Color = background;
	}

	void prisvoenie(float xFirstP, float yFirstP, float xSecondP,
		float ySecondP, float xThirdP, float yThirdP) {

		this->x1 = xFirstP;
		this->y1 = yFirstP;

		this->x2 = xSecondP;
		this->y2 = ySecondP;

		this->x3 = xThirdP;
		this->y3 = yThirdP;

	}

	float centerMassX() {
		this->xCenterMass = (x1 + x2 + x3) / 3;

		return xCenterMass;

	}

	float centerMassY() {
		this->yCenterMass = (y1 + y2 + y3) / 3;

		return yCenterMass;
	}

	void rotateAtCenter(TCanvas * Canvas) {

		float angleRotate1 = sin(M_PI / 180.0);
		float angleRotate2 = cos(M_PI / 180.0);

		hide(Canvas);

		x1 = xCenterMass + (x1 - xCenterMass) * angleRotate2 -
			(y1 - yCenterMass) * angleRotate1;

		x2 = xCenterMass + (x2 - xCenterMass) * angleRotate2 -
			(y2 - yCenterMass) * angleRotate1;

		x3 = xCenterMass + (x3 - xCenterMass) * angleRotate2 -
			(y3 - yCenterMass) * angleRotate1;

		y1 = yCenterMass + (y1 - yCenterMass) * angleRotate2 +
			(x1 - xCenterMass) * angleRotate1;

		y2 = yCenterMass + (y2 - yCenterMass) * angleRotate2 +
			(x2 - xCenterMass) * angleRotate1;

		y3 = yCenterMass + (y3 - yCenterMass) * angleRotate2 +
			(x3 - xCenterMass) * angleRotate1;

		draw(Canvas);

	}

	void changeScalePlus(TCanvas * Canvas) {
		hide(Canvas);

		x1;
		y1--;

		x2++;
		y2++;

		x3--;
		y3++;

		draw(Canvas);
	}

	void changeScaleMinus(TCanvas * Canvas) {
		hide(Canvas);

		x1;
		y1++;

		x2--;
		y2--;

		x3++;
		y3--;

		draw(Canvas);
	}

	float getSquare() {

		this->square =
			(abs((((x2 - x1) * (y3 - y1)) - ((x3 - x1) * (y2 - y1))))) / 2;

		return square;
	}

	float getPerimeter() {
		this->perimeter = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) +
			sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)) +
			sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

		return perimeter;

	}

	void moveRightCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x1++;
		x2++;
		x3++;
		draw(Canvas);
	}

	void moveLeftCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x1--;
		x2--;
		x3--;
		draw(Canvas);
	}

	void moveUpCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y1--;
		y2--;
		y3--;
		draw(Canvas);
	}

	void moveDownCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y1++;
		y2++;
		y3++;
		draw(Canvas);
	}

	~Treugolnik() {
	}

};
