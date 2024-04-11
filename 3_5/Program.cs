using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

string str = "a123bc456d";

​

​            string result = " ";

​

​            for (int i = 0; str[i] >= 'a' && str[i] <= 'z'; i += 1)

​

​            {

​

​                result = str[i] + result;

​

​                Console.WriteLine(result);

​

​            }
//namespace mine
//{ 
//    internal class Program
//    {
//        static void Main(string[] args)
//        {
//            Box box1 = new Box(5, 6, 7);
//            Console.WriteLine("例1:");
//            box1.Printf();
//            box1.PrintfObjNum();

//            Box box2 = new Box(8, 8, 8);
//            Console.WriteLine("例2:");
//            box2.Printf();
//            box2.PrintfObjNum();

//            Box box3 = new Box(9, 6, 15);
//            Console.WriteLine("例3:");
//            box3.Printf();
//            box3.PrintfObjNum();
//        }
//    }
//    class Box
//    {
//        private decimal x, y, z;
//        static int objNum = 1;

//        public Box(decimal a, decimal b, decimal c)
//        {
//            x = a; y = b; z = c;
//        }
//        public void PrintfObjNum()
//        {
//            Console.WriteLine(":" + objNum);
//            Console.WriteLine("\r\n");
//            objNum += 1;
//        }
//        public decimal S()
//        {
//            return x * y * z;
//        }
//        public decimal V()
//        {
//            return 2 * (x * y + x * z + y * z);
//        }
//        public void Printf()
//        {
//            if (x == y && y == z)
//                Console.Write("正方体,");
//            else
//            {
//                Console.Write("长方体,");
//            }
//            Console.WriteLine("长={0}宽={1}高={2}", x, y, z);
//            Console.WriteLine("S={0}，V={1}", S(), V());
//        }
//    }
//}


//using System;

//public class Student
//{
//    public int ID { get; set; }
//    public string Name { get; set; }

//    public Student(int id, string name)
//    {
//        ID = id;
//        Name = name;
//    }

//    public void Print()
//    {
//        Console.WriteLine($"Student ID: {ID}, Name: {Name}");
//    }
//}

//class Program
//{
//    static void Main()
//    {
//        Student student = new Student(230208, "songyaohui");
//        student.Print();
//    }
//}

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
