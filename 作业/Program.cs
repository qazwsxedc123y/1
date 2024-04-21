using System;

namespace UniqueNumbersArray
{
    class Program
    {
        static void Main(string[] args)
        {
            const int ArraySize = 10;
            int[] numbers = new int[ArraySize];
            int uniqueCount = 0;

            Console.WriteLine("请输入10个整数（每个数在10~100之间，包括10和100）：");

            for (int i = 0; i < ArraySize; i++)
            {
                bool isValidInput = false;
                while (!isValidInput)
                {
                    if (int.TryParse(Console.ReadLine(), out int inputNumber))
                    {
                        if (inputNumber >= 10 && inputNumber <= 100)
                        {
                            bool isUnique = true;
                            for (int j = 0; j < uniqueCount; j++)
                            {
                                if (numbers[j] == inputNumber)
                                {
                                    isUnique = false;
                                    break;
                                }
                            }

                            if (isUnique)
                            {
                                numbers[uniqueCount] = inputNumber;
                                uniqueCount++;
                            }

                            isValidInput = true;
                        }
                        else
                        {
                            Console.WriteLine("输入有误，请重新输入！");
                        }
                    }
                    else
                    {
                        Console.WriteLine("输入有误，请重新输入！");
                    }
                }
            }

            Console.WriteLine("\n用户输入的不同的数值为：");
            for (int i = 0; i < uniqueCount; i++)
            {
                Console.Write($"{numbers[i],4}");
            }

            Console.WriteLine();
        }
    }
}