#include<iostream>
using namespace std;

class IMathFigure
{
public:
	virtual IMathFigure* Clone() = 0;
	virtual void ShowArea() = 0;
};

class Circle : IMathFigure
{
private:
	float _radius;
public:
	Circle(float radius)
	{
		_radius = radius;
	}
	IMathFigure* Clone()
	{
		return new Circle(_radius);
	}
	void ShowArea()
	{
		cout << "Area = " << 3.1415926 * _radius * _radius << endl;
	}
};

class Rectangle : IMathFigure
{
private:
	float _width;
	float _length;
public:
	Rectangle(float width, float length)
	{
		_width = width;
		_length = length;
	}
	IMathFigure* Clone()
	{
		return new Rectangle(_width, _length);
	}
	void ShowArea()
	{
		cout << "Area = " << _width * _length << endl;
	}
};


class Client
{
public:
	static void GetMathFigures()
	{
		Rectangle* rect = new Rectangle(3, 4);
		Rectangle* rectCloned = (Rectangle*)rect->Clone();
		rectCloned->ShowArea();

		cout << "***********************************" << endl;

		Circle* circle = new Circle(1);
		Circle* circleCloned = (Circle*)circle->Clone();
		circle->ShowArea();
	}
};

int main() {
	Client::GetMathFigures();
}