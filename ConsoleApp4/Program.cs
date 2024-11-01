//using System;
//using System.Collections.Generic;
//using System.Linq;
//public class Booking
//{
//    public int K { get; set; }
//    public int S { get; set; }
//    public int T { get; set; }
//    public Booking(int k, int s, int t)
//    {
//        K = k;
//        S = s;
//        T = t;
//    }
//    public override string ToString()
//    {
//        return $"({K}, {S}, {T})";
//    }
//}
//public class Request
//{
//    public int S { get; set; }
//    public int T { get; set; }
//    public Request(int s, int t)
//    {
//        S = s;
//        T = t;
//    }
//    public override string ToString()
//    {
//        return $"({S}, {T})";
//    }
//}
//public class Program
//{

//    static List<Booking> MergeBookings(List<Booking> B1, List<Booking> B2)
//    {
//        int i = 0;
//        int j = 0;
//        var B = new List<Booking>();

//        while (i < B1.Count && j < B2.Count)
//        {
//            var k1 = B1[i].K;
//            var s1 = B1[i].S;
//            var t1 = B1[i].T;
//            var k2 = B2[j].K;
//            var s2 = B2[j].S;
//            var t2 = B2[j].T;

//            if (t1 <= s2)
//            {
//                B.Add(new Booking(k1, s1, t1));
//                i++;
//            }
//            else if (t2 <= s1)
//            {
//                B.Add(new Booking(k2, s2, t2));
//                j++;
//            }
//            else if (t1 == t2)
//            {
//                if (s1 == s2)
//                {
//                    B.Add(new Booking(k1 + k2, s1, t1));
//                }
//                else if (s1 < s2)
//                {
//                    B.Add(new Booking(k1, s1, s2));
//                    B.Add(new Booking(k1 + k2, s2, t1));
//                }
//                else
//                {
//                    B.Add(new Booking(k2, s2, s1));
//                    B.Add(new Booking(k1 + k2, s1, t1));
//                }
//                j++;
//                i++;
//            }
//            else if (t1 < t2)
//            {
//                if (s1 == s2)
//                {
//                    B.Add(new Booking(k1 + k2, s2, t1));
//                }
//                else if (s1 < s2)
//                {
//                    B.Add(new Booking(k1, s1, s2));
//                    B.Add(new Booking(k1 + k2, s2, t1));
//                }
//                else
//                {
//                    B.Add(new Booking(k2, s2, s1));
//                    B.Add(new Booking(k1 + k2, s1, t1));
//                }
//                B2[j].S = t1;
//                i++;
//            }
//            else
//            {
//                if (s1 == s2)
//                {
//                    B.Add(new Booking(k1 + k2, s2, t2));
//                }
//                else if (s1 < s2)
//                {
//                    B.Add(new Booking(k1, s1, s2));
//                    B.Add(new Booking(k1 + k2, s2, t2));
//                }
//                else
//                {
//                    B.Add(new Booking(k2, s2, s1));
//                    B.Add(new Booking(k1 + k2, s1, t2));
//                }
//                B1[i].S = t2;
//                j++;
//            }
//        }
//        if (i != B1.Count)
//        {
//            for (; i < B1.Count; i++)
//            {
//                B.Add(B1[i]);
//            }
//        }
//        else if (j != B2.Count)
//        {
//            for (; j < B2.Count; j++)
//            {
//                B.Add(B2[j]);
//            }
//        }
//        return B;
//    }

//    static List<Booking> SatisfyingBooking(List<Request> R)
//    {
//        if (R.Count == 1) return new List<Booking> { new Booking(1, R[0].S, R[0].T) };

//        var mid = R.Count / 2;
//        var B1 = SatisfyingBooking(R.Take(mid).ToList());
//        var B2 = SatisfyingBooking(R.Skip(mid).ToList());

//        return MergeBookings(B1, B2);
//    }


//static void Main(string[] args)
//{
//    string input = Console.ReadLine();
//    string[] items = input.Trim().Split(new string[] { "), (" }, StringSplitOptions.RemoveEmptyEntries);
//    List<Request> R = new List<Request>();

//    foreach (string item in items)
//    {
//            // 去掉括号并分割
//            string[] items2 = item.Replace("(", "").Replace(")", "").Split(new string[] { ", " }, StringSplitOptions.RemoveEmptyEntries);
//            R.Add(new Request(int.Parse(items2[0]), int.Parse(items2[1])));
//    }

//    var result = SatisfyingBooking(R);

//    // 输出结果
//    for (int i = 0; i < result.Count; i++)
//    {
//        Console.Write(result[i].ToString());
//        if (i < result.Count - 1)
//        {
//            Console.Write(", "); // 仅在不是最后一个元素时添加逗号
//        }
//    }
//}

//}



using System;

class Program
{

    static int[] CountAnagramSubstrings(string T, string[] S)
    {
        int k = S[0].Length;
        int n = S.Length;
        int[] result = new int[n];
        int[][] sCounts = new int[n][];
        for (int i = 0; i < n; i++)
        {
            sCounts[i] = new int[26];
            foreach (char c in S[i])
            {
                sCounts[i][c - 'a']++;
            }
        }

        // 使用滑动窗口遍历 T
        int[] windowCount = new int[26]; // 存储当前窗口的字符计数
        for (int i = 0; i < T.Length; i++)
        {
            // 增加当前字符到窗口
            windowCount[T[i] - 'a']++;

            // 一旦窗口大小超过 k，移除最左边的字符
            if (i >= k)
            {
                windowCount[T[i - k] - 'a']--;
            }

            // 如果窗口大小达到 k，检查与 S 的计数是否相等
            if (i >= k - 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (windowCount == sCounts[j]))
                    {
                        result[j]++;
                    }
                }
            }
        }

        return result;
    }

    static void Main(string[] args)
    {
        string T = Console.ReadLine();
        string[] S = Console.ReadLine().Split(",");
        int[] result = CountAnagramSubstrings(T, S);
        for (int i = 0; i < result.Length - 1; i++)
        {
            Console.Write($"{result[i]},");
        }
        Console.Write(result[result.Length - 1]);
    }
}

