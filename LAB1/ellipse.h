#include <cmath>

class Ellipse : public Krug {
private:

	float x1, y1;
	float x2, y2;
	float x3, y3;
	float x4, y4;

	float square;
	float ellipseLenght;

	float xCenterMass;
	float yCenterMass;

	float radiusKrug, xCenter, yCenter;

public:

	Ellipse(float xLC, float yLC, float xRC, float yRC /* , float x3RC,
		 float y3RC, float x4LC, float y4LC */)
		: Krug(xCenter, yCenter, radiusKrug) {

		x2 = xRC;
		y2 = yRC;
		// x3 = x3RC;
		// y3 = y3RC;
		// x4 = x4LC;
		// y4 = y4LC;

		background = clYellow;
	}

	void prisvoenie(float xLC, float yLC, float xRC, float yRC /* , float x3RC,
		 float y3RC, float x4LC, float y4LC */) {

		this->x1 = xLC;
		this->y1 = yLC;

		this->x2 = xRC;
		this->y2 = yRC;

		this->x3 = 100;
		this->y3 = 200;

		this->x4 = 500;
		this->y4 = 200;

	}

	void hide(TCanvas * Canvas) {
		Canvas->Pen->Color = clActiveCaption;

		//
		// Canvas->Arc(x1, y1, x2, y2, x3, y3, x4, y4);
		// Canvas->Arc(x1, y1, x2, y2, x4, y4, x3, y3);

		Canvas->Ellipse(x1, y1, x2, y2);

		// Canvas->Pen->Color = clActiveCaption;

	}

	void draw(TCanvas * Canvas) {
		Canvas->Pen->Color = background;
		Canvas->Ellipse(x1, y1, x2, y2);

		// Canvas->Arc(x1, y1, x2, y2, x3, y3, x4, y4);

		// Canvas->Arc(x1, y1, x2, y2, x4, y4, x3, y3);

		// Canvas->Arc(x1, y1, x2, y2, x2, y1, x1, y2);

		Canvas->Pen->Color = clActiveCaption;

	}

	float getSquare() {
		this->square =
			M_PI * ((((x2 - x1) / 2.0) + x1) * (((y2 - y1) / 2.0) + y1));
		return square;
	}

	float getLenght() {
		this->ellipseLenght =
			M_PI * ((((x2 - x1) / 2.0) + x1) + (((y2 - y1) / 2.0) + y1));
		return ellipseLenght;
	}

	float centerMassX() {
		this->xCenterMass = ((x2 - x1) / 2.0) + x1;

		return xCenterMass;

	}

	float centerMassY() {
		this->yCenterMass = ((y2 - y1) / 2.0) + y1;

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

		y1 = yCenterMass + (((y1 - yCenterMass) * angleRotate2) +
			((x1 - xCenterMass) * angleRotate1));

		y2 = yCenterMass + (((y2 - yCenterMass) * angleRotate2) +
			((x2 - xCenterMass) * angleRotate1));

		draw(Canvas);
	}

	void changeScalePlus(TCanvas * Canvas) {
		hide(Canvas);

		x1--;
		y1--;

		x2++;
		y2++;

		draw(Canvas);
	}

	void changeScaleMinus(TCanvas * Canvas) {
		hide(Canvas);

		x1++;
		y1++;

		x2--;
		y2--;

		draw(Canvas);
	}

	void changeScalePlusRadiusHorizontal(TCanvas * Canvas) {
		hide(Canvas);

		x1--;

		x2++;

		draw(Canvas);
	}

	void changeScaleMinusRadiusHorizontal(TCanvas * Canvas) {
		hide(Canvas);

		x1++;

		x2--;

		draw(Canvas);
	}

	void changeScalePlusRadiusVertical(TCanvas * Canvas) {
		hide(Canvas);

		y1--;

		y2++;

		draw(Canvas);
	}

	void changeScaleMinusRadiusVertical(TCanvas * Canvas) {
		hide(Canvas);

		y1++;

		y2--;

		draw(Canvas);
	}

	void moveRightCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x1++;
		x2++;
		draw(Canvas);
	}

	void moveLeftCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x1--;
		x2--;
		draw(Canvas);
	}

	void moveUpCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y1--;
		y2--;
		draw(Canvas);
	}

	void moveDownCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y1++;
		y2++;
		draw(Canvas);
	}

	~Ellipse() {
	}

};
