using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using static System.Net.Mime.MediaTypeNames;


class Program
{
    public class DoublyLinkedListNode
    {
        public int Item { get; set; }
        public DoublyLinkedListNode Prev { get; set; }
        public DoublyLinkedListNode Next { get; set; }
        public DoublyLinkedListNode(int x)
        {
            Item = x;
            Prev = null;
            Next = null;
        }
        public DoublyLinkedListNode LaterNode(int i)
        {
            if (i == 0) return this;
            if (Next == null) throw new InvalidOperationException();
            return Next.LaterNode(i - 1);
        }
    }
    public class DoublyLinkedListSeq
    {
        public DoublyLinkedListNode head;
        public DoublyLinkedListNode tail;
        public DoublyLinkedListSeq()
        {
            head = null;
            tail = null;
        }
        public override string ToString()
        {
            List<string> items = new List<string>();
            foreach (var item in this)
            {
                items.Add($"({item})");
            }
            return string.Join("-", items);
        }
        public void Build(IEnumerable<int> X)
        {
            foreach (var a in X)
            {
                InsertLast(a);
            }
        }
        public IEnumerator<int> GetEnumerator()
        {
            var node = head;
            while (node != null)
            {
                yield return node.Item;
                node = node.Next;
            }
        }
        public int GetAt(int i)
        {
            var node = head.LaterNode(i);
            return node.Item;
        }
        public void SetAt(int i, int x)
        {
            var node = head.LaterNode(i);
            node.Item = x;
        }
        public void InsertFirst(int x)
        {
            var node = new DoublyLinkedListNode(x);
            if (head == null)
            {
                head = node;
                tail = node;
            }
            else
            {
                node.Next = head;
                head.Prev = node;
                head = node;
            }
        }
        public void InsertLast(int x)
        {
            var node = new DoublyLinkedListNode(x);
            if (tail == null)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail.Next = node;
                node.Prev = tail;
                tail = node;
            }
        }
        public int DeleteFirst()
        {
            int item = head.Item;
            head = head.Next;
            if (head != null)
                head.Prev = null;
            else
                tail = null;
            return item;
        }
        public int DeleteLast()
        {
            int item = tail.Item;
            tail = tail.Prev;
            if (tail != null) tail.Next = null;
            else head = null;
            return item;
        }
        public DoublyLinkedListSeq Remove(DoublyLinkedListNode x1, DoublyLinkedListNode x2)
        {
            var result = new DoublyLinkedListSeq();
            var current = head;
            bool flag = false;
            while (current != null)
            {
                if (current.Item == x1.Item)
                    flag = true;
                var next = current.Next;
                var prev = current.Prev;
                if (flag)
                {
                    result.InsertLast(current.Item);
                    if (prev != null)
                    {
                        prev.Next = next;
                    }
                    if (next != null)
                    {
                        next.Prev = prev;
                    }

                }
                if (current.Item == x2.Item)
                    flag = false;
                current = next;
            }
            return result;
        }

        public void Splice(DoublyLinkedListNode x, DoublyLinkedListSeq L2)
        {
            if (x == null || L2.head == null) return;

            DoublyLinkedListSeq newList = new DoublyLinkedListSeq();
            DoublyLinkedListNode current = L2.head;

            while (current != null)
            {
                newList.InsertLast(current.Item);
                current = current.Next;
            }
            var xNext = x.Next;
            var xPrev = x;

            if (xNext != null)
            {
                xNext.Prev = newList.tail;
            }
            if (newList.tail != null)
            {
                newList.tail.Next = xNext;
            }

            if (xPrev != null)
            {
                xPrev.Next = newList.head;
                newList.head.Prev = xPrev;
            }
            else
            {
                head = newList.head;
            }

            tail = xNext == null ? newList.tail : tail;
            x.Next = newList.head;
            newList.head.Prev = x;
            L2.head = null;
            L2.tail = null;
        }
    }
    static void Main(string[] args)
    {
        string[] lines = new string[] { "InsertFirst 39", "InsertFirst 59", "InsertLast 59", "InsertFirst 52", "InsertFirst 21", "InsertLast 53", "InsertFirst 61", "InsertFirst 58",
                                        "InsertLast 49", "InsertLast 30", "InsertLast 19", "InsertFirst 25", "InsertFirst 59", "InsertLast 33", "InsertFirst 33", "InsertLast 42",
                                        "DeleteLast", "DeleteLast", "DeleteFirst", "DeleteLast", "DeleteFirst", "DeleteFirst", "DeleteLast", "DeleteLast",
                                        "Splice/Remove 2 4", "Splice/Remove 5 4", "Splice/Remove 6 4", "Splice/Remove 1 4", "Splice/Remove 6 4" };
        string[] outs = new string[] { "42", "33", "33", "19", "59", "25", "30", "49",
                                       "(58)-(61)-(0)-(1)-(2)-(3)-(21)-(0)-(1)-(2)-(3)-(0)-(1)-(2)-(0)-(0)-(1)-(2)-(3)-(1)-(2)-(3)-(3)-(52)-(59)-(39)-(59)-(53)" };
        int j = 0;
        var L = new DoublyLinkedListSeq();
        var n = lines.Length;
        for (int i = 0; i < n; i++)
        {
            string line = lines[i];
            string[] ops = line.Split(' ');
            if (ops[0] == "InsertLast")
            {
                int number = int.Parse(ops[1]);
                L.InsertLast(number);
            }
            if (ops[0] == "InsertFirst")
            {
                int number = int.Parse(ops[1]);
                L.InsertFirst(number);
            }
            if (ops[0] == "DeleteLast")
            {
                int number = L.DeleteLast();
                if (number.ToString() != outs[j++])
                    Console.WriteLine("DeleteLast 错误");
            }
            if (ops[0] == "DeleteFirst")
            {
                int number = L.DeleteFirst();
                if (number.ToString() != outs[j++])
                    Console.WriteLine("DeleteFirst 错误");
            }
            if (ops[0] == "Splice/Remove")
            {
                int number1 = int.Parse(ops[1]);
                int number2 = int.Parse(ops[2]);
                var L2 = new DoublyLinkedListSeq();
                int[] numbers = new int[number2];
                for (int k = 0; k < number2; k++)
                    numbers[k] = k;
                L2.Build(numbers);
                var x1 = L.head.LaterNode(number1);
                var x2 = x1.Next;
                L.Splice(x1, L2);
                for (int k = 0; k < number2; k++)
                {
                    L2 = L.Remove(x1.Next, x2.Prev);
                    x2 = x1.Next;
                    L.Splice(x1, L2);
                }
            }
        }
        //var L2 = new DoublyLinkedListSeq();
        //int[] numbers = new int[3];
        //for (int k = 0; k < 3; k++)
        //    numbers[k] = k;
        //L2.Build(numbers);
        //var x1 = L.head.LaterNode(2);
        //var x2 = x1.Next;
        //L.Splice(x1, L2);
        //L.Remove(x1, x2);

        if (L.ToString() != outs[j])
        {
            Console.WriteLine("Splice/Remove 错误");
            Console.WriteLine("期望的最终列表元素：" + outs[j]);
            Console.WriteLine("实际的最终链表元素：" + L.ToString());
        }
        else
        {
            Console.WriteLine("此测试用例通过");
        }
    }
}