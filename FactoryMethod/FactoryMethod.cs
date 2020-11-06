using System;

interface IAnimal
{
    void attack();
}

class Bird : IAnimal
{
    public void attack()
    {
        Console.WriteLine("Meow!");
    }
}
class Cat : IAnimal
{
    public void attack()
    {
        Console.WriteLine("Chew!");
    }
}


class Factory
{
	public Bird makeBird()
    {
        return new Bird();
    }
    public Cat makeCat()
    {
        return new Cat();
    }
};
class Client
{
    static void CreatedAndAttack(Factory factory)
    {
        Bird b = factory.makeBird();
        b.attack();

        Cat c = factory.makeCat();
        c.attack();
    }
    static void Main()
    {
        Factory f = new Factory();
        CreatedAndAttack(f);
    }
}
