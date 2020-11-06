#include<iostream>
using namespace std;

class Animal {
public:
	virtual void attack() = 0;
};

//Concrete Product
class Bird : public Animal {
public:
	void attack() {
		cout << "Chew!" << endl;
	}
};

//Concrete Product
class Cat : public Animal {
public:
	void attack() {
		cout << "Meow!" << endl;
	}
};

//Abstract Factory
class Factory {
public:
	Bird* makeBird() {
		return new Bird();
	}
	Cat* makeCat() {
		return new Cat();
	}
};


//Client call this
void CreatedAndAttack(Factory* factory) {
	Bird* b = factory->makeBird();
	b->attack();

	Cat* c = factory->makeCat();
	c->attack();
}
int main() {
	Factory* f = new Factory();
	CreatedAndAttack(f);
	//Chew！
	//Meow！
}