using System;

class Cal
{
    public double CalMi(int a, int b)
    {
        return Math.Pow(a, b);
    }

    public void Print(double result)
    {
        Console.WriteLine(result);
    }
}

class Program
{
    static void Main()
    {
        Cal calculator = new Cal();

        Console.WriteLine("请输入整数a:");
        int a = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("请输入整数b:");
        int b = Convert.ToInt32(Console.ReadLine());

        double result = calculator.CalMi(a, b);
        calculator.Print(result);
    }
}