using System;

class Vehicle
{
    public int wheels;
    public double weight;

    public Vehicle(int wheels, double weight)
    {
        this.wheels = wheels;
        this.weight = weight;
    }

    public void Run()
    {
        Console.WriteLine("Running");
    }
}

class Car : Vehicle
{
    public int passenger_load;

    public Car(int wheels, double weight, int passenger_load) : base(wheels, weight)
    {
        this.passenger_load = passenger_load;
    }

    public void Run() 
    {
        Console.WriteLine("Car is running");
    }

    public override string ToString()
    {
        return $"车轮数{wheels}，车重{weight}，车载人数{passenger_load}";
    }
}

class Program
{
    public static void Main()
    {
        int wheels = Convert.ToInt32(Console.ReadLine());
        double weight = Convert.ToDouble(Console.ReadLine());
        int passenger_load = Convert.ToInt32(Console.ReadLine());

        Car myCar = new Car(wheels, weight, passenger_load);

        myCar.Run();
        Console.WriteLine(myCar.ToString());
    }
}