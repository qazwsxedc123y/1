using System;
using System.Collections.Generic;

public class Topping : IComparable<Topping>  // 撒料类
{
    public int x;       // x 坐标
    public int y;       // y 坐标
    public int t;       // 美味值

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
    public int key;     // 键 
    public int val;     // 值

    public Item(int k, int v)
    {
        key = k;
        val = v;
    }
}

public class AvlNode
{
    public Item item;       // 数据项
    public AvlNode left;    // 左孩子
    public AvlNode right;   // 右孩子
    public AvlNode parent;  // 父节点

    public int sum;
    public int maxPrefix;
    public int maxPrefixKey;

    public AvlNode(Item x)           // Avl树节点 构造函数
    {
        item = x;
        UpdateSubtreeProperty();    // 更新(初始化)当前节点的“子树属性”
    }

    public void UpdateSubtreeProperty()
    {
        UpdateHeight();             // 更新子树属性1 —— 高度
        UpdateMaxPrefix();          // 更新子树属性2、3、4 —— sum、maxPrefix、maxPrefixKey
    }

    public int height;              // 子树属性——高度

    static int GetHeight(AvlNode A)  // 若节点为null，则规定其“高度”为 -1
    {
        return A != null ? A.height : -1;
    }

    public void UpdateHeight()      // 子树属性1——高度 的更新，时间复杂度 O(1)
    {
        int l_height = GetHeight(left);
        int r_height = GetHeight(right);
        height = l_height > r_height ? l_height + 1 : r_height + 1;
    }

    public void UpdateMaxPrefix()
    {
        sum = item.val + (left?.sum ?? 0) + (right?.sum ?? 0);

        int leftMaxPrefix = left?.maxPrefix ?? 0;
        int rightMaxPrefix = right?.maxPrefix ?? 0;
        maxPrefix = Math.Max(leftMaxPrefix, Math.Max(rightMaxPrefix, item.val + (left?.sum ?? 0)));

        if (maxPrefix == leftMaxPrefix)
            maxPrefixKey = left?.maxPrefixKey ?? item.key;
        else if (maxPrefix == rightMaxPrefix)
            maxPrefixKey = right?.maxPrefixKey ?? item.key;
        else
            maxPrefixKey = item.key;
    }

    public int Skew     // 倾斜度：右子树高度 - 左子树高度，时间复杂度 O(1)
    {
        get { return GetHeight(right) - GetHeight(left); }
    }

    public void RotateRight()   // 右旋操作，时间复杂度 O(1)
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
        D.UpdateSubtreeProperty();      // 更新 节点D 的子树属性
        B.UpdateSubtreeProperty();      // 更新 节点B 的子树属性
    }

    public void RotateLeft()    // 左旋操作，时间复杂度 O(1)
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
        B.UpdateSubtreeProperty();      // 更新 节点B 的子树属性
        D.UpdateSubtreeProperty();      // 更新 节点D 的子树属性
    }

    public void Rebalance()     // 局部重平衡操作，时间复杂度 O(1)
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

    public void Maintain()         // 增删节点后的维护操作：自下而上更新祖先节点的子树属性，顺便修复失衡状态。该函数为递归函数，总时间复杂度为 O(log n)
    {
        UpdateSubtreeProperty();    // 更新子树属性
        Rebalance();                // 修复失衡状态

        if (parent != null)
            parent.Maintain();      // 递归调用，最多 O(log n) 次
    }

    public AvlNode FindByKey(int k)   // 根据关键字 k 在当前子树中查找并返回对应节点，若不存在则返回 null，时间复杂度 O(log n)，注意此函数正确运行的前提是：是一棵二叉搜索树
    {
        if (k < item.key)
            return left != null ? left.FindByKey(k) : null;
        else if (k > item.key)
            return right != null ? right.FindByKey(k) : null;
        else
            return this;
    }

    public void InsertItem(Item x)   // 将数据项 x 封装成节点插入到正确位置，时间复杂度 O(log n)，注意此函数正确运行的前提是：是一棵二叉搜索树
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
    public AvlNode root;   // 根节点
    public int size;       // 节点数量
    public AvlTree()       // 构造函数
    {
        root = null;
        size = 0;
    }

    public int len() { return size; }  // 返回节点数量，时间复杂度 O(1)

    public Item Find(int k)  // 查找，时间复杂度 O(log n)
    {
        if (root != null)
        {
            var node = root.FindByKey(k);
            if (node != null) return node.item;
        }
        return null;
    }

    public void Insert(Item x)  // 插入，时间复杂度 O(log n)
    {
        if (root != null)
            root.InsertItem(x);
        else
            root = new AvlNode(x);
        size += 1;
    }

    public Item Delete(int k)  // 删除，时间复杂度 O(log n)
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

    // 更新的 max_prefix 方法：返回最大前缀和
    public int[] MaxPrefix()
    {
        return MaxPrefixHelper(root);
    }

    // 递归帮助函数，计算整棵树的最大前缀和
    private int[] MaxPrefixHelper(AvlNode node)
    {
        if (node == null)
        {
            return new int[] { 0, 0 };  // 返回默认值：前缀和为 0
        }

        int leftMaxPrefixKey = node.left?.maxPrefixKey ?? 0;
        int leftMaxPrefixValue = node.left?.maxPrefix ?? 0;

        int rightMaxPrefixKey = node.right?.maxPrefixKey ?? 0;
        int rightMaxPrefixValue = node.right?.maxPrefix ?? 0;

        // 返回最大前缀和及对应的 key
        if (node.maxPrefix >= leftMaxPrefixValue && node.maxPrefix >= rightMaxPrefixValue)
        {
            return new int[] { node.maxPrefixKey, node.maxPrefix };
        }
        else if (leftMaxPrefixValue >= rightMaxPrefixValue)
        {
            return new int[] { leftMaxPrefixKey, leftMaxPrefixValue };
        }
        else
        {
            return new int[] { rightMaxPrefixKey, rightMaxPrefixValue };
        }
    }
}

public static class Program
{
    public static int[] TastiestSlice(List<Topping> toppings)
    {
        // 1. 按照 x 坐标排序
        toppings.Sort();

        // 用于存储最优切片的美味值
        int maxTaste = int.MinValue;
        int bestX = 0, bestY = 0;

        // 2. 初始化 AVL 树
        var avlTree = new AvlTree();

        // 3. 遍历所有 topping，利用 AVL 树维护区间美味值
        for (int i = 0; i < toppings.Count; i++)
        {
            // 插入当前 topping 到 AVL 树
            avlTree.Insert(new Item(toppings[i].x, toppings[i].t));

            // 查询 AVL 树中的最大前缀和
            var maxPrefix = avlTree.MaxPrefix();
            int currentMaxPrefixKey = maxPrefix[0];  // 当前区间的最大前缀和对应的 x 坐标
            int currentMaxPrefixValue = maxPrefix[1]; // 当前区间的最大前缀和

            // 更新最优切片
            if (currentMaxPrefixValue > maxTaste)
            {
                maxTaste = currentMaxPrefixValue;
                bestX = currentMaxPrefixKey;
                bestY = toppings[i].y; // 以当前 topping 的 y 坐标为切片的结束坐标
            }
        }

        // 4. 返回最优切片的 x, y 和最大美味值
        return new int[] { bestX, bestY, maxTaste };
    }

    public static void Main(string[] args)
    {
        // 示例
        var toppings = new List<Topping>
        {
            new Topping(1, 2, 3),
            new Topping(2, 3, 4),
            new Topping(3, 4, 2),
        };

        var result = TastiestSlice(toppings);
        Console.WriteLine($"Best Slice: x = {result[0]}, y = {result[1]}, maxTaste = {result[2]}");
    }
}
