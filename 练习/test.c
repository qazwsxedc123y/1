#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>






///**
// * Definition for singly-linked list.
// * struct ListNode {
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}



///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* cur = head, * tail = NULL, * p2 = NULL;
//    while (cur)
//    {
//        tail = cur;
//        cur = cur->next;
//        tail->next = p2;
//        p2 = tail;
//    }
//    return tail;
//}



///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* tail = head, * cur = NULL;
//    while (tail)
//    {
//        if (tail->val == val)
//        {
//            if (cur)
//            {
//                cur->next = tail->next;
//                free(tail);
//                //跌代
//                tail = cur->next;
//            }
//            else
//            {
//                tail = head->next;
//                free(head);
//                head = tail;
//
//            }
//        }
//        else
//        {
//            cur = tail;
//            tail = cur->next;
//        }
//    }
//    return head;
//}


///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* head = NULL, * tail = NULL;
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//            if (tail == NULL)
//            {
//                head = tail = list1;
//            }
//            else
//            {
//                tail->next = list1;
//                tail = tail->next;
//            }
//            list1 = list1->next;
//        }
//        else
//        {
//            if (tail == NULL)
//            {
//                head = tail = list2;
//            }
//            else
//            {
//                tail->next = list2;
//                tail = tail->next;
//            }
//            list2 = list2->next;
//        }
//    }
//    if (list1)//1结束
//    {
//        tail->next = list1;
//    }
//    else
//    {
//        tail->next = list2;
//    }
//    return head;
//}


///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* head = NULL, * tail = NULL;
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//    while (list1 && list2)
//    {
//        if (list1->val <= list2->val)
//        {
//            tail->next = list1;
//            tail = list1;
//
//            list1 = list1->next;
//        }
//        else
//        {
//            tail->next = list2;
//            tail = list2;
//
//            list2 = list2->next;
//        }
//    }
//    if (list1)//1结束
//    {
//        tail->next = list1;
//    }
//    else
//    {
//        tail->next = list2;
//    }
//    struct ListNode* del = head;
//    head = head->next;
//    free(del);
//    return head;
//}

//int main()
//{
//	char arr1[] = "this is an apple";
//	char arr2[] = "is";
//	char* ret = strstr(arr1, arr2);
//	printf("%s\n", ret);
//	printf("%s\n", arr1);
//	return 0;
//}


//typedef struct SLList
//{
//    int x;
//    int y;
//} SL;
//
//int main()
//{
//    SL s = { 10, 20 };
//    SL* p = &s;
//    p->x = s.x;
//    p->y = s.y;
//
//    SL* pr = p;
//    pr->x = 30; // 通过间接访问修改p指向的内容
//
//    printf("s.x: %d, s.y: %d\n", s.x, s.y);
//    return 0;
//}

//typedef struct SLList
//{
//	int x;
//	int y;
//}SL;
//int main()
//{
//	SL s = { 10,20 };
//	SL* p = &s;
//	p->x = s.x;
//	p->y = s.y;
//	SL* pr = &p;
//	pr->x = 30;
//	return 0;
//}

//char* my_strcat(char* strDestination, const char* strSource)
//{
//	char* ret = strDestination;
//	size_t sz = strlen(strDestination);
//	strDestination += sz;
//	while (*strSource != '\0')
//	{
//		*strDestination++ = *strSource++;
//	}
//	*strDestination = '\0';
//
//
//	return ret;
//}
//int main()
//{
//	char arr1[100] = "aaaaaaa";
//	char arr2[] = "bbbb";
//	my_strcat(arr1, arr2);
//	return 0;
//}


//char* my_strcpy(char* strDestination, const char* strSource)
//{
//	char* ret = strDestination;
//	while (*strSource != '\0')
//	{
//		*strDestination++ = *strSource++;
//	}
//	*strDestination = '\0';
//	return ret;
//}
//int main()
//{
//	char arr1[100] = "aaaaaaa";
//	char arr2[] = "bbbb";
//	my_strcpy(arr1, arr2);
//	return 0;
//}


//size_t my_strlen(const char* string)
//{
//	size_t count = 0;
//	while (*string++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	size_t ret=my_strlen(arr);
//	printf("my_strlen=%zd\n", ret);
//	printf("strlen=%zd", strlen(arr));
//	return 0;
//}

//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}


//int is_leap_year(year)
//{
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//        return 1;
//    else
//        return 0;
//}
//int main() {
//    int a, b;
//    while (scanf("%d%d", &a, &b) != EOF)
//    {
//        int ret = is_leap_year(a);
//        //是返回1 不是返回0
//        //1、3、5、7、8、10、12 每月31天，4、6、9、11为30天。
//        //2月正常为28天，如果为闰年，则多一天为29天。
//        switch (b)
//        {
//        case 1:
//        case 3:
//        case 5:
//        case 7:
//        case 8:
//        case 10:
//        case 12:
//            printf("31");
//            break;
//        case 4:
//        case 6:
//        case 9:
//        case 11:
//            printf("30");
//            break;
//        case 2:
//            printf("%d", 28 + ret);
//            break;
//        default:
//            break;
//        }
//    }
//    return 0;
//}

//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int flag = 0;
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//		{
//			return;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		if (arr[i] != arr[i + 1])
//		{
//			printf("%d ", arr[i]);
//		}
//		else
//			i++;
//	}
//	if (arr[sz - 2] != arr[sz - 1])
//		printf("%d ", arr[sz - 1]);
//	return 0;
//}