class Mnogougolnik {
public:
	float getSquare();
	float getPerimeter();
	float draw();
	float hide();
	float prisvoenie();
	float centerMassX();
	float centerMassY();
	void rotateAtCenter();
	void changeScalePlus();
	void changeScaleMinus();
	void moveRightCenterMassX();
	void moveLeftCenterMassX();
	void moveUpCenterMassY();
	void moveDownCenterMassY();

	TColor background = clWebSaddleBrown;
};
