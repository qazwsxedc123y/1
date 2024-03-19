using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Circle
{
    private double x1, y1, x2, y2;

    public Circle(double x1, double y1, double x2, double y2)
    {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public double CalculateArea()
    {
        double semiMajorAxis = Math.Abs(x2 - x1) / 2;
        double semiMinorAxis = Math.Abs(y2 - y1) / 2;
        return Math.PI * semiMajorAxis * semiMinorAxis;
    }

    public double CalculatePerimeter()
    {
        double semiMajorAxis = Math.Abs(x2 - x1) / 2;
        double semiMinorAxis = Math.Abs(y2 - y1) / 2;
        return 2 * Math.PI * Math.Sqrt((semiMajorAxis * semiMajorAxis + semiMinorAxis * semiMinorAxis) / 2);
    }
}

class Program
{
    static void Main()
    {
        Circle circle = new Circle(1, 1, 5, 3);
        double area = circle.CalculateArea();
        double perimeter = circle.CalculatePerimeter();

        Console.WriteLine("Area of the circle: {0}",area);
        Console.WriteLine("Perimeter of the circle: {0}", perimeter);
    }
}

//namespace _3_5
//{
//    internal class Program
//    {
//        static void Main(string[] args)
//        {
//            Console.WriteLine("请输入两个操作数：>");
//            string s1=Console.ReadLine();
//            int a = Convert.ToInt32(s1);
//            string s2 = Console.ReadLine();
//            int b = Convert.ToInt32(s2);
//            Console.WriteLine("和：{0},差：{1},积：{2},商：{3},余：{4}",a+b,a-b,a*b,a/b,a%b);
//            Console.ReadKey();
//        }
//    }
//}
