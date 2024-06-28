////using System;
////using System.Collections.Generic;
////using System.Linq;
////using System.Text;
////using System.Threading.Tasks;

////namespace _0514例7_1
////{

////        public class Time
////        {
////            private int hour;       // 小时，数据范围0~23
////            private int minute;     // 分，数据范围0~59
////            private int second;     // 秒，数据范围0~59
////            public void SetTime(int hour, int minute, int s)
////            {
////                this.hour = ((hour >= 0 && hour < 24) ? hour : 0);    // 确保hour在有效范围
////                this.minute = ((minute >= 0 && minute < 60) ? minute : 0); 
////                this.second = ((s >= 0 && s < 60) ? s : 0);//this可省略
////            }
////            public string To24hourSystemString()            // 输出24小时制字符串，24小时返回值,父类
////            {
////                return string.Format("{0:D2}:{1:D2}:{2:D2}", hour, minute, second);
////            }

////            public override string ToString()           // 输出12小时制字符串，12小时返回值，子类
////            {
////                return string.Format("{0}:{1:D2}:{2:D2} {3}", ((hour == 0 || hour == 12) ? 12 : hour % 12), minute, second, (hour < 12 ? "AM" : "PM"));
////            }
////        }
////        class Program
////        {
////            static void Main(string[] args)
////            {
////                Time time = new Time();
////                Console.WriteLine("初始的时间：");
////                Console.Write("\t24小时制：");
////                Console.WriteLine(time.To24hourSystemString());
////                Console.Write("\t12小时制：");
////                Console.WriteLine(time.ToString());

////                // 设置新的时间
////                time.SetTime(13, 27, 6);
////                Console.WriteLine("设置的有效时间：");
////                Console.Write("\t24小时制：");
////                Console.WriteLine(time.To24hourSystemString());
////                Console.Write("\t12小时制：");
////                Console.WriteLine(time.ToString());

////                // 设置为无效的时间
////                Console.WriteLine("设置的无效时间：");
////                time.SetTime(99, 99, 99);
////                Console.Write("\t24小时制：");
////                Console.WriteLine(time.To24hourSystemString());
////                Console.Write("\t12小时制：");
////                Console.WriteLine(time);

////        }
////        }
////    }


////using System;

////namespace 1
////{
////    internal class Program
////{
////    static void Main(string[] args)
////    {
////        int i = int.Parse(Console.ReadLine());
////        Person[] people = new Person[i];
////        for (int a = 0; a < i; a++)
////        {
////            int b = int.Parse(Console.ReadLine());
////            if (b == 0)
////            {
////                string arr = Console.ReadLine();
////                string[] arr1 = arr.Split(' ');
////                int id = int.Parse(arr1[0]);
////                int bir = int.Parse(arr1[2]);
////                double score = double.Parse(arr1[4]);
////                people[a] = new Student(id, arr1[1], bir, arr1[3], score);
////            }
////            else
////            {
////                string arr = Console.ReadLine();
////                string[] arr1 = arr.Split(' ');
////                int id = int.Parse(arr1[0]);
////                int bir = int.Parse(arr1[2]);
////                double salary = double.Parse(arr1[4]);
////                people[a] = new Teacher(id, arr1[1], bir, arr1[3], salary);
////            }
////        }
////        foreach (var item in people)
////        {
////            Console.WriteLine(item.ToString());
////        }
////    }
////}

////public abstract class Person
////{
////    private int _id;
////    private string _name;
////    private int _bir;
////    public int Id { get ; set ; }
////    public string Name { get; set; }
////    public int Bir { get; set; }
////    public Person(int id, string name, int bir)
////    {
////        this.Id = id;
////        this.Name = name;
////        this.Bir = bir;
////    }
////}
////public class Student : Person
////{
////    private string _major;
////    private double _score;
////    public string Major { get; set; }
////    public double Score { get; set; }
////    public Student(int id, string name, int bit, string major, double score) : base(id, name, bir)
////    {
////        this._major = major;
////        this._score = score;
////    }
////    public override string ToString()
////    {
////        return $"{Id} {Name} {Bir} {Major} {Score}";
////    }
////}
////public class Teacher : Person
////{
////    private string _title;
////    private double _salary;
////    public string Title { get; set; }
////    public double Salary { get; set; }
////    public Teacher(int id, string name, int bit, string title, double salary) : base(id, name, bir)
////    {
////        this._title = title;
////        this._salary = salary;
////    }
////    public override string ToString()
////    {
////        return $"{Id} {Name} {Bir} {Title} {Salary}";
////    }
////}
////}

//using System;

//namespace YourNamespace
//{
//    internal class Program
//    {
//        static void Main(string[] args)
//        {
//            int i = int.Parse(Console.ReadLine());
//            Person[] people = new Person[i];
//            for (int a = 0; a < i; a++)
//            {
//                int b = int.Parse(Console.ReadLine());
//                if (b == 0)
//                {
//                    string arr = Console.ReadLine();
//                    string[] arr1 = arr.Split(' ');
//                    int id = int.Parse(arr1[0]);
//                    int bir = int.Parse(arr1[2]);
//                    double score = double.Parse(arr1[4]);
//                    people[a] = new Student(id, arr1[1], bir, arr1[3], score);
//                }
//                else
//                {
//                    string arr = Console.ReadLine();
//                    string[] arr1 = arr.Split(' ');
//                    int id = int.Parse(arr1[0]);
//                    int bir = int.Parse(arr1[2]);
//                    double salary = double.Parse(arr1[4]);
//                    people[a] = new Teacher(id, arr1[1], bir, arr1[3], salary);
//                }
//            }
//            foreach (var item in people)
//            {
//                Console.WriteLine(item.ToString());
//            }
//        }
//    }

//    public abstract class Person
//    {
//        public int Id { get; set; }
//        public string Name { get; set; }
//        public int Bir { get; set; }

//        public Person(int id, string name, int bir)
//        {
//            this.Id = id;
//            this.Name = name;
//            this.Bir = bir;
//        }
//    }

//    public class Student : Person
//    {
//        public string Major { get; set; }
//        public double Score { get; set; }

//        public Student(int id, string name, int bir, string major, double score) : base(id, name, bir)
//        {
//            this.Major = major;
//            this.Score = score;
//        }

//        public override string ToString()
//        {
//            return $"Student [id={Id}, name={Name}, bir={Bir}, major={Major}, score={Score}]";
//        }
//    }

//    public class Teacher : Person
//    {
//        public string Title { get; set; }
//        public double Salary { get; set; }

//        public Teacher(int id, string name, int bir, string title, double salary) : base(id, name, bir)
//        {
//            this.Title = title;
//            this.Salary = salary;
//        }

//        public override string ToString()
//        {
//            return $"Teacher [id={Id}, name={Name}, bir={Bir}, title={Title}, salary={Salary:F1}]";
//        }
//    }
//}


using System;

class Vehicle
{
    public virtual void Run()
    {
        Console.WriteLine("Vehicle is running!");
    }

    public virtual void Show()
    {
        Console.WriteLine("I'm a Vehicle.");
    }
}

class Car : Vehicle
{
    public override void Run()
    {
        Console.WriteLine("Car is running!");
    }

    public override void Show()
    {
        Console.WriteLine("I'm a Car.");
        Console.Write("My Base class : ");
        base.Show();       
    }
}

class RaceCar : Car
{
    public override void Run()
    {
        Console.WriteLine("RaceCar is running.");
    }

    public override void Show()
    {
        Console.WriteLine("I'm a RaceCar.");
        Console.Write("My Base class : ");
        base.Show();
    }
}

class Program
{
    static void Main()
    {
        Vehicle vehicle = new Vehicle();
        Car car = new Car();
        RaceCar raceCar = new RaceCar();

        vehicle.Run();
        vehicle.Show();
        Console.WriteLine();

        car.Run();
        car.Show();
        Console.WriteLine();

        raceCar.Run();
        raceCar.Show();
    }
}






