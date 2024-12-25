#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


// 先描述
class channel
{
private:
    channel(int cmdfd, int slaverid, const std::string& processname)
        :_cmdfd(cmdfd), _slaverid(slaverid), _processname(processname)
    {
    }
public:
    int _cmdfd;               // 发送任务的文件描述符
    pid_t _slaverid;          // 子进程的PID
    string _processname; // 子进程的名字 -- 方便我们打印日志
}; using System;
using System.Collections;
using System.Collections.Generic;

public class Topping : IComparable<Topping>   // 撒料类
{
    public int x;       // x 坐标
    public int y;       // y 坐标
    public int t;       // 美味值

    public Topping(int x, int y, int t)
    {
        this.x = x; this.y = y; this.t = t;
    }

    public int CompareTo(Topping other)
    {
        return x.CompareTo(other.x);
    }
}

public class Item
{
    public int key;     // 键 
    public int val;     // 值


    public Item(int k, int v)
    {
        key = k;
        val = v;
    }
}

public class AvlNode
{
    public Item item;       // 数据项
    public AvlNode left;    // 左孩子
    public AvlNode right;   // 右孩子
    public AvlNode parent;  // 父节点
    public int sum;
    public int maxPrefix;
    public int maxPrefixKey;

    public AvlNode(Item x)          // Avl树节点 构造函数
    {
        item = x;
        UpdateSubtreeProperty();    // 更新(初始化)当前节点的“子树属性”
    }

    public void UpdateSubtreeProperty()
    {
        UpdateHeight();             // 更新子树属性1 —— 高度
        UpdateMaxPrefix();          // 更新子树属性2、3、4 —— sum、maxPrefix、maxPrefixKey
    }

    public int height;              // 子树属性——高度

    static int GetHeight(AvlNode A) // 若节点为null，则规定其“高度”为 -1
    {
        return A != null ? A.height : -1;
    }

    public void UpdateHeight()      // 子树属性1——高度 的更新，时间复杂度 O(1)
    {
        int l_height = GetHeight(left);
        int r_height = GetHeight(right);
        height = l_height > r_height ? l_height + 1 : r_height + 1;
    }



    /* **************** 这里要补充代码！*********************** */
    /* ****************************************************** */
    // 需要补充三个子树属性：sum、maxPrefix、maxPrefixKey
    // 并实现它们的更新函数 UpdateMaxPrefix
    /* ****************************************************** */
    /* ****************************************************** */

    public void UpdateMaxPrefix()
    {
        sum = item.val;
        if (left != null) sum += left.sum;
        if (right != null) sum += right.sum;
        var cut_cur = left != null ? left.sum + item.val : item.val;
        var cut_cur_left = left != null ? left.maxPrefix : -99999999;
        var cut_cur_right = left != null ? left.sum + item.val + (right != null ? right.maxPrefix : -99999999) : item.val + (right != null ? right.maxPrefix : -99999999);
        if (cut_cur_right > cut_cur_left)
        {
            if (cut_cur_right > cut_cur)
            {
                maxPrefix = cut_cur_right;
                maxPrefixKey = right.maxPrefixKey;
            }
            else
            {
                maxPrefix = cut_cur;
                maxPrefixKey = item.key;
            }
        }
        else
        {
            if (cut_cur_right > cut_cur_left)
            {
                maxPrefix = cut_cur_right;
                maxPrefixKey = right.maxPrefixKey;
            }
            else
            {
                maxPrefix = cut_cur_left;
                maxPrefixKey = left.maxPrefixKey;
            }
        }
    }

    public AvlNode SubtreeFirst()   // 返回当前子树的首节点，时间复杂度 O(log n)
    {
        if (left != null) return left.SubtreeFirst();
        else return this;
    }

    public AvlNode SubtreeLast()    // 返回当前子树的末节点，时间复杂度 O(log n)
    {
        if (right != null) return right.SubtreeLast();
        else return this;
    }

    public AvlNode Successor()      // 返回当前节点的后继节点，时间复杂度 O(log n)
    {
        if (right != null)
            return right.SubtreeFirst();
        AvlNode A = this;
        while (A.parent != null && A == A.parent.right)
            A = A.parent;
        return A.parent;
    }

    public AvlNode Predecessor()    // 返回当前节点的前驱节点，时间复杂度 O(log n)
    {
        if (left != null)
            return left.SubtreeLast();
        AvlNode A = this;
        while (A.parent != null && A == A.parent.left)
            A = A.parent;
        return A.parent;
    }

    public void InsertBefore(AvlNode B)     // 插入节点 B，令其成为当前节点的前驱节点，时间复杂度 O(log n)
    {
        AvlNode A = this;
        if (left != null)
        {
            A = A.left.SubtreeLast();
            B.parent = A;
            A.right = B;
        }
        else
        {
            B.parent = A;
            A.left = B;
        }
        A.Maintain();
    }

    public void InsertAfter(AvlNode B)      // 插入节点 B，令其成为当前节点的后继节点，时间复杂度 O(log n)
    {
        AvlNode A = this;
        if (right != null)
        {
            A = A.right.SubtreeFirst();
            B.parent = A;
            A.left = B;
        }
        else
        {
            B.parent = A;
            A.right = B;
        }
        A.Maintain();
    }

    public AvlNode SubtreeDelete()          // 将当前节点的数据项转移到叶子，移除并返回该叶子，时间复杂度 O(log n)
    {
        AvlNode A = this;
        if (A.left != null || A.right != null)
        {
            AvlNode B;
            if (A.left != null) B = A.Predecessor();
            else B = A.Successor();
            var temp = A.item;
            A.item = B.item;
            B.item = temp;
            return B.SubtreeDelete();
        }
        if (A.parent != null)
        {
            if (A == A.parent.left) A.parent.left = null;
            else A.parent.right = null;
            A.parent.Maintain();
            A.parent = null;
        }
        return A;
    }

    public int Skew     // 倾斜度：右子树高度 - 左子树高度，时间复杂度 O(1)
    {
        get { return GetHeight(right) - GetHeight(left); }
    }

        /////////////////////////////////////////////////////////////////
        //             -                                 -             //
        //       _____<D>___                         ___<B>_____       //
        //    __<B>__     <E>                       <A>     __<D>__    //
        //   <A>   <C>    / \    RotateRight(<D>)   / \    <C>   <E>   //
        //   / \   / \   /___\         =>          /___\   / \   / \   //
        //  /___\ /___\                                   /___\ /___\  //
        //                                                             //
        /////////////////////////////////////////////////////////////////
        public void RotateRight()   // 右旋操作，时间复杂度 O(1)
    {
        var D = this;
        var B = D.left; var E = D.right;
        var A = B.left; var C = B.right;
        var temp = B; B = D; D = temp;
        var tempitem = B.item;
        B.item = D.item;
        D.item = tempitem;
        B.left = A; B.right = D;
        D.left = C; D.right = E;
        if (A != null) A.parent = B;
        if (E != null) E.parent = D;
        D.UpdateSubtreeProperty();      // 更新 节点D 的子树属性
        B.UpdateSubtreeProperty();      // 更新 节点B 的子树属性
    }

    /////////////////////////////////////////////////////////////////
    //             -                                 -             //
    //       _____<D>___                         ___<B>_____       //
    //    __<B>__     <E>                       <A>     __<D>__    //
    //   <A>   <C>    / \    RotateLeft(<B>)    / \    <C>   <E>   //
    //   / \   / \   /___\         <=          /___\   / \   / \   //
    //  /___\ /___\                                   /___\ /___\  //
    //                                                             //
    /////////////////////////////////////////////////////////////////
    public void RotateLeft()    // 左旋操作，时间复杂度 O(1)
    {
        var B = this;
        var A = B.left; var D = B.right;
        var C = D.left; var E = D.right;
        var temp = B; B = D; D = temp;
        var tempitem = B.item;
        B.item = D.item;
        D.item = tempitem;
        D.left = B; D.right = E;
        B.left = A; B.right = C;
        if (A != null) A.parent = B;
        if (E != null) E.parent = D;
        B.UpdateSubtreeProperty();      // 更新 节点B 的子树属性
        D.UpdateSubtreeProperty();      // 更新 节点D 的子树属性
    }

    public void Rebalance()     // 局部重平衡操作，时间复杂度 O(1)
    {
        if (Skew == 2)
        {
            if (right.Skew < 0)
                right.RotateRight();
            RotateLeft();
        }
        else if (Skew == -2)
        {
            if (left.Skew > 0)
                left.RotateLeft();
            RotateRight();
        }
    }

    public void Maintain()          // 增删节点后的维护操作：自下而上更新祖先节点的子树属性，顺便修复失衡状态。该函数为递归函数，总时间复杂度为 O(log n)
    {
        UpdateSubtreeProperty();    // 更新子树属性
        Rebalance();                // 修复失衡状态

        if (parent != null)
            parent.Maintain();      // 递归调用，最多 O(log n) 次
    }

    public AvlNode FindByKey(int k)   // 根据关键字 k 在当前子树中查找并返回对应节点，若不存在则返回 null，时间复杂度 O(log n)，注意此函数正确运行的前提是：是一棵二叉搜索树
    {
        if (k < item.key)
            return left != null ? left.FindByKey(k) : null;
        else if (k > item.key)
            return right != null ? right.FindByKey(k) : null;
        else
            return this;
    }

    public void InsertItem(Item x)    // 将数据项 x 封装成节点插入到正确位置，时间复杂度 O(log n)，注意此函数正确运行的前提是：是一棵二叉搜索树
    {
        if (x.key < item.key)
        {
            if (left != null)
                left.InsertItem(x);
            else
                InsertBefore(new AvlNode(x));
        }
        else if (x.key > item.key)
        {
            if (right != null)
                right.InsertItem(x);
            else
                InsertAfter(new AvlNode(x));
        }
        else
        {
            item.val = x.val;
        }
    }
}

public class AvlTree
{
    public AvlNode root;    // 根节点
    public int size;        // 节点数量
    public AvlTree()        // 构造函数
    {
        root = null;
        size = 0;
    }

    public int len() { return size; }   // 返回节点数量，时间复杂度 O(1)

    public Item Find(int k)     // 查找，时间复杂度 O(log n)
    {
        if (root != null)
        {
            var node = root.FindByKey(k);
            if (node != null) return node.item;
        }
        return null;
    }

    public void Insert(Item x)  // 插入，时间复杂度 O(log n)
    {
        if (root != null)
            root.InsertItem(x);
        else
            root = new AvlNode(x);
        size += 1;
    }

    public Item Delete(int k)   // 删除，时间复杂度 O(log n)
    {
        if (root == null) return null;
        var node = root.FindByKey(k);
        if (node == null) return null;
        var ext = node.SubtreeDelete();
        if (ext.parent == null)
            root = null;
        size -= 1;
        return (Item)ext.item;
    }

    public int[] max_prefix()   // 获取最大前缀数据，时间复杂度 O(1)
    {
        int[] result = new int[2];
        result[0] = root.maxPrefixKey;
        result[1] = root.maxPrefix;
        return result;
    }
}
public class Program
{



    /* **************** 这里要补充代码！*********************** */
    /* ****************************************************** */
    // 需要实现最终函数 TastiestSlice(List<Topping> toppings)
    /* ****************************************************** */
    /* ****************************************************** */
    public static int[] TastiestSlice(List<Topping> toppings)
    {
        int[] ret = new int[3] { 0, 0, 0 };
        toppings.Sort();
        var T = new AvlTree();
        foreach(var t in toppings)
        {
            T.Insert(new Item(t.y, t.t));
            var yt = T.max_prefix();
            if (yt[1] > ret[2])
            {
                ret[0] = t.x;
                ret[1] = yt[0];
                ret[2] = yt[1];
            }
        }
        return ret;
    }


    public static void Main()
    {
        var line = Console.ReadLine();
        var strs = line.Substring(1, line.Length - 2).Split("), (");
        var toppings = new List<Topping>();
        for (int i = 0; i < strs.Length; i++)
        {
            string[] strs2 = strs[i].Split(", ");
            toppings.Add(new Topping(int.Parse(strs2[0]), int.Parse(strs2[1]), int.Parse(strs2[2])));
        }
        var result = TastiestSlice(toppings);
        Console.WriteLine(result[0].ToString() + ", " + result[1].ToString() + ", " + result[2].ToString());
    }
}

// 输入：const &
// 输出：*
// 输入输出：&

int main()
{
    // 先描述，在组织
    // 描述为创建管道
    // 利用fork 父进程为写端 子进程为读端
    // 建立通信匿名管道使用函数pipe
}


//int n, m;
//string s1, s2;

//int main()
//{
//    cin >> n >> m; // 读入字符串长度（未在代码中使用）
//    cin >> s1; // 原始字符串
//    cin >> s2; // 要插入的字符串
//
//    unordered_map<char, int> hash;
//    for (auto x : s2)
//    {
//        hash[x]++; // 统计每个字符的出现次数
//    }
//
//    // 将字符插入到字符串 s1 中
//    for (auto [ch, num] : hash)
//    {
//        bool inserted = false; // 标记是否成功插入
//        for (int i = 0; i < s1.size(); ++i)
//        {
//            if (ch < s1[i])
//            {
//                s1.insert(i, num, ch); // 在合适位置插入 num 个字符 ch
//                inserted = true;
//                break; // 插入后跳出循环
//            }
//        }
//        if (!inserted)
//        {
//            // 如果没有合适位置，直接追加到末尾
//            s1.append(num, ch);
//        }
//    }
//
//    cout << s1; // 输出最终字符串
//    return 0;
//}



//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//const int N = 100001;
//int n, ans = N;
//int arr[N], fid[N];
//void Create(int n)
//{
//    fid[0] = 1;
//    fid[1] = 1;
//    for (int i = 2; i < n; i++) fid[i] = fid[i - 1] + fid[i - 2];
//}
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> arr[i];
//    Create(n);
//    for (int i = 1; i < 1e6; i++)
//    {
//        int count = 0;
//        for (int j = 0; j < min(n, 30); j++)count += (arr[j] != i * fid[j]);
//        ans = min(count, ans);
//    }
//    cout << ans + max(0, n - 30);
//    return 0;
//}