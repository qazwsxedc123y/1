using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

//namespace ConsoleApp2
//{
//    internal class Program
//    {
//        static void Main(string[] args)
//        {

//            string s = Console.ReadLine();
//            string[] sSplit = s.Split(' ');
//            int max = 0;
//            for (int i = 0; i < 6; i++)
//            {
//                int a = Convert.ToInt32(sSplit[i]);

//                if (a > max)
//                    max = a;
//            }
//            Console.WriteLine("最大的整数为：{0}", max);
//        }
//    }
//}

//康讯通:
//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

//namespace ConsoleApp2
//{
//    internal class Program
//    {
//        static void Main(string[] args)
//        {

//            string s = Console.ReadLine();
//            int a = Convert.ToInt32(s);
//            Console.WriteLine("Celsius = {0}", 5 * (a - 32) / 9);
//        }
//    }
//}

//康讯通:
//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

//namespace ConsoleApp2
//{
//    internal class Program
//    {
//        static void Main(string[] args)
//        {

//            string s = Console.ReadLine();
//            int a = Convert.ToInt32(s);
//            s = Console.ReadLine();
//            int b = Convert.ToInt32(s);
//            Console.WriteLine("{0} + {1} = {2}", a, b, a + b);
//            Console.WriteLine("{0} - {1} = {2}", a, b, a - b);
//            Console.WriteLine("{0} * {1} = {2}", a, b, a * b);
//            Console.WriteLine("{0} / {1} = {2}", a, b, a / b);
//        }
//    }
//}

////using System;
////using System.Collections.Generic;
////using System.Linq;
////using System.Text;
////using System.Threading.Tasks;

////namespace ConsoleApp2
////{
////    internal class Program
////    {
////        static void Main(string[] args)
////        {
////            Console.WriteLine("I'm gonna WIN!");
////            Console.WriteLine("I'm gonna WIN!");
////            Console.WriteLine("I'm gonna WIN!");
////        }
////    }
////}

////using System;
////using System.Collections.Generic;
////using System.Linq;
////using System.Text;
////using System.Threading.Tasks;

////namespace ConsoleApp2
////{
////    internal class Program
////    {
////        static void Main(string[] args)
////        {
////            Console.WriteLine("我爱学习");
////        }
////    }
////}



////using System;
////using System.Collections.Generic;
////using System.Linq;
////using System.Text;
////using System.Threading.Tasks;

////namespace ConsoleApp2
////{
////    internal class Program
////    {
////        static void Main(string[] args)
////        {
////            Console.WriteLine("Hello World!");
////        }
////    }
////}


////class Circle
////{
////    private double x1, y1, x2, y2;

////    public Circle(double x1, double y1, double x2, double y2)
////    {
////        this.x1 = x1;
////        this.y1 = y1;
////        this.x2 = x2;
////        this.y2 = y2;
////    }

////    public double CalculateArea()
////    {
////        double semiMajorAxis = Math.Abs(x2 - x1) / 2;
////        double semiMinorAxis = Math.Abs(y2 - y1) / 2;
////        return Math.PI * semiMajorAxis * semiMinorAxis;
////    }

////    public double CalculatePerimeter()
////    {
////        double semiMajorAxis = Math.Abs(x2 - x1) / 2;
////        double semiMinorAxis = Math.Abs(y2 - y1) / 2;
////        return 2 * Math.PI * Math.Sqrt((semiMajorAxis * semiMajorAxis + semiMinorAxis * semiMinorAxis) / 2);
////    }
////}

////class Program
////{
////    static void Main()
////    {
////        Circle circle = new Circle(1, 1, 5, 3);
////        double area = circle.CalculateArea();
////        double perimeter = circle.CalculatePerimeter();

////        Console.WriteLine("Area of the circle: {0}",area);
////        Console.WriteLine("Perimeter of the circle: {0}", perimeter);
////    }
////}

////namespace _3_5
////{
////    internal class Program
////    {
////        static void Main(string[] args)
////        {
////            Console.WriteLine("请输入两个操作数：>");
////            string s1=Console.ReadLine();
////            int a = Convert.ToInt32(s1);
////            string s2 = Console.ReadLine();
////            int b = Convert.ToInt32(s2);
////            Console.WriteLine("和：{0},差：{1},积：{2},商：{3},余：{4}",a+b,a-b,a*b,a/b,a%b);
////            Console.ReadKey();
////        }
////    }
////}
