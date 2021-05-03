void sun(TCanvas * Canvas) {
	Canvas->Pen->Color = clWebOrange;
	Canvas->Brush->Color = clWebOrange;
	Canvas->Ellipse(-50, -50, 100, 100);

}

void sea(TCanvas * Canvas) {
	Canvas->Pen->Color = clWebCornFlowerBlue;
	Canvas->Brush->Color = clWebCornFlowerBlue;
	Canvas->Rectangle(0, 314, 500, 280);

}

class rectangleFather {
protected:
	int x1, y1, x2, y2;

	TColor background = clWebSaddleBrown;

public:

	rectangleFather(int xLC, int yLC, int xRC, int yRC) {
		x1 = xLC;
		y1 = yLC;
		x2 = xRC;
		y2 = yRC;

	}

	void hide(TCanvas * Canvas) {

		Canvas->Brush->Color = clGradientInactiveCaption;
		Canvas->FillRect(Rect(x1, y1, x2, y2));

		Canvas->Pen->Color = clGradientInactiveCaption;
		Canvas->Rectangle(x1, y1, x2, y2);

	}

	void show(TCanvas * Canvas)

	{
		Canvas->Pen->Color = background;
		Canvas->Rectangle(x1, y1, x2, y2);

		Canvas->Brush->Color = background;
		Canvas->FillRect(Rect(x1, y1, x2, y2));

	}

	void moveRight(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{
		if (this->x2 == 500) {
		}
		else {
			hide(Canvas);
			x1 += xLC;
			y1 += yLC;
			x2 += xRC;
			y2 += yRC;
			show(Canvas);
		}

	}

	void moveLeft(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{
		if (this->x1 == 0) {

		}
		else {
			hide(Canvas);
			x1 -= xLC;
			y1 -= yLC;
			x2 -= xRC;
			y2 -= yRC;
			show(Canvas);

		}

	}

	~rectangleFather() {
	}

};

class flagShtock : public rectangleFather {
public:
	flagShtock(int xLC, int yLC, int xRC, int yRC)
		: rectangleFather(xLC, yLC, xRC, yRC) {
		background = clWebBurlywood;
	}

	void moveRight(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{

		if (this->x2 == 410) {
		}
		else {
			hide(Canvas);
			x1 += xLC;
			y1 += yLC;
			x2 += xRC;
			y2 += yRC;
			show(Canvas);
		}

	}

	void moveLeft(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{

		if (this->x1 == 95) {

		}
		else {
			hide(Canvas);
			x1 -= xLC;
			y1 -= yLC;
			x2 -= xRC;
			y2 -= yRC;
			show(Canvas);

		}

	}

	~flagShtock() {
	}

};

class flag : public rectangleFather {
public:
	flag(int xLC, int yLC, int xRC, int yRC)
		: rectangleFather(xLC, yLC, xRC, yRC) {
		background = clWebLightSkyBlue;
	}

	void moveRight(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{

		if (this->x2 == 320) {
		}
		else {
			hide(Canvas);
			x1 += xLC;
			y1 += yLC;
			x2 += xRC;
			y2 += yRC;
			show(Canvas);
		}

	}

	void moveLeft(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{
		if (this->x1 == 110) {

		}
		else {
			hide(Canvas);
			x1 -= xLC;
			y1 -= yLC;
			x2 -= xRC;
			y2 -= yRC;
			show(Canvas);
		}

	}

	void moveUp(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{

		if (this->y1 == 150) {

		}
		else {
			hide(Canvas);
			x1 -= xLC;
			y1 -= yLC;
			x2 -= xRC;
			y2 -= yRC;
			show(Canvas);

		}

	}

	void moveDown(TCanvas * Canvas, int xLC, int yLC, int xRC, int yRC)

	{

		if (this->y2 == 190) {
		}
		else {
			hide(Canvas);
			x1 += xLC;
			y1 += yLC;
			x2 += xRC;
			y2 += yRC;
			show(Canvas);
		}

	}

	~flag() {
	}

};
