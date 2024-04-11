using System;

namespace CitizenInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            Citizen member1 = new Citizen();
            member1.Input();
            member1.Print();
        }

        class Citizen
        {
            private string ID;
            private string Name;
            private string Gender;
            private string Age;
            private string Birthplace;
            private string FamilyAddress;

            public void Input()
            {
                Console.WriteLine("身份证号：");
                ID = Console.ReadLine();
                Console.WriteLine("姓名：");
                Name = Console.ReadLine();
                Console.WriteLine("性别：F/M");
                Gender = Console.ReadLine();
                Console.WriteLine("年龄：");
                Age = Console.ReadLine();
                Console.WriteLine("籍贯：");
                Birthplace = Console.ReadLine();
                Console.WriteLine("家庭住址：");
                FamilyAddress = Console.ReadLine();
            }

            public void Print()
            {
                Console.WriteLine("身份证号：" + ID);
                Console.WriteLine("姓名：" + Name);
                Console.WriteLine("性别：" + Gender);
                Console.WriteLine("年龄：" + Age);
                Console.WriteLine("籍贯：" + Birthplace);
                Console.WriteLine("家庭住址：" + FamilyAddress);
            }
        }
    }
}