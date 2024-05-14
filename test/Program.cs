using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0514例7_1
{

    public class Time
    {
        private int hour;       // 小时，数据范围0~23
        private int minute;     // 分，数据范围0~59
        private int second;     // 秒，数据范围0~59
        public void SetTime(int hour, int minute, int s)
        {
            this.hour = ((hour >= 0 && hour < 24) ? hour : 0);    // 确保hour在有效范围
            this.minute = ((minute >= 0 && minute < 60) ? minute : 0);
            this.second = ((s >= 0 && s < 60) ? s : 0);//this可省略
        }


        public string To24hourSystemString()            // 输出24小时制字符串，24小时返回值,父类
        {
            return string.Format("{0:D2}:{1:D2}:{2:D2}", hour, minute, second);
        }
        //public override string ToString()           // 输出12小时制字符串，12小时返回值，子类
        public new string ToString()           // 输出12小时制字符串，12小时返回值，子类
        {
            return string.Format("{0}:{1:D2}:{2:D2} {3}", ((hour == 0 || hour == 12) ? 12 : hour % 12), minute, second, (hour < 12 ? "AM" : "PM"));
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Time time = new Time();
            Console.WriteLine("初始的时间：");
            Console.Write("\t24小时制：");
            Console.WriteLine(time.To24hourSystemString());
            Console.Write("\t12小时制：");
            Console.WriteLine(time.ToString());

            // 设置新的时间
            //time.SetTime(13, 27, 6);
            Console.WriteLine("设置的有效时间：");
            Console.Write("\t24小时制：");
            Console.WriteLine(time.To24hourSystemString());
            Console.Write("\t12小时制：");
            Console.WriteLine(time.ToString());

            // 设置为无效的时间
            Console.WriteLine("设置的无效时间：");
            time.SetTime(99, 99, 99);
            Console.Write("\t24小时制：");
            Console.WriteLine(time.To24hourSystemString());
            Console.Write("\t12小时制：");
            Console.WriteLine(time);
        }
    }
}

