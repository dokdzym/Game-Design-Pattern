using System;
using System.Dynamic;

/*
* How many characters in Adapter pattern?
  1.Adapter, designed to matches Adaptee implements with the Target-interface
  2.Target, raise a request
  3.Adaptee, contains implements which does not fit with Target-interface
* Class-Adapter and Object-Adapter are showed in this .cpp file.
*/

class Adaptee
{
    public void SpecificImplement()
    {
        Console.WriteLine("It's an implement of Adaptee class, cannot be called directly by Target");
    }
};
interface ITarget
{
    void Implement();
};

//Class Adapter
class ClassAdapter : Adaptee, ITarget
{
    public void Implement()
    {
        SpecificImplement();
        Console.WriteLine("Adapter : Now it matches me! ___by ClassAdapter");
    }
};

//Object Adapter
class ObjectAdapter : ITarget
{
    public ObjectAdapter(Adaptee adaptee)
    {
        _adaptee = adaptee;
    }
    public void Implement()
    {
        _adaptee.SpecificImplement();
        Console.WriteLine("Adapter : Now it matches me! ___by ObjectAdapter");
    }
    private Adaptee _adaptee;
};

class Client
{
    static void Main()
    {
        ITarget tClass = new ClassAdapter();
        tClass.Implement();

        Console.WriteLine("**************************");

        ITarget tObj = new ObjectAdapter(new Adaptee());
        tObj.Implement();
    }
}