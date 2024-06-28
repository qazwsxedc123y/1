
////////////using System;

////////////namespace a
////////////{
////////////    internal class Program
////////////    {
////////////        static void Main(string[] args)
////////////        {
////////////            int i = int.Parse(Console.ReadLine());
////////////            Person[] people = new Person[i];
////////////            for (int a = 0; a < i; a++)
////////////            {
////////////                int b = int.Parse(Console.ReadLine());
////////////                if (b == 0)
////////////                {
////////////                    string arr = Console.ReadLine();
////////////                    string[] arr1 = arr.Split(' ');
////////////                    int id = int.Parse(arr1[0]);
////////////                    int bir = int.Parse(arr1[2]);
////////////                    double score = double.Parse(arr1[4]);
////////////                    people[a] = new Student(id, arr1[1], bir, arr1[3], score);
////////////                }
////////////                else if (b == 1)
////////////                {
////////////                    string arr = Console.ReadLine();
////////////                    string[] arr1 = arr.Split(' ');
////////////                    int id = int.Parse(arr1[0]);
////////////                    int bir = int.Parse(arr1[2]);
////////////                    double salary = double.Parse(arr1[4]);
////////////                    people[a] = new Teacher(id, arr1[1], bir, arr1[3], salary);
////////////                }
////////////                else
////////////                {
////////////                    break;
////////////                }
////////////            }
////////////            foreach (var item in people)
////////////            {
////////////                Console.WriteLine(item.ToString());

////////////            }
////////////        }
////////////    }
////////////}

////////////public abstract class Person
////////////{
////////////    private int _id;
////////////    private string _name;
////////////    private int _bir;
////////////    public int Id { get; set; }
////////////    public string Name { get; set; }
////////////    public int Bir { get; set; }
////////////    public Person(int id, string name, int bir)
////////////    {
////////////        this.Id = id;
////////////        this.Name = name;
////////////        this.Bir = bir;
////////////    }
////////////}
////////////public class Student : Person
////////////{
////////////    private string _major;
////////////    private double _score;
////////////    public string Major { get; set; }
////////////    public double Score { get; set; }
////////////    public Student(int id, string name) { }
////////////}

////////////using System;

////////////// 抽象类Shape
////////////abstract class Shape
////////////{
////////////    // 抽象方法Perimeter
////////////    public abstract double Perimeter();

////////////    // 抽象方法Area
////////////    public abstract double Area();
////////////}

////////////// Rectangle类继承自Shape
////////////class Rectangle : Shape
////////////{
////////////    private double w; // 矩形的宽度
////////////    private double h; // 矩形的高度

////////////    // 带参构造函数
////////////    public Rectangle(double width, double height)
////////////    {
////////////        w = width;
////////////        h = height;
////////////    }

////////////    // 重写Perimeter方法
////////////    public override double Perimeter()
////////////    {
////////////        return 2 * (w + h);
////////////    }

////////////    // 重写Area方法
////////////    public override double Area()
////////////    {
////////////        return w * h;
////////////    }
////////////}

////////////// Circle类继承自Shape
////////////class Circle : Shape
////////////{
////////////    private double r; // 圆的半径

////////////    // 带参构造函数
////////////    public Circle(double radius)
////////////    {
////////////        r = radius;
////////////    }

////////////    // 重写Perimeter方法
////////////    public override double Perimeter()
////////////    {
////////////        return 2 * Math.PI * r;
////////////    }

////////////    // 重写Area方法
////////////    public override double Area()
////////////    {
////////////        return Math.PI * r * r;
////////////    }
////////////}

////////////// Main类
////////////class Program
////////////{
////////////    static void Main(string[] args)
////////////    {
////////////        // 创建Shape类型的数组
////////////        Shape[] shapes = new Shape[5];

////////////        // 实例化Rectangle类的对象并添加到数组
////////////        shapes[0] = new Rectangle(10.0, 10.0);
////////////        shapes[1] = new Rectangle(4.0, 4.0);

////////////        // 实例化Circle类的对象并添加到数组
////////////        shapes[2] = new Circle(5.0);
////////////        shapes[3] = new Circle(7.0);
////////////        shapes[4] = new Circle(9.0);

////////////        // 遍历数组并调用计算周长和面积的方法
////////////        foreach (Shape shape in shapes)
////////////        {
////////////            Console.WriteLine("周长 " + shape.GetType().Name + ": " + shape.Perimeter());
////////////            Console.WriteLine("面积 " + shape.GetType().Name + ": " + shape.Area());
////////////            Console.WriteLine();
////////////        }
////////////    }
////////////}


//////////using System;
//////////using System.Reflection.Emit;

//////////namespace a
//////////{
//////////    internal class Program
//////////    {
//////////        static void Main(string[] args)
//////////        {
//////////            int[] scores = new int[5] { 65, 71, 90, 68, 80 };
//////////            scores[!] = ();


//////////            //string s=Console.ReadLine();
//////////            //int x=Convert.ToInt32(s);
//////////            //int sum = 0;
//////////            //for(int i=1;i<=x;i++)
//////////            //{
//////////            //    sum += i;
//////////            //}
//////////            //Console.WriteLine(sum);


//////////            //string s = Console.ReadLine();
//////////            //int x=Convert.ToInt32(s);
//////////            //if (x > 0)
//////////            //{
//////////            //    Console.WriteLine("y=1");
//////////            //}
//////////            //else if (x < 0)
//////////            //{
//////////            //    Console.WriteLine("y=-1");
//////////            //}
//////////            //else
//////////            //{
//////////            //    Console.WriteLine("y=0");
//////////            //}


//////////            //int day = 0;
//////////            //int month = 4;
//////////            //switch(month)
//////////            //{
//////////            //    case 2:
//////////            //        day = 28;
//////////            //        break;
//////////            //    case 3:
//////////            //    case 4:
//////////            //    case 6:
//////////            //    case 9:
//////////            //    case 11:
//////////            //        day = 30;
//////////            //        break;
//////////            //    default:
//////////            //        day = 31;
//////////            //        break;
//////////            //}
//////////            //Console.WriteLine(day);
//////////        }
//////////    }
//////////}

////////using System;
////////using System.Collections.Generic;

////////namespace 数组作业
////////{
////////    internal class Program
////////    {
////////        static void Main(string[] args)
////////        {
////////            Console.WriteLine("请输入10个10~100之间的整数，包含10和100：");
////////            int[] num = new int[10];
////////            HashSet<int> set = new HashSet<int>();
////////            int i = 0;

////////            while (i < 10)
////////            {
////////                int unknown = Convert.ToInt32(Console.ReadLine());

////////                if (unknown >= 10 && unknown <= 100 && !set.Contains(unknown))
////////                {
////////                    set.Add(unknown);
////////                    num[i] = unknown;
////////                    i++;
////////                }
////////                else
////////                {
////////                    Console.WriteLine("输入有误，请重新输入！");
////////                }
////////            }

////////            foreach (int number in num)
////////            {
////////                if (number != 0)
////////                {
////////                    Console.Write("{0:D3} ", number);
////////                }
////////            }
////////        }
////////    }
////////}

////////using System;

////////class p
////////{
////////    static void sort(ref int a,ref int b,ref int c)
////////    {
////////        if (a > b)
////////        {
////////            Swap(ref a, ref b);
////////        }
////////        if (a > c)
////////        {
////////            Swap(ref a, ref c);
////////        }
////////        if (b > c)
////////        {
////////            Swap(ref b, ref c);
////////        }
////////    }
////////    static void Swap(ref int x,ref int y)
////////    {
////////        int temp = x;
////////        x = y;
////////        y = temp;
////////    }
////////    static void Main(string[] args)
////////    {
////////        string[] input = Console.ReadLine().Split(' ');
////////        int num1 = int.Parse(input[0]);
////////        int num2 = int.Parse(input[1]);
////////        int num3 = int.Parse(input[2]);
////////        sort(ref num1,ref num2,ref num3);
////////        Console.WriteLine("{0} {1} {2}", num1, num2, num3);
////////    }
////////}

//////using System;

//////class p
//////{
//////    static void Main()
//////    {
//////        int n = int.Parse(Console.ReadLine());
//////        for (int i = 0; i < n; i++)
//////        {
//////            string[] input = Console.ReadLine().Split(' ');
//////            int max = int.Parse(input[0]);
//////            int min = int.Parse(input[0]);
//////            int sum = 0;
//////            for (int j = 0; j < input.Length; j++)
//////            {
//////                if (max < int.Parse(input[j]))
//////                {
//////                    max = int.Parse(input[j]);
//////                }
//////                if (min > int.Parse(input[j]))
//////                {
//////                    min = int.Parse(input[j]);
//////                }
//////                sum += int.Parse(input[j]);
//////            }
//////            int ave = sum / input.Length;
//////            Console.WriteLine(ave);
//////            int count = 0;
//////            for (int j = 0; j < input.Length; j++)
//////            {
//////                if (int.Parse(input[j]) > ave)
//////                {
//////                    count++;
//////                }
//////            }
//////            Console.WriteLine("{0} {1} {2}", max, min, count); ;
//////        }
//////    }
//////}


////////using System;

////////class Program
////////{
////////    static void Main()
////////    {
////////        int n = int.Parse(Console.ReadLine());

////////        for (int i = 0; i < n; i++)
////////        {
////////            string[] input = Console.ReadLine().Split(' ');
////////            int max = int.Parse(input[0]);
////////            int min = int.Parse(input[0]);
////////            int sum = 0;

////////            for (int j = 0; j < input.Length; j++)
////////            {
////////                int num = int.Parse(input[j]);

////////                if (max < num)
////////                {
////////                    max = num;
////////                }

////////                if (min > num)
////////                {
////////                    min = num;
////////                }

////////                sum += num;
////////            }

////////            int average = sum / input.Length;
////////            int count = 0;

////////            for (int j = 0; j < input.Length; j++)
////////            {
////////                if (int.Parse(input[j]) > average)
////////                {
////////                    count++;
////////                }
////////            }

////////            Console.WriteLine("{0} {1} {2}", max, min, count);
////////        }
////////    }
////////}
///////
////using System;

////class Rectangle
////{
////    private double length;
////    private double width;
////    public double Length
////    {
////        get { return length; }
////        set
////        {
////            if(value > 0.0 && value < 20.0)
////            {
////                length = value;
////            }
////            else
////            {
////                Console.WriteLine("The value you input is not within the required range.");
////            }
////        }
////    }
////    public double Width
////    {
////        get
////        {
////            return width;
////        }
////        set
////        {
////            if (value > 0.0 && value < 20.0)
////                width = value;
////            else
////                Console.WriteLine("The value you input is not within the required range.");
////        }
////    }
////     public double Perimeter
////    {
////        get { return 2 * (length + width); }
////    }
////    public double Area
////    {
////        get { return length * width; }
////    }

////    class Program
////    {
////        static void Main()
////        {
////            string[] input = Console.ReadLine().Split(' ');
////            double l = double.Parse(input[0]);
////            double w = double.Parse(input[1]);

////            Rectangle rect = new Rectangle();
////            rect.Length = l;
////            rect.Width = w;
////            Console.WriteLine($"the perimeter is {rect.Perimeter:F2}，the area is {rect.Area:F2}.");
////        }
////    }
////}

//using System;

//public class SavingAccount
//{
//    private static double annualInterestRate;
//    private double savingBalance;
//    public void CalculateMonthlyInterest()
//    {
//        double monthlyInterest = (annualInterestRate * savingBalance) / 12;
//        savingBalance += monthlyInterest;
//    }
//    public void ModifyInterestRate(double newRate)
//    {
//        savingBalance = newRate;       
//    }
//    public SavingAccount(double savingBalance)
//    {
//        this.savingBalance = savingBalance;
//    }
//    public double GetSavingBalance()
//    {
//        return savingBalance;
//    }
//}
//class Program
//{
//    static void Main()
//    {
//        SavingAccount saver1 = new SavingAccount(2000.0);
//        SavingAccount saver2 = new SavingAccount(3000.0);

//        double newRate = Convert.ToDouble(Console.ReadLine());

//        saver1.ModifyInterestRate(newRate); 

//        Console.WriteLine($"the new interest rate is {newRate:P2}.");

//        saver1.CalculateMonthlyInterest();
//        saver2.CalculateMonthlyInterest();

//        Console.WriteLine($"the balance of the save1 is ${saver1.GetSavingBalance():F2} and the balance of save2 is ${saver2.GetSavingBalance():F2}.");
//    }
//}


//using System;

//class A

//{

//    public int a;

//    public A(int a)

//    {

//        this.a = a;

//    }

//}

//class B : A
//{
//    public int b;
//    public B(int a, int b) : base(a)
//    {
//        this.b = b;
//    }
//}
//class p
//{
//    static void Main()
//    {

//    }
//}


//using System;
//using System.Runtime.ConstrainedExecution;

//class Circle
//{
//    private double r;

//    public double R
//    {
//        get { return r; }
//        set { r = value; }
//    }

//    public Circle(double radius)
//    {
//        r = radius;
//    }

//    public double Area()
//    {
//        return Math.PI * r * r;
//    }
//}

//class Cylinder : Circle
//{
//    private double h;

//    public double H
//    {
//        get { return h; }
//        set { h = value; }
//    }

//    public Cylinder(double radius, double height) : base(radius)
//    {
//        h = height;
//    }

//    public double Volume()
//    {
//        return Area() * h;
//    }
//}

//class Program
//{
//    public static void Main()
//    {
//        int wheels = Convert.ToInt32(Console.ReadLine());
//        double weight = Convert.ToDouble(Console.ReadLine());
//        int passenger_load = Convert.ToInt32(Console.ReadLine());

//        Console.WriteLine("Car is running");
//        Console.WriteLine("车轮数4，车重10000，车载人数5");
//    }
//}

using System;

public class Bubble_sort
{
    public static void BubbleSort(int[]a)
    {
        int b = a.Length;
        for (int i = 0; i < b - 1; i++)//趟数
        {
            int flag = 1;
            for (int j = 0; j < b - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                    flag = 0;

                    //swap(a[i], a[j]);               
                }
            }
            if (flag == 1)
                break;
        }
    }
}

//class Person
//{
//    public string name;
//    public Person(string name)
//    {
//        this.name = name;
//    }
//    public bool Isbool()
//    {
//        return 1==1;
//    }
//}
//class Person
//{
//    private int age;
//    private string name;

//    public Person(int age)
//    {
//        this.age = age;
//        Console.WriteLine(age);
//    }
//    //仅仅将上一个构造的age为默认的18,但name改为0（null）
//    public Person(string name) : this(18)
//    {
//        this.name = name;
//        Console.WriteLine(name);
//    }
//    //仅仅将上一个构造的name改为xian，但是age为默认的0
//    public Person(int age, string name) : this("xian")
//    {
//        Console.WriteLine("我是性别，年龄！");
//    }
//}

//public class Person
//{
//    public string name;

//    public Person(string name)
//    {
//        this.name = name;
//        Console.WriteLine(name);
//    }

//    public virtual void Say()
//    {
//        Console.WriteLine("你在干什么！");
//    }
//}
//public class Person1 : Person
//{
//    public Person1(string name) : base(name)
//    {
//    }
//    public override void Say()
//    {
//        Console.WriteLine("弄啥呢！");
//    }
//}
//public class Person2 : Person1
//{
//    public Person2(string name) : base(name)
//    {
//    }
//    public override void Say()
//    {
//        Console.WriteLine("搞啥呢！");
//    }
//}

//public class Person
//{
//    public string name;

//    public Person()
//    {
//    }

//    public Person(string name)
//    {
//        this.name = name;
//    }

//    public virtual void Say()
//    {
//        Console.WriteLine("我是父类的方法");
//    }


//}
//public class Person1 : Person
//{
//    public Person1(string name)
//    {
//    }

//    public override void Say()
//    {
//        Console.WriteLine("我是子类的方法");
//    }
//}
public class Person
{
    public string name;

    public Person(string name)
    {
        this.name = name;
        Console.WriteLine(name);
    }

    public virtual void Say()
    {
        Console.WriteLine("我是父类的方法");
    }
}
public class Person1 : Person
{
    public Person1(string name) : base(name)
    {
    }
    public override void Say()
    {
        Console.WriteLine("我是子类的方法");
    }
}
class p
{
    static void Main()
    {
        int n = Convert.ToInt32(Console.ReadLine());
        long x = 1;
        long y = 0;
        for (int i = 1; i <= n; i++)
        {
            x *= i;
            y += x;
        }
        Console.WriteLine("sum={0}", y);
        Console.ReadKey();

        //Person1 p1 = new Person1("我是子类");
        //p1.Say();
        //Person p = new Person1("我是父类");
        //p.Say();

        //Person person = new Person("先生");
        //Console.WriteLine(person.name);

        //int[,] arr = new int[,] { { 1, 0, 1 }, { 3, 0, 5 } };
        //for(int i=0;i<arr.GetLength(0);i++)
        //{
        //    for(int j=0;j<arr.GetLength(1);j++)
        //    {
        //        Console.Write("{0} ", arr[i, j]);
        //    }
        //    Console.WriteLine();
        //}

        //Console.WriteLine(arr[1,1]);

        //int[] a = new int[] { 9,5,1,3,7,8,2,4,6,0 };
        //int b=Convert.ToInt32(a.Length);
        //Console.WriteLine(b);
        //Bubble_sort.BubbleSort(a);
        //for (int i=0;i<b;i++)
        //    Console.Write("{0} ", a[i]);

        //int month=Convert.ToInt32(Console.ReadLine());
        ////char c=Convert.ToChar(Console.ReadLine());
        //int day = Convert.ToInt32(Console.ReadLine());
        //if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
        //    Console.WriteLine("白羊座");
        //if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
        //    Console.WriteLine("金牛座");
        //if ((month == 5 && day >= 21) || (month == 6 && day <= 21))
        //    Console.WriteLine("双子座");
        //if ((month == 6 && day >= 22) || (month == 7 && day <= 22))
        //    Console.WriteLine("巨蟹座");
        //if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
        //    Console.WriteLine("狮子座");
        //if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
        //    Console.WriteLine("处女座");
        //if ((month == 9 && day >= 23) || (month == 10 && day <= 23))
        //    Console.WriteLine("天秤座");
        //if ((month == 10 && day >= 24) || (month == 11 && day <= 22))
        //    Console.WriteLine("天蝎座");
        //if ((month == 11 && day >= 23) || (month == 12 && day <= 21))
        //    Console.WriteLine("射手座");
        //if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
        //    Console.WriteLine("魔羯座"); 
        //if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
        //    Console.WriteLine("水瓶座");
        //if ((month == 2 && day >= 19) || (month == 3 && day <= 20))
        //    Console.WriteLine("双鱼座");
        //switch(c)
        //{
        //    case '+':
        //        Console.WriteLine("{0}", a + b);
        //        break;
        //    case '-':
        //        Console.WriteLine("{0}", a - b);
        //        break;
        //    case '*':
        //        Console.WriteLine("{0}", a * b);
        //        break;
        //        case '/':
        //        Console.WriteLine("{0}", a / b);
        //        break;
        //    defaule:
        //        break;
        //}
    }
}



