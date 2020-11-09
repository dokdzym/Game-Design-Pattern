#include<iostream>
using namespace std;

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

class Implementor {
public:
	~Implementor() {};
	virtual void Print(const string& str) = 0;
};

class ConcreteImplementorA : public Implementor {
public:
	void Print(const string& str) {
		cout << str << "  , It's AAAAAAAAA" << endl;
	}
};

class ConcreteImplementorB : public Implementor {
public:
	void Print(const string& str) {
		cout << str << "  , It's BBBBBBBBB" << endl;
	}
};

class Abstraction {
public:
	virtual ~Abstraction() {}
	virtual Implementor* GetImplementor() { return _imp; }
	virtual void Action(const string& str) = 0;
protected:
	Implementor* _imp;
};

class RefinedAbstractionA : public Abstraction {
public:
	RefinedAbstractionA(Implementor* imp) { _imp = imp; }
	void Action(const string& str) {
		Implementor* imp = GetImplementor();
		imp->Print(str);
	}
};

//Double Print
class RefinedAbstractionB : public Abstraction {
public:
	RefinedAbstractionB(Implementor* imp) { _imp = imp; }
	void Action(const string& str) {
		Implementor* imp = GetImplementor();
		imp->Print(str);
		imp->Print(str);
	}
};

int main() {
	Implementor* a = new ConcreteImplementorA();
	Implementor* b = new ConcreteImplementorB();

	Abstraction* A = new RefinedAbstractionA(a);
	Abstraction* B = new RefinedAbstractionB(b);

	A->Action("AAA: ");
	cout << "**************************" << endl;
	B->Action("BBB: ");

	delete a;
	delete b;
	delete A;
	delete B;
}