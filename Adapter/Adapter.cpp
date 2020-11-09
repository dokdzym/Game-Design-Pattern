#include<iostream>
using namespace std;

/*
* How many characters in Adapter pattern?
  1.Adapter, designed to matches Adaptee implements with the Target-interface
  2.Target, raise a request
  3.Adaptee, contains implements which does not fit with Target-interface
* Class-Adapter and Object-Adapter are showed in this .cpp file.
*/

class Adaptee {
public:
	void SpecificImplement (){
		cout << "It's an implement of Adaptee class, cannot be called directly by Target" << endl;
	}
};
class Target {
public:
	virtual void Implement() {
		cout << "Target Implement needed." << endl;
	}
};

//Class Adapter
class ClassAdapter : public Target, private Adaptee{
public:
	void Implement() {
		SpecificImplement();
		cout << "Adapter : Now it matches me! ___by ClassAdapter" << endl;
	}
};

//Object Adapter
class ObjectAdapter : public Target {
public:
	ObjectAdapter(Adaptee* adaptee) {
		_adaptee = adaptee;
	}
	void Implement() {
		_adaptee->SpecificImplement();
		cout << "Adapter : Now it matches me! ___by ObjectAdapter" << endl;
	}
private:
	Adaptee* _adaptee;
};

int main() {
	Target* tClass = new ClassAdapter();
	tClass -> Implement();

	cout << "**************************" << endl;

	Target* tObj = new ObjectAdapter(new Adaptee());
	tObj -> Implement();
}