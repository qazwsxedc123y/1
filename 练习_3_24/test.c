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
//    }*pstPimData;//2�ֽ�
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
//    struct ListNode* sortedHead = head, * sortedTail = head;//β
//    head = head->next;
//    sortedTail->next = NULL;
//
//    while (head) {
//        struct ListNode* current = head;
//        // �ƶ�headָ�뵽��һ���ڵ�
//        head = head->next;
//
//        // ����ڵ㵽������
//        if (current->val <= sortedHead->val) {
//            // ���뵽ͷ��  ��ͷ
//            current->next = sortedHead;
//            sortedHead = current;
//        }
//        else {
//            // ���뵽�����򲿷ֻ�β��
//            struct ListNode* temp = sortedHead;
//            //���Ľڵ�ŵ�sorted����ȷλ��
//            while (temp != sortedTail && temp->next->val < current->val) {
//                temp = temp->next;
//            }
//            //����
//            current->next = temp->next;
//            temp->next = current;
//            if (temp == sortedTail) {
//                sortedTail = current; // ����ǲ��뵽β��������sortedTail
//            }
//        }
//    }
//    return sortedHead;
//}
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//    struct ListNode* sortedHead = head, * sortedTail = head;//β
//    head = head->next;
//    //���һ��
//    sortedTail->next = NULL;
//
//    while (head) {
//        struct ListNode* cur = head;
//        // �ƶ�headָ�뵽��һ���ڵ�
//        head = head->next;
//
//        //��sortedHead��ͷ��ֱ������
//        if (cur->val <= sortedHead->val)//ͷ�壬����ͷ
//        {
//            cur->next = sortedHead;
//            sortedHead = cur;
//        }
//        //sorthead��nextû��
//
//        //����ͷ��
//        //��ҩ�����Ƚ��ҵ���Ӧ��λ��
//        else
//        {
//            struct ListNode* tmp = sortedHead;
//            //�ҵ��˶�Ӧλ��
//            while ((tmp != sortedTail) && (tmp->next->val <= cur->val))
//            {
//                tmp = tmp->next;
//            }
//            cur->next = tmp->next;//�ȼ��� sortedTail->next=NULL;
//            tmp->next = cur;
//            //�������Ӧλ��Ϊβ�ڵ�
//            //����Tail
//            if (tmp == sortedTail)
//            {
//                sortedTail = cur;
//                //��ʱ��tmpΪ���һ������һ��  NULL
//            }
//        }
//    }
//    return sortedHead;
//}

 //else
 //{
 //    k = cur->val;
 //    //ptrΪcurǰһ��
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
 //        //���ptrǰһ��
 //        tmp = head;

 //        while (tmp->next != ptr)
 //        {
 //            tmp = tmp->next;
 //        }
 //        ptr = tmp;//--���

 //        ptr->next->val = k;
 //    }
 //    cur = cur->next;
 //       }

 
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head; // ��������Ϊ�ջ�ֻ��һ���ڵ�����
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
//        //ptrΪcurǰһ��
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
//                //���ptrǰһ��
//                tmp = dummy;
//                while (tmp->next != ptr)
//                {
//                    tmp = tmp->next;
//                }
//                ptr = tmp;//--���
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
//        //ptrΪcurǰһ��
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
//            //���ptrǰһ��
//            tmp = head;
//            if (ptr == head)//j=0
//            {
//                //����Ҫ����
//                ptr->val = k;
//            }
//            else
//            {
//                while (tmp->next != ptr)
//                {
//                    tmp = tmp->next;
//
//                }
//                ptr = tmp;//--���
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
//        //����
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
//    //ʣ�����������
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
//		//����׵���Ϣ
//		mine[i] = (char*)malloc(sizeof(char) * (col + 2));
//		//չʾ�����̣�������׵���Ϣ
//		show[i] = (char*)malloc(sizeof(char) * (col + 2));
//	}
//	Initboard(mine, '*');
//}

//int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    int i = 0;
//    int* arr1 = (int*)malloc(sizeof(int) * 5);
//    int count1 = 0;
//    while (k)//��kÿ��λ�浽arr1��
//    {
//        arr1[count1] = k % 10;
//        count1++;
//        k /= 10;
//    }
//    i = 0;
//    while (count1)//�ӵ���Ӧλ��
//    {
//        num[numSize - 1 - i] = num[numSize - 1 - i] + arr1[i];
//        i++;
//        count1--;
//    }
//    for (i = 0; i < numSize; i++)//��10��1  ��λ�Ȳ���
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
//    while (num[0] >= 10)//������λ
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
//	int* ps = (int*)malloc(sizeof(int) * 5);//���������СΪint�͵Ŀռ䣬����ָ��psָ��ÿռ�
//	if (ps == NULL)
//	{
//		perror("malloc fail");
//	}
//	int** pps = (int**)malloc(sizeof(int*) * 5);//���������СΪint*�͵Ŀռ䣬����ָ��ppsָ��ÿռ�
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
//	//�����ֽڴ�С
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



// ����������
//union Test {
//    int num;
//    char bytes;
//};
//
//// �жϵ�ǰ�������ֽ�˳����
//int check() 
//{
//    union Test test;
//    test.num = 1;
//    return test.bytes == 1;  // ���bytesΪ1����ΪС�ˣ�����Ϊ���
//}
//
//int main() {
//    if (check()) 
//    {
//        printf("��ǰ����ΪС��\n");
//    }
//    else 
//    {
//        printf("��ǰ����Ϊ���\n");
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
//	//���ϱ����Ķ��� 
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
////��ϰ2 
//struct S2
//{
//    char c1;
//    char c2;
//    int i;
//};
//printf("%d\n", sizeof(struct S2));
////��ϰ3 
//
//printf("%d\n", sizeof(struct S3));
////��ϰ4-�ṹ��Ƕ������ 

//printf("%d\n", sizeof(struct S4));

//void print(struct st ps)
//{
//    printf("%d %c", ps.a, ps.b);
//}
//int main()
//{
//    struct st s = { 10,'b' };//��ʼ��
//    print(s);
//    return 0;
//}