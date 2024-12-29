#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define MAXSIZE 100
using namespace std;

// 定义二叉树节点
typedef struct BiTNode {
    char data;                // 节点数据
    struct BiTNode* lchild;   // 左子节点
    struct BiTNode* rchild;   // 右子节点
} BiTNode, * BiTree;

// 先序建立二叉树
void CreateBiTree(BiTree& T, char S[], int& i) {
    if (S[i] == '0') { // 空节点
        T = nullptr;
        i++;
    }
    else {
        T = new BiTNode();
        T->data = S[i++];
        T->lchild = nullptr;
        T->rchild = nullptr;
        CreateBiTree(T->lchild, S, i); // 左子树
        CreateBiTree(T->rchild, S, i); // 右子树
    }
}

// 使用回溯法求最长路径
void LongestPath(BiTree T, BiTree l[], int& longest) {
    static BiTree path[MAXSIZE]; // 存储当前路径
    static int pathLen = 0;      // 当前路径长度

    if (!T) return; // 空节点，直接返回

    // 将当前节点加入路径
    path[pathLen++] = T;

    // 如果到达叶子节点，检查是否为最长路径
    if (!T->lchild && !T->rchild) {
        if (pathLen > longest) {
            longest = pathLen;
            for (int i = 0; i < pathLen; i++) {
                l[i] = path[i];
            }
        }
    }

    // 递归遍历左右子树
    LongestPath(T->lchild, l, longest);
    LongestPath(T->rchild, l, longest);

    // 回溯：移除当前节点
    pathLen--;
}

// 输出路径
void PrintPath(BiTree l[], int length) {
    if (length == 0) {
        cout << "No path found!" << endl;
        return;
    }
    for (int i = 0; i < length; i++) {
        if (l[i]) {
            cout << l[i]->data;
        }
    }
    cout << endl;
}
// 释放二叉树内存
void DeleteTree(BiTree& T) {
    if (!T) return;
    DeleteTree(T->lchild);
    DeleteTree(T->rchild);
    delete T;
}
int main() {
    char S[MAXSIZE]; // 存储先序遍历序列
    while (cin >> S) {
        if (S[0] == '0') break; // 遇到 '0' 结束输入

        BiTree T = nullptr;
        int i = 0;
        CreateBiTree(T, S, i); // 建立二叉树

        BiTree longestPath[MAXSIZE]; // 最长路径存储
        int longest = 0;             // 最长路径长度

        LongestPath(T, longestPath, longest);

        cout << longest << endl;
        PrintPath(longestPath, longest);

        DeleteTree(T); // 释放内存
    }

    return 0;
}