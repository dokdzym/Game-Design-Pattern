#include<iostream>
using namespace std;

/*
* When to use?
* Sometimes when you want only one instance in your codes. For example, you may need a StateManager/TimeManager etc.
*/
class Singleton {
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator= (const Singleton&) = delete;
	static Singleton* Instance() {
		if (nullptr == _instance) {
			//should lock in multi-thread environment 
			_instance = new Singleton();
		}
		return _instance;
	}

	void ChangeValue(const int& desiredValue) { value = desiredValue; }
	void PrintValue() { cout << value << endl; }
private:
	Singleton() { value = 1; }
	static Singleton* _instance;
	//Any data you want to keep
	int value;
};
Singleton* Singleton::_instance = nullptr;
int main() {
	Singleton* instance = Singleton::Instance();           //The only way to get an instance of Singleton*
	//Singleton* instance2 = new Singleton();              //Cannot get instance with new Singleton()

	Singleton* instance2 = Singleton::Instance();          //Can we get another instance ? Check it in below codes
	instance->PrintValue();                                //1
	instance2->ChangeValue(2);
	instance->PrintValue();                                //2
}