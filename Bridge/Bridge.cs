using System;
using System.Dynamic;

/*
* How many characters in Bridge pattern?
  1.Abstraction: Defines a interface which contains all methods Client needs.
  2.RefinedAbstraction: Extends the interface of Abstraction.
  3.Implementor: Implements the interface of Abstraction.
  4.ConcreteImplementor: Extends the interface of Implementor.

* How?
  An instance of Implementor* is held by Abstraction.

* Attention!
  You don't really need Abstraction if you only need a single version of interface for Client.
*/

abstract class Implementor
{
	public abstract void Print(string str);
};

class ConcreteImplementorA : Implementor {
	public override void Print(string str)
	{
		Console.WriteLine("{0}  , It's AAAAAAAAA", str);
	}
};

class ConcreteImplementorB : Implementor
{
	public override void Print(string str)
	{
		Console.WriteLine("{0}  , It's BBBBBBBBB", str);
	}
};

abstract class Abstraction
{
	public Implementor GetImplementor() { return _imp; }
	public abstract void Action(string str);
	protected Implementor _imp;
};

class RefinedAbstractionA : Abstraction
{
	public RefinedAbstractionA(Implementor imp) { _imp = imp; }
	public override void Action(string str)
	{
		Implementor imp = GetImplementor();
		imp.Print(str);
	}
};

//Double Print
class RefinedAbstractionB : Abstraction
{
	public RefinedAbstractionB(Implementor imp) { _imp = imp; }
	public override void Action(string str)
	{
		Implementor imp = GetImplementor();
		imp.Print(str);
		imp.Print(str);
	}
};


class Client
{
    static void Main()
    {
		Implementor a = new ConcreteImplementorA();
		Implementor b = new ConcreteImplementorB();

		Abstraction A = new RefinedAbstractionA(a);
		Abstraction B = new RefinedAbstractionB(b);

		A.Action("AAA: ");
		Console.WriteLine("**************************");
		B.Action("BBB: ");
	}
}