using System;
using System.Dynamic;

/*
* When to use?
* Sometimes when you want only one instance in your codes. For example, you may need a StateManager/TimeManager etc.
*/
class Singleton
{
    public static Singleton Instance()
    {
        if (_instance == null)
        {
            //should lock in multi-thread environment 
            _instance = new Singleton();
        }
        return _instance;
    }

    public void ChangeValue(int desiredValue)
    {
        value = desiredValue;
    }
    public void PrintValue() { Console.WriteLine("value = {0}", value); }
    private Singleton() { value = 1; }
    //Any data you want to keep
    private int value;
    private static Singleton _instance;
}
//Singleton Singleton._instance = nullptr;
class Client
{
    static void Main()
    {
        Singleton instance = Singleton.Instance();             //The only way to get an instance of Singleton*
        //Singleton* instance2 = new Singleton();              //Cannot get instance with new Singleton()

        Singleton instance2 = Singleton.Instance();            //Can we get another instance ? Check it in below codes
        instance.PrintValue();                                 //1
        instance2.ChangeValue(2);
        instance.PrintValue();                                 //2
    }
}