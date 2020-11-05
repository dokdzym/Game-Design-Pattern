using System;

namespace AbstractFactory
{
    interface IBird
    {
        abstract void attack();
    }

    class YellowBird : IBird
    {
        public void attack()
        {
            Console.WriteLine("Yellow Chew!");
        }
    }

    class GreenBird : IBird
    {
        public void attack()
        {
            Console.WriteLine("Green Chew!");
        }
    }


    interface ICat
    {
        abstract void attack();
    }

    class YellowCat : ICat
    {
        public void attack()
        {
            Console.WriteLine("Yellow Meow!");
        }
    }

    class GreenCat : ICat
    {
        public void attack()
        {
            Console.WriteLine("Green Meow!");
        }
    }

    interface IFactory
    {
        IBird makeBird();
        ICat makeCat();
    }

    class YellowFactory : IFactory
    {
        public IBird makeBird()
        {
            return new YellowBird();
        }
        public ICat makeCat()
        {
            return new YellowCat();
        }
    }

    class GreenFactory : IFactory
    {
        public IBird makeBird()
        {
            return new GreenBird();
        }
        public ICat makeCat()
        {
            return new GreenCat();
        }
    }

    class Client
    {
        //Client call this
        static void CreatedAndAttack(IFactory factory)
        {
            IBird b = factory.makeBird();
            b.attack();

            ICat c = factory.makeCat();
            c.attack();
        }
        static void Main()
        {
            IFactory f = new YellowFactory();
            CreatedAndAttack(f);
            //Meow！

            Console.WriteLine("-----------------------------");
            IFactory f1 = new GreenFactory();
            CreatedAndAttack(f1);
            //Chew！
        }
    }
}