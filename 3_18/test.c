#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>


//int main()
//{
//    FILE* pFile;
//    pFile = fopen("unexist.ent", "r");
//    if (pFile == NULL)
//        perror("Error opening file unexist.ent");
//    return 0;
//}


//int main()
//{
//    char a = 'A';
//    a = tolower(a);
//    printf("%c", a);
//    return 0;
//}


//int main()
//{
//    char a = 'a';
//    a = a - 32;
//    printf("%c", a);
//    return 0;
//}
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    //拷贝节点挂在原节点后面，建立关系
//    while (cur)
//    {
//        struct Node* next = cur->next;
//        struct Node* newcode = (struct Node*)malloc(sizeof(struct Node));
//        cur->next = newcode;
//        newcode->next = next;
//        cur = next;
//    }
//    //拷贝节点random
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//        copy->val = cur->val;
//        cur = next;
//    }
//    //恢复链表
//    cur = head;
//    struct Node* copyHead = NULL;
//    struct Node* copyTail = NULL;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//        if (copyTail == NULL)
//        {
//            copyHead = copyTail = copy;
//        }
//        else
//        {
//            copyTail->next = copy;
//            copyTail = copyTail->next;
//        }
//        cur->next = next;
//        cur = next;
//
//    }
//    return copyHead;
//}

//void GetMemory(char** p)
//{
//    *p = (char*)malloc(100);
//}
//void Test(void)
//{
//    char* str = NULL;
//    GetMemory(&str);
//    strcpy(str, "hello world");
//    printf(str);
//}
//int main()
//{
//    Test();
//    return 0;
//}




//int main() {
//    int* ptr;
//
//    // 使用malloc分配4个int大小的空间
//    ptr = (int*)malloc(4 * sizeof(int));
//
//    if (ptr == NULL) {
//        printf("内存分配失败\n");
//        exit(1);
//    }
//
//    // 给分配的空间赋值
//    for (int i = 0; i < 4; i++) {
//        *ptr = i;
//        ptr++;
//    }
//
//    // 解引用指针并访问数据
//    for (int i = 0; i < 4; i++) {
//        printf("%d ", ptr[i]);
//    }
//
//    // 释放malloc分配的空间
//    free(ptr);
//
//    return 0;
//}




    //struct Node* copyRandomList(struct Node* head) {
    //    struct Node* cur = head;
    //    while (cur)
    //    {
    //        struct Node* next = cur->next;
    //        struct Node* newcode = (struct Node*)malloc(sizeof(struct Node));
    //    }
    //}