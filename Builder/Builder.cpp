#include<iostream>
#include<string>
using namespace std;

//This design pattern is similiar with Abstract-Factory,But it focus more on diffrent parts built in a single product.


class EngineProduct {
public:
	~EngineProduct(){}
	void MakeVoice(const string& cmd) { _voiceSystem = cmd; }
	void MakeAnimation(const string& cmd) { _animationSystem = cmd; }
	void MakeCollision(const string& cmd) { _collisionSystem = cmd; }

	string GetEngine() { return _voiceSystem + _animationSystem + _collisionSystem; }
	void ShowEngine() {
		cout << "Voice = " << _voiceSystem << endl;
		cout << "Animation = " << _animationSystem << endl;
		cout << "Collision = " << _collisionSystem << endl;
	}
private:
	//Components in Engine
	string _voiceSystem;
	string _animationSystem;
	string _collisionSystem;
};

class EngineBuilder {
public:
	~EngineBuilder() { 
		if (_engine) {
			delete _engine;
			_engine = nullptr;
		}
	};
	EngineProduct* Get() {
		return _engine;
	};

	virtual void BuildVoice() = 0;
	virtual void BuildAnimation() = 0;
	virtual void BuildCollision() = 0;

protected:
	EngineProduct* _engine = new EngineProduct();
};

class XEngineBuilder : public EngineBuilder {
public:
	void BuildVoice() {
		_engine->MakeVoice("X Voice!");
	};

	void BuildAnimation() {
		_engine->MakeAnimation("X Animation!");
	}

	void BuildCollision() {
		_engine->MakeCollision("X Collision!");
	}
};

class YEngineBuilder : public EngineBuilder {
public:
	void BuildVoice() {
		_engine->MakeVoice("Y Voice!");
	}

	void BuildAnimation() {
		_engine->MakeAnimation("Y Animation!");
	}

	void BuildCollision() {
		_engine->MakeCollision("Y Collision!");
	}
};

class Director {
public:
	~Director(){
		if (_builder) {
			delete _builder;
			_builder = nullptr;
		}
	}
	void SetBuilder(EngineBuilder* builder) {
		if (_builder) delete _builder;
		_builder = builder;
	};

	EngineProduct* GetEngine(){
		return _builder -> Get();
	};

	void BuildEngine() {
		_builder->BuildVoice();
		_builder->BuildAnimation();
		_builder->BuildCollision();
	}

private:
	EngineBuilder* _builder;
};


class Client {
public:
	static void BuildXYEngine() {
		Director d;

		EngineBuilder* x = new XEngineBuilder(); //Create a Builder
		d.SetBuilder(x);
		d.BuildEngine();                         //Building...
		EngineProduct* engine = d.GetEngine();
		engine -> ShowEngine();

		cout << "*******************************" << endl;

		EngineBuilder* y = new YEngineBuilder();
		d.SetBuilder(y);
		d.BuildEngine();
		engine = d.GetEngine();
		engine -> ShowEngine();
	}
};

int main() {
	Client::BuildXYEngine();
}