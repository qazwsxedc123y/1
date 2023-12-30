#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//standard library  标准库  对应system
#include<windows.h>//程序需要的重要头文件
#include<math.h>
#include<time.h>
#include<assert.h>

int main()
{
    int a ;
    scanf("%d", &a);

}


// 递归打印 一个整数（倒序）

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



//同理写  自己制函数 strlen

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


//自己定义函数实现strcpy函数的作用

//满分代码

//char* strcpy_my(char* ar1,char* ar2)
//{
//    assert(ar1 != NULL);//断言
//    assert(ar2 != NULL);//断言
//    char* ret = ar1;
//    //将ar2指向的字符串拷贝到ar1中，包含\0
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


//9分

//void strcpy_my(char* ar1,const char* ar2)
//{
//    assert(ar1 != NULL);
//    assert(ar2 != NULL);
//    while (*ar1++ = *ar2++)
//    {
//        ;
//    }


//8分

//void strcpy_my(char* ar1, char* ar2)
//{
//    assert(ar1 != NULL);
//    assert(ar2 != NULL);
//    while (*ar1++ = *ar2++)
//    {
//        ;
//    }


    //7分

    //while (*ar1++ = *ar2++)  //\0的ascII值为0  为假
    //{
    //    ;
    //}

    //6分

    //while (*ar2 != '\0')
    //{
    //    *ar1 = *ar2;
    //    ar1++, ar2++;
    //}
    //*ar1 = *ar2;

    //5分

//    int i = 0;
//    int sz = (int)strlen(ar2);
////    printf("%d", sz);
//    for (i = 0; i < sz; i++)
//    {
//        *ar1 = *ar2;
//        ar1++, ar2++;
//    }
//    *ar1 = *ar2;
////    ar1[i] = ar2[i];错误

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

//strcpy 库函数的使用

//int main()
//{
//    char arr1[] = "###########";
//    char arr2[]= "bit?";
//    strcpy(arr1, arr2);
//    printf("%s\n", arr1);
//    return 0;
//}



//关于死循环的代码  栈区相关

//int main()// 死循环
////栈区的默认使用是从高到低，数组随着下角标的增加，地址由低到高变化，数组随着越界改变就有可能把i改变2019版
////2022版的是默认先存储在低地址处
////栈区没有严格意义上的高低而是先使用后出
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

//调试修改代码   设置  断点  与  条件断点

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

//堆栈调式窗口

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

//调试

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

//逆置函数

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



//计算n的k次方（递归）

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

//使用递归实现一个整数的各个位数相加

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

//使用递归打印一个整数的每一位

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


//打印乘法表（自定义几几乘法表）


//print(int n)
//{
//    int i = 0, j = 0;
//    for (i = 1; i <= n; i++)
//    {
//        for (j = 1; j <= i; j++)
//        {
//            printf("%d*%d=%-3d", i, j, i * j);//这里是左对齐   右对齐为%3d
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


//打印100-200之间所有的质数

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




// 利用指针打印数组的内容

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

// 交换俩个数  不允许出现第三个变量  1逻辑运算符

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

//  加减实现
//int main()
//{
//    int a = 0, b = 0;
//    scanf("%d%d", &a, &b);
//    a = a + b;
//    b = a - b;
//    a = a - b;
//    printf("%d %d", a, b);
//}


//分别打印一个数的二进制数的偶数位与奇数位

//void print(int m)
//{
//    int i = 0;
//    printf("奇数为：\n");
//    for (i=30;i>=0;i-=2)
//    {
//        printf("%d ", (m >> i) & 1);
//    }
//    printf("\n");
//    printf("偶数为：\n");
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


//  求两个整形中的二进制不同的个数

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



//方法三  最为精简  按位与的用法

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






//计算一个数的（补码）有几个1
//方法二
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



//计算一个数的（补码）有几个1
//方法一

//int f(unsigned int a)//把负数转化为无符号的数
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




//数组内容互换

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


//逆置

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

//冒泡排序

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



//爱心

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



//求矩阵和   作业

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


//九九乘法表
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{                                   //%-2d(左对齐)
//			printf("%d*%d=%-2d ",i,j, i * j);//%2d表示打印的值为二位数，如果不是二位用空格补齐(右对齐)
//		}
//		printf("\n");
//	}
//	return 0;
//}



//关机程序
//int main()
//{
//    char arr[20];
//    system("shutdown -s -t 60");
//    again:
//        printf("你的电脑将在60s后关机，输入“我是猪”，则取消关机\n");
//        scanf("%s", arr);
//        if (strcmp(arr, "我是猪") == 0)
//        {
//            system("shutdown -a");
//        }
//        else
//        {
//            goto again;
//        }
//    return 0;
//}


//找出单身狗  2.0高级版（异或的使用）  异或满足交换律
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
//    printf("单身狗:%d", ret);
//    return 0;
//}




//找出单身狗  1.0简单版
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
//            printf("单身狗:%d", arr[i]);
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


//数组的特例知识点

//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int sz = 0;
//    printf("%p\n", arr);//数组名是首个元素
//    printf("%p\n", & arr[0]);
//    printf("%d", *arr);//数组名是首个元素
//    sz = sizeof(arr) / sizeof(arr[0]);//sizeof(数组名)这里的数组表示整个数组，不是首个元素地址
//    printf("%p\n", &arr);//&数组名   数组名表示整个数组
//    printf("%p\n", &arr+1);//&数组名   数组名表示整个数组   但&arr+1表示整个数组后面的第一个地址
//    return 0;
//}


//双层循环的举例

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



//冒泡排序

//int bubble_sort(int arr[], int sz)//数组本身就是地址，所以int arr【】就是传址调用
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




//二维数组

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



