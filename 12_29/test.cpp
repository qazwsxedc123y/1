#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define MAXSIZE 100
using namespace std;

// ����������ڵ�
typedef struct BiTNode {
    char data;                // �ڵ�����
    struct BiTNode* lchild;   // ���ӽڵ�
    struct BiTNode* rchild;   // ���ӽڵ�
} BiTNode, * BiTree;

// ������������
void CreateBiTree(BiTree& T, char S[], int& i) {
    if (S[i] == '0') { // �սڵ�
        T = nullptr;
        i++;
    }
    else {
        T = new BiTNode();
        T->data = S[i++];
        T->lchild = nullptr;
        T->rchild = nullptr;
        CreateBiTree(T->lchild, S, i); // ������
        CreateBiTree(T->rchild, S, i); // ������
    }
}

// ʹ�û��ݷ����·��
void LongestPath(BiTree T, BiTree l[], int& longest) {
    static BiTree path[MAXSIZE]; // �洢��ǰ·��
    static int pathLen = 0;      // ��ǰ·������

    if (!T) return; // �սڵ㣬ֱ�ӷ���

    // ����ǰ�ڵ����·��
    path[pathLen++] = T;

    // �������Ҷ�ӽڵ㣬����Ƿ�Ϊ�·��
    if (!T->lchild && !T->rchild) {
        if (pathLen > longest) {
            longest = pathLen;
            for (int i = 0; i < pathLen; i++) {
                l[i] = path[i];
            }
        }
    }

    // �ݹ������������
    LongestPath(T->lchild, l, longest);
    LongestPath(T->rchild, l, longest);

    // ���ݣ��Ƴ���ǰ�ڵ�
    pathLen--;
}

// ���·��
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
// �ͷŶ������ڴ�
void DeleteTree(BiTree& T) {
    if (!T) return;
    DeleteTree(T->lchild);
    DeleteTree(T->rchild);
    delete T;
}
int main() {
    char S[MAXSIZE]; // �洢�����������
    while (cin >> S) {
        if (S[0] == '0') break; // ���� '0' ��������

        BiTree T = nullptr;
        int i = 0;
        CreateBiTree(T, S, i); // ����������

        BiTree longestPath[MAXSIZE]; // �·���洢
        int longest = 0;             // �·������

        LongestPath(T, longestPath, longest);

        cout << longest << endl;
        PrintPath(longestPath, longest);

        DeleteTree(T); // �ͷ��ڴ�
    }

    return 0;
}