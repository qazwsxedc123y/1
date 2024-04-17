using System;

class Student
{
    public int ID;
    public string Name;
    public int Age;

    public Student(int id, string name, int age)
    {
        ID = id;
        Name = name;
        Age = age;
    }
}

class Program
{
    static void Main()
    {
        // 创建两个Student类型的引用变量stu1和stu2
        Student stu1 = new Student(54546, "ars", 20);
        Student stu2 = stu1;

        // 输出显式stu1和stu2的字段值
        Console.WriteLine("stu1: {0} {1} {2}", stu1.ID, stu1.Name, stu1.Age);
        Console.WriteLine("stu2: {0} {1} {2}", stu2.ID, stu2.Name, stu2.Age);

        // 修改stu2的字段值
        stu2.ID = 50152202;
        stu2.Name = "sss";
        stu2.Age = 22;

        // 输出显式stu1和stu2的字段值
        Console.WriteLine("stu1: {0} {1} {2}", stu1.ID, stu1.Name, stu1.Age);
        Console.WriteLine("stu2: {0} {1} {2}", stu2.ID, stu2.Name, stu2.Age);
    }
}