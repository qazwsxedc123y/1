using System;

namespace test_5 
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入三个小数,以空格键为分隔\r\n");
            string s = Console.ReadLine();
            string[] s2 = s.Split(' ');
            double[] a = new double[s2.Length];

            for (int i = 0; i < s2.Length; i++)
            {
                a[i] = Convert.ToDouble(s2[i]);
            }

            Console.WriteLine("\r\n三个数为 {0} {1} {2} ", a[0], a[1], a[2]);
            Console.WriteLine("相加结果为{0}", a[0] + a[1] + a[2]);
            double result = a[0] + a[1] + a[2] + 0.00005;
            int t = Convert.ToInt32(result);
            Console.WriteLine("四舍五入后为：{0}", t);
        }
    }
}