#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//standard library  ��׼��  ��Ӧsystem
#include<windows.h>//������Ҫ����Ҫͷ�ļ�
#include<math.h>
#include<time.h>
#include<assert.h>

int main()
{
    int a ;
    scanf("%d", &a);

}


// �ݹ��ӡ һ������������

//void print(int n)
//{
//    if (n < 10)
//    {
//        printf("%d ", n);
//    }
//    else
//    {
//        printf("%d ", n % 10);
//        print(n / 10);       
//    }
//}
//
//int main()
//{
//    int uum = 12345;
//    print(uum);
//    return 0;
//}

//int main() {
//    unsigned long long int p;
//    double a, b, c;
//    scanf("%llu;%lf,%lf,%lf", &p, &a, &b, &c);
//    printf("The each subject score of No. %llu is %.2lf, %.2lf, %.2lf.", p, a, b, c);
//    return 0;
//}

//int main() {
//    long long p[200];
//    double a, b, c;
//    scanf("%s;%lf,%lf,%lf", p, &a, &b, &c);
//    printf("The each subject score of No. %s is %.2lf, %.2lf, %.2lf.", p, a, b, c);
//    return 0;
//}
//



//ͬ��д  �Լ��ƺ��� strlen

//int my_strlen(const char* str)
//{
//    int count = 0;
//    assert(*str != NULL);
//    while (*str != '\0')
//    {
//        count++;
//        str++;
//    }
//    return count;
//}
//int main()
//{
//    char arr[] = "abcd";
//    int len = my_strlen(arr);
//    printf("%d\n", len);
//    return 0;
//}


//�Լ����庯��ʵ��strcpy����������

//���ִ���

//char* strcpy_my(char* ar1,char* ar2)
//{
//    assert(ar1 != NULL);//����
//    assert(ar2 != NULL);//����
//    char* ret = ar1;
//    //��ar2ָ����ַ���������ar1�У�����\0
//    while(*ar1++ = *ar2++)
//    {
//        ;
//    }
//    return ret;
//}
//
//int main()
//{
//    char arr1[] = "###########";
//    char arr2[] = "bit?";
//    printf("%s\n", strcpy_my(arr1, arr2));
//    return 0;
//}


//9��

//void strcpy_my(char* ar1,const char* ar2)
//{
//    assert(ar1 != NULL);
//    assert(ar2 != NULL);
//    while (*ar1++ = *ar2++)
//    {
//        ;
//    }


//8��

//void strcpy_my(char* ar1, char* ar2)
//{
//    assert(ar1 != NULL);
//    assert(ar2 != NULL);
//    while (*ar1++ = *ar2++)
//    {
//        ;
//    }


    //7��

    //while (*ar1++ = *ar2++)  //\0��ascIIֵΪ0  Ϊ��
    //{
    //    ;
    //}

    //6��

    //while (*ar2 != '\0')
    //{
    //    *ar1 = *ar2;
    //    ar1++, ar2++;
    //}
    //*ar1 = *ar2;

    //5��

//    int i = 0;
//    int sz = (int)strlen(ar2);
////    printf("%d", sz);
//    for (i = 0; i < sz; i++)
//    {
//        *ar1 = *ar2;
//        ar1++, ar2++;
//    }
//    *ar1 = *ar2;
////    ar1[i] = ar2[i];����

//}
//int main()
//{
//    char arr1[] = "###########";
//    char arr2[] = "bit?";
////    int sz = sizeof(arr2) / sizeof(arr2[0]);
//    strcpy_my(arr1, arr2);
//    printf("%s\n", arr1);
//    return 0;
//}

//strcpy �⺯����ʹ��

//int main()
//{
//    char arr1[] = "###########";
//    char arr2[]= "bit?";
//    strcpy(arr1, arr2);
//    printf("%s\n", arr1);
//    return 0;
//}



//������ѭ���Ĵ���  ջ�����

//int main()// ��ѭ��
////ջ����Ĭ��ʹ���ǴӸߵ��ͣ����������½Ǳ�����ӣ���ַ�ɵ͵��߱仯����������Խ��ı���п��ܰ�i�ı�2019��
////2022�����Ĭ���ȴ洢�ڵ͵�ַ��
////ջ��û���ϸ������ϵĸߵͶ�����ʹ�ú��
//{
//
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//    int i = 0;
//    printf("%p\n", arr);
//    printf("%p\n", &i);
//    system("pause");
//    for (i = 0; i <= 15; i++)
//    {
//        printf("hehe\n");
//        arr[i] = 0;
//    }
//    return 0;
//}

//�����޸Ĵ���   ����  �ϵ�  ��  �����ϵ�

//int main()
//{
//    int i = 0; 
//    int sum = 0;
//    int n= 0;
//    int ret = 1;
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++)
//    {
//        int j = 0;
//        ret = 1;
//        {
//            for (j = 1; j <= i; j++)
//                ret *= j;
//        }
//    }
//    sum += ret;
//    printf("%d\n",sum); 
//    return 0;
//}

//��ջ��ʽ����

//void test2()
//{
//    printf("hehe\n");
//}
//void test1()
//{
//    test2();
//}
//void test()
//{
//    test1();
//}
//int main()
//{
//    test();
//    return 0;
//}

//����

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	{
//		int tmp = 0;
//		printf("%d\n", tmp);
//	}
//	for (i = 0; i < 12; i++)
//	{
//		printf("hehe\n");
//		arr[i] = 0;
//	}
//	
//	for (i = 0; i < 12; i++)
//	{
//		printf("%d\n",i);
//	}
//	return 0;
//}

//���ú���

//void revers(int arr[], int sz)
//{
//    int left = 0;
//    int right = sz - 1;
//    int tmp = 0;
//    while (left < right)
//    {
//        tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++, right--;
//    }
//}
//int main()
//{
//    int arr[50];
//    int i = 0;
//    do {
//        scanf("%d", &arr[i]);
//        i++;
//    } while (getchar() != '\n' && i < 50);
//    int sz = i;
//    revers(arr, sz);
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}



//����n��k�η����ݹ飩

//double pow(int n, int k)
//{
//    if (k < 0)
//        return (1.0 / pow(n, -k));
//    else if (k == 0)
//        return 1.0;
//    else
//    return pow( n, k - 1) * n;
//}
//
//int main()
//{
//    int n = 0, k = 0;
//    scanf("%d%d", &n, &k);
//    double ret=pow(n, k);
//    printf("%lf", ret);
//    return 0;
//}

//ʹ�õݹ�ʵ��һ�������ĸ���λ�����

//int test(int num)
//{
//    if (num > 9)
//    {
//        return test(num / 10) + (num % 10);
//    }
//    else
//        return num;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int ret=test(n);
//    printf("%d", ret);
//    return 0;
//}

//ʹ�õݹ��ӡһ��������ÿһλ

//void print(int n)
//{
//    if (n < 10)
//    {
//        printf("%d ", n);
//    }
//    else
//    {
//        print(n / 10);
//        printf("%d ", n % 10);
//    }
//}
//
//int main()
//{
//    int uum = 12345;
//    print(uum);
//    return 0;
//}


//��ӡ�˷����Զ��弸���˷���


//print(int n)
//{
//    int i = 0, j = 0;
//    for (i = 1; i <= n; i++)
//    {
//        for (j = 1; j <= i; j++)
//        {
//            printf("%d*%d=%-3d", i, j, i * j);//�����������   �Ҷ���Ϊ%3d
//        }
//        printf("\n");
//    }
//}

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    print(n);
//    return 0;
//}


//��ӡ100-200֮�����е�����

//void test()
//{
//    int i = 0;
//    int count = 0;
//    for (i = 101; i < 200; i += 2)
//    {
//        int j = 2;
//        for (j = 2; j < i - 1; j++)
//        {
//            if (i % j == 0)
//                break;
//        }
//        if (j == i - 1)
//        {
//            printf("%d ", i);
//            count++;
//        }
//    }
//    printf("\n%d", count);
//}

//int main()
//{
//    test();
//    return 0;
//}




// ����ָ���ӡ���������

//void s(int* p, int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(p + i));
//    }
//}
//
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    s(arr,sz);
//    return 0;
//}

// ����������  ��������ֵ���������  1�߼������

//int main()
//{
//    int a = 12;
//    int b = 50;
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
//    printf("%d %d", a, b);
//    return 0;
//}

//  �Ӽ�ʵ��
//int main()
//{
//    int a = 0, b = 0;
//    scanf("%d%d", &a, &b);
//    a = a + b;
//    b = a - b;
//    a = a - b;
//    printf("%d %d", a, b);
//}


//�ֱ��ӡһ�����Ķ���������ż��λ������λ

//void print(int m)
//{
//    int i = 0;
//    printf("����Ϊ��\n");
//    for (i=30;i>=0;i-=2)
//    {
//        printf("%d ", (m >> i) & 1);
//    }
//    printf("\n");
//    printf("ż��Ϊ��\n");
//    for (i = 31; i >= 1; i-=2)
//    {
//        printf("%d ", (m >> i) & 1);
//    }
//}
//
//int main()
//{
//    int m = 0;
//    scanf("%d", &m);
//    print(m);
//    return 0;
//}


//  �����������еĶ����Ʋ�ͬ�ĸ���

//int ff(int a, int b)
//{
//    int c = a ^ b;
//    int count = 0;
//    //int i = 0;
//    //for (i = 0; i < 32; i++)
//    //{
//    //    if (((c >> i) & 1) == 1)
//    //    {
//    //        count++;
//    //    }
//    //}
//
//
//    return f(c);
//    return count;
//    return count;
//}
//
//int main()
//{
//    int a, b;
//    scanf("%d%d", &a, &b);
//    int ret = ff(a, b);
//    printf("%d", ret);
//    return 0;
//}



//������  ��Ϊ����  ��λ����÷�

//int f(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        n = n & (n - 1);
//        count++;
//    }
//    return count;
//}

//int main()
//{
//    int a = 0;
//    scanf("%d", &a);
//    int ret = f(a);
//    printf("%d", ret);
//    return 0;
//}






//����һ�����ģ����룩�м���1
//������
//
//int f(int n)
//{
//	int i = 0;
//	int count = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if (((n >> i) & 1) == 1)
//            count++;
//    }
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = f(a);
//	printf("%d", ret);
//	return 0;
//}



//����һ�����ģ����룩�м���1
//����һ

//int f(unsigned int a)//�Ѹ���ת��Ϊ�޷��ŵ���
//{
//	int count = 0;
//	while (a)
//	{
//		if (a % 2 == 1)
//		{
//			count++;
//
//		}
//		a = a / 2;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = f(a);
//	printf("%d", ret);
//	//	system("pause");
//	return 0;
//}




//�������ݻ���

//int main()
//{
//    int arr1[] = { 1,3,5,7,9 };
//    int arr2[] = { 0,2,4,6,8 };
//    int tmp = 0;
//    int sz = sizeof(arr1) / sizeof(arr1[0]);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        tmp = arr1[i];
//        arr1[i] = arr2[i];
//        arr2[i] = tmp;
//    }
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr1[i]);
//        printf("%d ", arr2[i]);
//        printf("\n");
//    }
//            
//    return 0;
//}


//����

//void revers(int arr[], int sz)
//{
//    int left = 0;
//    int right = sz - 1;
//    int tmp = 0;
//    while (left <right)
//    {
//        tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++, right--;
//    }
//}
//
//void print(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main()
//{
//    int arr[] = { 10,9,8,7,6,5,4,3,2,1,0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    print(arr, sz);
//    revers(arr, sz);
//    print(arr, sz);
//    return 0;
//}

//ð������

//void bubble_sort(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0;
//        int flag = 1;
//        for (j = 0; j < sz - 1-i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//                flag = 0;
//            }
//        }
//        if (flag == 1)
//            break;
//    }
//}
//
//int main()
//{
//    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    bubble_sort(arr, sz);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}



//����

//int main() {
//    for (float y = 1.5f; y > -1.5f; y -= 0.1f) {
//        for (float x = -1.5f; x < 1.5f; x += 0.05f) {
//            float a = x * x + y * y - 1;
//            putchar(a * a * a - x * x * y * y * y < 0.0f ? '*' : ' ');
//        }
//        Sleep(100);
//        putchar('\n');
//    }
//    getchar();
//    return 0;
//}



//������   ��ҵ

//int main()
//{
//    int arr1[3][3];
//    int arr2[3][3];
//    int arr[3][3];
//    int i = 0, j = 0;
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 3; j++)
//        {
//            scanf("%d", &arr1[i][j]);
//        }
//    }
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 3; j++)
//        {
//            scanf("%d", &arr2[i][j]);
//        }
//    }
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 3; j++)
//        {
//            arr[i][j] = arr1[i][j] + arr2[i][j];
//            printf("    %2d", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}


//�žų˷���
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{                                   //%-2d(�����)
//			printf("%d*%d=%-2d ",i,j, i * j);//%2d��ʾ��ӡ��ֵΪ��λ����������Ƕ�λ�ÿո���(�Ҷ���)
//		}
//		printf("\n");
//	}
//	return 0;
//}



//�ػ�����
//int main()
//{
//    char arr[20];
//    system("shutdown -s -t 60");
//    again:
//        printf("��ĵ��Խ���60s��ػ������롰����������ȡ���ػ�\n");
//        scanf("%s", arr);
//        if (strcmp(arr, "������") == 0)
//        {
//            system("shutdown -a");
//        }
//        else
//        {
//            goto again;
//        }
//    return 0;
//}


//�ҳ�����  2.0�߼��棨����ʹ�ã�  ������㽻����
//int main()
//{
//    int arr[] = { 1,2,3,4,5,1,2,3,4 };
//    int i = 0;
//    int ret = 0;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    for (i = 0; i < sz; i++)
//    {
//        ret = ret ^ arr[i];
//    }
//    printf("����:%d", ret);
//    return 0;
//}




//�ҳ�����  1.0�򵥰�
//int main()
//{
//    int arr[] = {1,2,3,4,5,1,2,3,4};
//    int i = 0;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    for (i = 0; i < sz; i++)
//    {
//        int count = 0;
//        int j = 0;
//        for (j = 0; j < sz; j++)
//        {
//            if (arr[i] == arr[j])
//            {
//                count++;
//            }
//        }
//        if (count == 1)
//        {
//            printf("����:%d", arr[i]);
//            break;
//        }
//    }
//    return 0;
//}















//int main()
//{
//    int T = 0, i = 0;
//    scanf("%d", &T);
//    for (i = 0; i < T; i++)
//    {
//        char arri;
//    }
//    int n = 0;
//    for (i = 0; i < T; i++)
//    {
//        scanf("%d", &n);
//        char arr1[n][n] = 0;
//        int j = 0;
//        for (j = 0; j < n; j++)
//        {
//            for (j = 0; j < n; j++)
//            {
//                scanf("%d", arr1[i][j]);
//            }
//        }
//    }
//    return 0;
//}


//���������֪ʶ��

//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int sz = 0;
//    printf("%p\n", arr);//���������׸�Ԫ��
//    printf("%p\n", & arr[0]);
//    printf("%d", *arr);//���������׸�Ԫ��
//    sz = sizeof(arr) / sizeof(arr[0]);//sizeof(������)����������ʾ�������飬�����׸�Ԫ�ص�ַ
//    printf("%p\n", &arr);//&������   ��������ʾ��������
//    printf("%p\n", &arr+1);//&������   ��������ʾ��������   ��&arr+1��ʾ�����������ĵ�һ����ַ
//    return 0;
//}


//˫��ѭ���ľ���

//int main()
//{
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < 10; i++)
//    {
//        for (j = 0; j < 10; j++)
//        {
//            printf("b");
//            break;
//        }
//        printf("a");
//    }
//    return 0;
//}



//ð������

//int bubble_sort(int arr[], int sz)//���鱾����ǵ�ַ������int arr�������Ǵ�ַ����
//{
//    int i = 0;   
//    for (i = 0; i < sz - 1; i++)
//    {
//        int flag = 1;
//        int j = 0;
//        for (j = 0; j <sz-1-i ; j++)
//        {
//            if (arr[j] < arr[j + 1])
//            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//                flag = 0;
//            }
//        }
//        if (flag == 1)
//        {
//            break;
//        }
//    }
//}
//int main()
//{
//    int arr[] = { 0,1,2,3,4,7,8,5,6,10 };
//    int i = 0;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    bubble_sort(arr,sz);
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}




//��ά����

//int main()
//{ 
//    int a[][3] = { {1,4}, {3,2}, {4,5,6}, {0} }; 
//    printf("%d", a[2][1]);
    /*int i, arr[100];
    int n = 0;
    scanf("%d", &n);
    for (i = n - 1; i >= 0; i--)
    {
        scanf("%d", &arr[i]);
    }       
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }*/
 /*   return 0;
}*/




//int fun(int x, int y) {
//    static int m = 0, i = 2;
//    i = i + m + 1;
//    m = i + x + y;
//    return m;
//}
//
//int main(void) {
//    int j = 4, m = 1, k;
//    k = fun(j, m);
//    printf("%d, ", k);
//    k = fun(j, m);
//    printf("%d\n", k);
//    return 0;
//}



//int main()
//{
//    int N,arr[10], i, a1 = 0, a2 = 0, min, max,x=0;
//    scanf("%d", &N);
//    for (i = 0; i < N; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    min = arr[0];
//    for (i = 0; i < N; i++)
//    {
//        if (min > arr[i])
//        {
//            x = i;
//            min = arr[i];
//        }
//    }
//    a1 = arr[x];
//    arr[x] = arr[0];
//    arr[0] = a1;
//    i = 0;
//    max = arr[N-1];
//    for (i = 0; i < N; i++)
//    {
//        if (max < arr[i])
//        {
//            x = i;
//            max = arr[i];
//        }
//    }
//    a2 = arr[x];
//    arr[x] = arr[N-1];
//    arr[N-1] = a2;
//    i = 0;
//    for (i = 0; i < N; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//	return 0;
//}



