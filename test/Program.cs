
using System;

namespace a
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int i = int.Parse(Console.ReadLine());
            Person[] people = new Person[i];
            for (int a = 0; a < i; a++)
            {
                int b = int.Parse(Console.ReadLine());
                if (b == 0)
                {
                    string arr = Console.ReadLine();
                    string[] arr1 = arr.Split(' ');
                    int id = int.Parse(arr1[0]);
                    int bir = int.Parse(arr1[2]);
                    double score = double.Parse(arr1[4]);
                    people[a] = new Student(id, arr1[1], bir, arr1[3], score);
                }
                else if (b == 1)
                {
                    string arr = Console.ReadLine();
                    string[] arr1 = arr.Split(' ');
                    int id = int.Parse(arr1[0]);
                    int bir = int.Parse(arr1[2]);
                    double salary = double.Parse(arr1[4]);
                    people[a] = new Teacher(id, arr1[1], bir, arr1[3], salary);
                }
                else
                {
                    break;
                }
            }
            foreach (var item in people)
            {
                Console.WriteLine(item.ToString());

            }
        }
    }
}

public abstract class Person
{
    private int _id;
    private string _name;
    private int _bir;
    public int Id { get; set; }
    public string Name { get; set; }
    public int Bir { get; set; }
    public Person(int id, string name, int bir)
    {
        this.Id = id;
        this.Name = name;
        this.Bir = bir;
    }
}
public class Student : Person
{
    private string _major;
    private double _score;
    public string Major { get; set; }
    public double Score { get; set; }
    public Student(int id, string name) { }
}

//using System;

//// 抽象类Shape
//abstract class Shape
//{
//    // 抽象方法Perimeter
//    public abstract double Perimeter();

//    // 抽象方法Area
//    public abstract double Area();
//}

//// Rectangle类继承自Shape
//class Rectangle : Shape
//{
//    private double w; // 矩形的宽度
//    private double h; // 矩形的高度

//    // 带参构造函数
//    public Rectangle(double width, double height)
//    {
//        w = width;
//        h = height;
//    }

//    // 重写Perimeter方法
//    public override double Perimeter()
//    {
//        return 2 * (w + h);
//    }

//    // 重写Area方法
//    public override double Area()
//    {
//        return w * h;
//    }
//}

//// Circle类继承自Shape
//class Circle : Shape
//{
//    private double r; // 圆的半径

//    // 带参构造函数
//    public Circle(double radius)
//    {
//        r = radius;
//    }

//    // 重写Perimeter方法
//    public override double Perimeter()
//    {
//        return 2 * Math.PI * r;
//    }

//    // 重写Area方法
//    public override double Area()
//    {
//        return Math.PI * r * r;
//    }
//}

//// Main类
//class Program
//{
//    static void Main(string[] args)
//    {
//        // 创建Shape类型的数组
//        Shape[] shapes = new Shape[5];

//        // 实例化Rectangle类的对象并添加到数组
//        shapes[0] = new Rectangle(10.0, 10.0);
//        shapes[1] = new Rectangle(4.0, 4.0);

//        // 实例化Circle类的对象并添加到数组
//        shapes[2] = new Circle(5.0);
//        shapes[3] = new Circle(7.0);
//        shapes[4] = new Circle(9.0);

//        // 遍历数组并调用计算周长和面积的方法
//        foreach (Shape shape in shapes)
//        {
//            Console.WriteLine("周长 " + shape.GetType().Name + ": " + shape.Perimeter());
//            Console.WriteLine("面积 " + shape.GetType().Name + ": " + shape.Area());
//            Console.WriteLine();
//        }
//    }
//}