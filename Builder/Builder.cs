using System;
using System.Linq.Expressions;
using System.Runtime.CompilerServices;

//This design pattern is similiar with Abstract-Factory,But it focus more on diffrent parts built in a single product.

class EngineProduct
{
	public void MakeVoice(string cmd) { _voiceSystem = cmd; }
	public void MakeAnimation(string cmd){ _animationSystem = cmd; }
	public void MakeCollision(string cmd){ _collisionSystem = cmd; }

	public string GetEngine() { return _voiceSystem + _animationSystem + _collisionSystem; }
	public void ShowEngine()
	{
		Console.WriteLine("Voice = {0}", _voiceSystem);
		Console.WriteLine("Animation = {0}", _animationSystem);
		Console.WriteLine("Collision = {0}", _collisionSystem);
	}
	string _voiceSystem { get; set; }
	string _animationSystem { get; set; }
	string _collisionSystem { get; set; }
}

abstract class EngineBuilder
{
	public EngineProduct Get()
	{
		return _engine;
	}

	public abstract void BuildVoice();
	public abstract void BuildAnimation();
	public abstract void BuildCollision();

	public EngineProduct _engine = new EngineProduct();
};

class XEngineBuilder : EngineBuilder
{
	override public void BuildVoice()
	{
		_engine.MakeVoice("X Voice!");
	}

	override public void BuildAnimation()
	{
		_engine.MakeAnimation("X Animation!");
	}

	override public void BuildCollision()
	{
		_engine.MakeCollision("X Collision!");
	}
};

class YEngineBuilder : EngineBuilder
{
	override public void BuildVoice()
	{
		_engine.MakeVoice("Y Voice!");
	}

	override public void BuildAnimation()
	{
		_engine.MakeAnimation("Y Animation!");
	}

	override public void BuildCollision()
	{
		_engine.MakeCollision("Y Collision!");
	}
};

class Director
{
	public void SetBuilder(EngineBuilder builder)
	{
		_builder = builder;
	}

	public EngineProduct GetEngine()
	{
		return _builder.Get();
	}

	public void BuildEngine()
	{
		_builder.BuildVoice();
		_builder.BuildAnimation();
		_builder.BuildCollision();
	}

	public EngineBuilder _builder;
};


class Client
{
	public static void BuildXYEngine()
	{
		Director d = new Director();

		EngineBuilder x = new XEngineBuilder(); //Create a Builder
		d.SetBuilder(x);
		d.BuildEngine();                         //Building...
		EngineProduct engine = d.GetEngine();
		engine.ShowEngine();

		Console.WriteLine("*******************************");

		EngineBuilder y = new YEngineBuilder();
		d.SetBuilder(y);
		d.BuildEngine();
		engine = d.GetEngine();
		engine.ShowEngine();
	}

	static void Main()
    {
		Client.BuildXYEngine();
    }
};
