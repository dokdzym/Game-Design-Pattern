using System;
using System.Dynamic;

interface IMathFigure : ICloneable
{
    void ShowArea();
}

class Circle : IMathFigure
{
    readonly private float _radius;
    public Circle(float radius)
    {
        _radius = radius;
    }
    public object Clone()
    {
        return new Circle(_radius);
    }
    public void ShowArea()
    {
        Console.WriteLine("Area = {0}", Math.PI * _radius * _radius);
    }
}
class Rectangle : IMathFigure
{
    readonly private float _width;
    readonly private float _length;
    public Rectangle(float width, float length)
    {
        _width = width;
        _length = length;
    }
    public object Clone()
    {
        return new Rectangle(_width, _length);
    }
    public void ShowArea()
    {
        Console.WriteLine("Area = {0}", _width * _length);
    }
}


class Client
{
    static void GetMathFigures()
    {
        Rectangle rect = new Rectangle(3, 4);
        Rectangle rectCloned = (Rectangle)rect.Clone();
        rectCloned.ShowArea();

        Console.WriteLine("***********************************");

        Circle circle = new Circle(1);
        Circle circleCloned = (Circle)circle.Clone();
        circle.ShowArea();
    }
    static void Main()
    {
        GetMathFigures();
    }
}
