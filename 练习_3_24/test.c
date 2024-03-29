#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include <stdlib.h> 
#include<errno.h>
#include<assert.h>

int main()
{
	printf("%d ", -1 / 2);
	return 0;
}
//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;//2字节
//    printf("%d\n", sizeof(*pstPimData));
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    return 0;
//}
//struct ListNode 
//{
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//    struct ListNode* sortedHead = head, * sortedTail = head;//尾
//    head = head->next;
//    sortedTail->next = NULL;
//
//    while (head) {
//        struct ListNode* current = head;
//        // 移动head指针到下一个节点
//        head = head->next;
//
//        // 插入节点到新链表
//        if (current->val <= sortedHead->val) {
//            // 插入到头部  换头
//            current->next = sortedHead;
//            sortedHead = current;
//        }
//        else {
//            // 插入到已排序部分或尾部
//            struct ListNode* temp = sortedHead;
//            //将改节点放到sorted的正确位置
//            while (temp != sortedTail && temp->next->val < current->val) {
//                temp = temp->next;
//            }
//            //插入
//            current->next = temp->next;
//            temp->next = current;
//            if (temp == sortedTail) {
//                sortedTail = current; // 如果是插入到尾部，更新sortedTail
//            }
//        }
//    }
//    return sortedHead;
//}
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//    struct ListNode* sortedHead = head, * sortedTail = head;//尾
//    head = head->next;
//    //最后一个
//    sortedTail->next = NULL;
//
//    while (head) {
//        struct ListNode* cur = head;
//        // 移动head指针到下一个节点
//        head = head->next;
//
//        //给sortedHead换头，直到合适
//        if (cur->val <= sortedHead->val)//头插，更换头
//        {
//            cur->next = sortedHead;
//            sortedHead = cur;
//        }
//        //sorthead的next没改
//
//        //不是头查
//        //弹药挨个比较找到对应的位置
//        else
//        {
//            struct ListNode* tmp = sortedHead;
//            //找到了对应位置
//            while ((tmp != sortedTail) && (tmp->next->val <= cur->val))
//            {
//                tmp = tmp->next;
//            }
//            cur->next = tmp->next;//等价于 sortedTail->next=NULL;
//            tmp->next = cur;
//            //但如果对应位置为尾节点
//            //更新Tail
//            if (tmp == sortedTail)
//            {
//                sortedTail = cur;
//                //此时的tmp为最后一个的下一个  NULL
//            }
//        }
//    }
//    return sortedHead;
//}

 //else
 //{
 //    k = cur->val;
 //    //ptr为cur前一个
 //    cur_prev = head;
 //    while (cur_prev->next != cur)
 //    {
 //        cur_prev = cur_prev->next;
 //    }
 //    ptr = cur_prev;
 //    while ((k < ptr->val) && (ptr != head))
 //    {
 //        ptr->next->val = ptr->val;//arr[j+1] = arr[j];
 //        //j--
 //        //存放ptr前一个
 //        tmp = head;

 //        while (tmp->next != ptr)
 //        {
 //            tmp = tmp->next;
 //        }
 //        ptr = tmp;//--完成

 //        ptr->next->val = k;
 //    }
 //    cur = cur->next;
 //       }

 
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head; // 处理链表为空或只有一个节点的情况
//    }
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    dummy->next = head;
//    struct ListNode* cur = dummy->next->next, * ptr = head;
//    // struct ListNode* cur = head->next->next, * ptr = head->next;
//    struct ListNode* tmp = head;
//    struct ListNode* cur_prev = head;
//    int k = 0;
//
//    while (cur)
//    {
//        //ptr为cur前一个
//        k = cur->val;
//        cur_prev = head;
//        while (cur_prev->next != cur)
//        {
//            cur_prev = cur_prev->next;
//        }
//        ptr = cur_prev;
//        if (cur->val >= ptr->val)
//        {
//            ptr = ptr->next;
//            cur = cur->next;
//        }
//        else
//        {
//            while ((k < ptr->val) && (ptr != dummy))
//            {
//                ptr->next->val = ptr->val;//arr[j+1] = arr[j];
//                //j--
//                //存放ptr前一个
//                tmp = dummy;
//                while (tmp->next != ptr)
//                {
//                    tmp = tmp->next;
//                }
//                ptr = tmp;//--完成
//                ptr->next->val = k;
//            }
//            cur = cur->next;
//        }
//    }
//    free(dummy);
//    return head;
//}
//void print(struct ListNode* head)
//{
//    while (head)
//    {
//        printf("%d ", head->val);
//        head = head->next;
//    }
//    printf("\n");
//}
//int main()
//{
//    struct ListNode* SL;
//    struct ListNode* Phead= (struct ListNode*)malloc(sizeof(struct ListNode));
//    SL=(struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* head = Phead;
//
//    struct ListNode* newcode=(struct ListNode*)malloc(sizeof(struct ListNode));
//    newcode->val = 4;
//    Phead->next = newcode;
//    Phead = Phead->next;
//
//    newcode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newcode->val = 2;
//    Phead->next = newcode;
//    Phead = Phead->next;
//    newcode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newcode->val = 1;
//    Phead->next = newcode;
//    Phead = Phead->next;
//    newcode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newcode->val = 3;
//    Phead->next = newcode;
//    Phead = Phead->next;
//    newcode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newcode->val = 6;
//    Phead->next = newcode;
//    Phead = Phead->next;
//    newcode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newcode->val = 0;
//    Phead->next = newcode;
//    Phead = Phead->next;
//        [4, 2, 1, 3]
//    Phead->next = NULL;
//    struct ListNode* tmp = head;
//    head = head->next;
//    free(tmp);
//    print(head);
//    insertionSortList(head);
//    print(head);
//    return 0;
//}

//  void insertion_sort(int arr[], int len){
//         int i,j,key;
//         for (i=1;i<len;i++){
//                 key = arr[i];
//                 j=i-1;
//                 while((j>=0) && (arr[j]>key)) {
//                         arr[j+1] = arr[j];
//                         j--;
//                 }
//                 arr[j+1] = key;
//         }
// }

//struct ListNode* insertionSortList(struct ListNode* head) {
//    struct ListNode* cur = head->next, * ptr = head;
//    struct ListNode* tmp = head;
//    struct ListNode* cur_prev = head;
//    int k = 0;
//    while (cur)
//    {
//        k = cur->val;
//        //ptr为cur前一个
//        cur_prev = head;
//        while (cur_prev->next != cur)
//        {
//            cur_prev = cur_prev->next;
//        }
//        ptr = cur_prev;
//        while ((k < ptr->val) && ptr != head)
//        {
//            ptr->next->val = ptr->val;//arr[j+1] = arr[j];
//
//            //j--
//
//            //存放ptr前一个
//            tmp = head;
//            if (ptr == head)//j=0
//            {
//                //不需要减减
//                ptr->val = k;
//            }
//            else
//            {
//                while (tmp->next != ptr)
//                {
//                    tmp = tmp->next;
//
//                }
//                ptr = tmp;//--完成
//
//                ptr->next->val = k;
//            }
//
//        }
//        cur = cur->next;
//    }
//    return head;
//}


//void insertion_sort(int arr[], int len)
//{
//         int i,j,key;
//         for (i=1;i<len;i++){
//                 key = arr[i];
//                 j=i-1;
//                 while((j>=0) && (arr[j]>key)) {
//                         arr[j+1] = arr[j];
//                         j--;
//                 }
//                 arr[j+1] = key;
//         }
// }
//int main()
//{
//    int arr[] = { 4,2,1,3 };
//    insertion_sort(arr, 4);
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//struct ListNode* deleteDuplication(struct ListNode* pHead) {
//    struct ListNode* fast = pHead->next;
//    struct ListNode* slow = pHead;
//    struct ListNode* newtail = NULL;
//    struct ListNode* newhead = NULL;
//    struct ListNode* tmp = NULL;
//    struct ListNode* tmr = NULL;
//    if (pHead == NULL) return NULL;
//    if (pHead->next == NULL) return pHead;
//    while (fast)
//    {
//        if (fast->val != slow->val)
//        {
//            if (newhead == NULL)
//            {
//                newhead = newtail = slow;
//            }
//            else
//            {
//                newtail->next = slow;
//                newtail = newtail->next;
//            }
//        }
//        else
//        {
//            while ((fast != NULL) && fast->val == slow->val)
//            {
//                fast = fast->next;
//            }
//            if ((fast == NULL) && newhead == NULL)
//                return NULL;
//        }
//        //跌代
//        slow = fast;
//        if (slow != NULL)
//        {
//            fast = slow->next;
//        }
//    }
//    if (newhead == NULL)
//    {
//        newhead = newtail = slow;
//    }
//    //剩余两个不想的
//    if ((slow != NULL) && (slow->next) == NULL)
//    {
//        newtail->next = slow;
//        newtail = newtail->next;
//    }
//    newtail->next = NULL;
//    return newhead;
//}

//int main()
//{
//    int row = 30, col = 16;
//    char** mine = (char**)malloc(sizeof(char*) * (row + 2));
//    char** show = (char**)malloc(sizeof(char*) * (row + 2));
//    for (int i = 0; i < row + 2; i++)
//    {
//        mine[i] = (char*)malloc(sizeof(char) * (col + 2));
//        show[i] = (char*)malloc(sizeof(char) * (col + 2));
//    }
//    Initboard(mine, '*');
//    return 0;
//}
//int main()
//{
//	int row = 30, col = 16;
//	char** mine = (char**)malloc(sizeof(char*) * (row + 2));
//	char** show = (char**)malloc(sizeof(char*) * (row + 2));
//	int i = 0;
//	for (i = 0; i < col + 2; i++)
//	{
//		//存放雷的信息
//		mine[i] = (char*)malloc(sizeof(char) * (col + 2));
//		//展示的棋盘，存放排雷的信息
//		show[i] = (char*)malloc(sizeof(char) * (col + 2));
//	}
//	Initboard(mine, '*');
//}

//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    int i = 0;
//    int* arr1 = (int*)malloc(sizeof(int) * 5);
//    int count1 = 0;
//    while (k)//把k每个位存到arr1内
//    {
//        arr1[count1] = k % 10;
//        count1++;
//        k /= 10;
//    }
//    i = 0;
//    while (count1)//加到对应位置
//    {
//        num[numSize - 1 - i] = num[numSize - 1 - i] + arr1[i];
//        i++;
//        count1--;
//    }
//    for (i = 0; i < numSize; i++)//满10进1  首位先不管
//    {
//        if (i = numSize - 1)
//        {
//            break;
//        }
//        while (num[numSize - i - 1] >= 10)
//        {
//            num[numSize - i - 1] -= 10;
//            num[numSize - i - 2] += 1;
//        }
//    }
//    while (num[0] >= 10)//处理首位
//    {
//        int* tmp = realloc(num, sizeof(int) * (numSize + 1));
//        numSize += 1;
//        if (tmp != NULL)
//        {
//            num = tmp;
//        }
//        memmove(num, num + 1, sizeof(int) * numSize);
//        while (num[1] >= 10)
//        {
//            num[1] -= 10;
//            num[0] += 1;
//        }
//    }
//    *returnSize = numSize;
//    return num;
//}
//int main()
//{
//    int arr[] = { 1,2,0,0 };
//    int k = 34;
//    int size = 0;
//    addToArrayForm(arr, 4, k, &size);
//    return 0;
//}






//int main()
//{
//	int* ps = (int*)malloc(sizeof(int) * 5);//开辟五个大小为int型的空间，利用指针ps指向该空间
//	if (ps == NULL)
//	{
//		perror("malloc fail");
//	}
//	int** pps = (int**)malloc(sizeof(int*) * 5);//开辟五个大小为int*型的空间，利用指针pps指向该空间
//	if (pps == NULL)
//	{
//		perror("malloc fail");
//	}
//	int* psr = (int*)calloc( 5 , sizeof(int));
//	if (psr == NULL)
//	{
//		perror("malloc fail");
//	}
//	int** ppsr = (int**)calloc( 5 , sizeof(int*));
//	if (ppsr == NULL)
//	{
//		perror("malloc fail");
//	}
//	//调整字节大小
//	int* tmp= (int* ) realloc(ps, 40);
//	if (tmp == NULL)
//	{
//		perror("realloc fail");
//	}
//	free(ps);
//	free(pps);
//	free(psr);
//	free(ppsr);
//	return 0;
//}



// 定义联合体
//union Test {
//    int num;
//    char bytes;
//};
//
//// 判断当前机器的字节顺序函数
//int check() 
//{
//    union Test test;
//    test.num = 1;
//    return test.bytes == 1;  // 如果bytes为1，则为小端；否则为大端
//}
//
//int main() {
//    if (check()) 
//    {
//        printf("当前机器为小端\n");
//    }
//    else 
//    {
//        printf("当前机器为大端\n");
//    }
//    return 0;
//}


//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", a.k);
//    return 0;
//}

//union Un
//{
//	short s[7];
//	int n;
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}

//#define A 2
//#define B 3
//
//#define MAX_SIZE A+B
//
//struct _Record_Struct
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//
//struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);


//int main()
//{
//	char buffer[25] = { '7','5','a','b'};
//	int i = 0;
//	i = atoi(buffer);
//	printf("%d", i);
//	return 0;
//}
 

//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合变量的定义 
//	union Un un = { 0 };
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//	return 0;
//}
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un un = { 0 };
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.c));
//	printf("%p\n", &un);
//}
//enum Color
//{
//    GREEN = 1,
//    RED,
//    BLUE,
//    GREEN_RED = 10,
//    GREEN_BLUE,
//    sss,
//}c;
//int main()
//{
//    printf("%zd", sizeof(c));
//}


//struct S3
//{
//    double d;
//    char c;
//    int i;
//};
//struct S4
//{
//    char c1;
//    struct S3 s3;
//    double d;
//};
//int main()
//{
//    printf("%zd", sizeof(struct S4));
//    return 0;
//}
////练习2 
//struct S2
//{
//    char c1;
//    char c2;
//    int i;
//};
//printf("%d\n", sizeof(struct S2));
////练习3 
//
//printf("%d\n", sizeof(struct S3));
////练习4-结构体嵌套问题 

//printf("%d\n", sizeof(struct S4));

//void print(struct st ps)
//{
//    printf("%d %c", ps.a, ps.b);
//}
//int main()
//{
//    struct st s = { 10,'b' };//初始化
//    print(s);
//    return 0;
//}