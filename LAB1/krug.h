#include <cmath>

class Krug {
private:
	float x, y, radius, square, circleLenght;
	float xCenterMass;
	float yCenterMass;

public:

	TColor background = clMoneyGreen;

	Krug(float xCenter, float yCenter, float radiusKrug)
		: x(xCenter), y(yCenter), radius(radiusKrug) {

	}

	void hide(TCanvas * Canvas) {
		Canvas->Pen->Color = clActiveCaption;
		Canvas->Ellipse(x - radius, y - radius, x + radius, y + radius);
		Canvas->Pen->Color = clActiveCaption;

	}

	void draw(TCanvas * Canvas) {
		Canvas->Pen->Color = background;
		Canvas->Ellipse(x - radius, y - radius, x + radius, y + radius);
		Canvas->Pen->Color = clWhite;

	}

	void prisvoenie(float x1, float y1, float radiusKrug) {

		this->x = x1;
		this->y = y1;

		this->radius = radiusKrug;
	}

	float getSquare() {
		this->square = M_PI * pow(radius, 2);
		return square;
	}

	float getLenght() {
		this->circleLenght = 2 * M_PI * radius;
		return circleLenght;
	}

	float centerMassX() {
		this->xCenterMass = x;

		return xCenterMass;

	}

	float centerMassY() {
		this->yCenterMass = y;

		return yCenterMass;
	}

	void changeScalePlus(TCanvas * Canvas) {
		hide(Canvas);

		radius++;

		draw(Canvas);
	}

	void changeScaleMinus(TCanvas * Canvas) {
		hide(Canvas);

		radius--;

		draw(Canvas);
	}

	void moveRightCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x++;

		draw(Canvas);
	}

	void moveLeftCenterMassX(TCanvas * Canvas) {
		hide(Canvas);
		x--;

		draw(Canvas);
	}

	void moveUpCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y--;

		draw(Canvas);
	}

	void moveDownCenterMassY(TCanvas * Canvas) {
		hide(Canvas);
		y++;

		draw(Canvas);
	}

	~Krug() {
	}
};
