#include<iostream>
using namespace std;
/*
* Abstract Factory
* What do client wants?
*		He wants to get enemies of a specified color without knowing how it works.

* How do we do?
*		We send a factory object to client, and he gets EVERYTHING!

* What's the advantage of this pattern?
*		We seperate products and client.

* What's the disadvantage of this pattern?
*	    We can hardly add a new color or a new kind of animal.
*/

//Abstract Product
class Bird {
public:
	virtual void attack() = 0;
};

//Concrete Product
class YellowBird : public Bird {
public:
	void attack() {
		cout << "Yellow Chew!" << endl;
	}
};

//Concrete Product
class GreenBird : public Bird {
public:
	void attack() {
		cout << "Green Chew!" << endl;
	}
};


class Cat {
	virtual void attack() = 0;
};

//Concrete Product
class YellowCat : public Cat {
public:
	void attack() {
		cout << "Yellow Meow!" << endl;
	}
};

//Concrete Product
class GreenCat : public Cat {
public:
	void attack() {
		cout << "Green Meow!" << endl;
	}
};


//Abstract Factory
class AbstractFactory {
public :
	virtual Bird* makeBird() = 0;
	virtual Cat* makeCat()  = 0;
};

//Concrete Factory
class YellowFactory : public AbstractFactory{
	Bird* makeBird() {
		return new YellowBird();
	}
	Cat* makeCat() {
		return new YellowCat();
	}
};
//Concrete Factory
class GreenFactory : public AbstractFactory {
	Bird* makeBird() {
		return new GreenBird();
	}
	Cat* makeCat() {
		return new GreenCat();
	}
};

//Client call this
void CreatedAndAttack(AbstractFactory* factory) {
	Bird* b = factory->makeBird();
	b->attack();

	Cat* c = factory->makeCat();
	b->attack();
}
int main() {
	YellowFactory* f = new YellowFactory();
	CreatedAndAttack(f);
	//Meow！

	cout << "-----------------------------" << endl;
	GreenFactory* f1 = new GreenFactory();
	CreatedAndAttack(f1);
	//Chew！
}