#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>


 
//double max(double* p, int sz)
//{
//    int i = 0;
//    double max = p[0];
//    for (i = 0; i < sz - 1; i++)
//    {
//        if (p[i] < p[i + 1])
//            max = p[i + 1];
//    }
//    return max;
//}
//double min(double* p, int sz)
//{
//    int i = 0;
//    double min;
//    for (i = 0; i < sz - 1; i++)
//    {
//        if (p[i] > p[i + 1])
//            min = p[i + 1];
//    }
//    return min;
//}
//double ave(double* p, int sz)
//{
//    int i = 0;
//    double sum = 0;
//    for (i = 0; i < sz; i++)
//    {
//        sum += p[i];
//    }
//    return sum / sz;
//}
//int main()
//{
//    int n = 0, i = 0;
//    double arr[100];
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%lf", &arr[i]);
//    }
//    double m1 = max(arr, sz);
//    double m2 = min(arr, sz);
//    double m3 = ave(arr, sz);
//    printf("%.2lf %.2lf %.2lf", m1, m2, m3);
//    return 0;
//}


//void swap(int* a, int* b)
//{
//    int temp;
//    temp = *a;
//    *a = *b;
//    *b = temp;
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int ary[100][100];
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d", &ary[i][j]);
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        swap(&ary[i][i], &ary[i][n - 1 - i]);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n - 1; j++)
//        {
//            printf("%d ", ary[i][j]);
//        }
//        printf("%d\n", ary[i][n - 1]);
//    }
//    return 0;
//}

//int main()
//{
//    int a = 0;
//    int arr[100][100];
//    scanf("%d", &a);
//    int i = 0, j = 0;
//    for (i = 0; i < a; i++)
//    {
//        for (j = 0; j < a; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }//1
//    int tmp = 0;
//    tmp = arr[0][a - 1];
//    arr[0][a - 1] = arr[0][0];
//    arr[0][0] = tmp;
//    //2
//    tmp = arr[a - 1][0];
//    arr[a - 1][0] = arr[a - 1][a - 1];
//    arr[a - 1][a - 1] = tmp;
//    for (i = 0; i < a; i++)
//    {
//        for (j = 0; j < a; j++)
//        {
//            printf("%d", arr[i][j]);
//            if (j != a - 1)
//                printf(" ");
//        }
//        if (i != a - 1)
//            printf("\n");
//    }
//    return 0;
//}
//int main()
//{
//	int m, n;
//	int arr[10][10];
//	scanf("%d%d", &m, &n);
//	int i = 0, j = 0;
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int k1 = 0, k2 = 0;//位置
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%4d", arr[i][j]);
//			if (arr[i][j] < arr[k1][k2])
//			{
//				k1 = i;
//				k2 = j;
//			}
//		}
//		printf("\n");
//	}
//	printf("min = a[%d][%d] = %d", k1, k2, arr[k1][k2]);
//}


//int rabbitPairs(int month)
//{
//    if (month <= 0)
//    {
//        return 0;
//    }
//    else if (month == 1 || month == 2)
//    {
//        return 1;
//    }
//    else
//    {
//        return rabbitPairs(month - 1) + rabbitPairs(month - 2);
//    }
//}
//
//int main()
//{
//    int inputMonth;
//    printf("请输入月数:");
//    scanf("%d", &inputMonth);
//    int result = rabbitPairs(inputMonth);
//    printf("num=%d", result);
//    return 0;
//}


//int akm(unsigned int m, unsigned int n)
//{
//    if (m == 0)
//    {
//        return n + 1;
//    }
//    else if (m > 0 && n == 0)
//    {
//        return akm(m - 1, 1);
//    }
//    else if (m > 0 && n > 0)
//    {
//        return akm(m - 1, akm(m, n - 1));
//    }
//}
//int main()
//{
//    unsigned int m = 0, n = 0;
//    scanf("%u%u", &m,& n);
//    int c = akm(m, n);
//    printf("%d", c);
//    return 0;
//}


//
//int isprime(int n)
//{
//	int i = 0;
//	for (i = 0; i < n / 2; i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return -1;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a = isprime(n);
//	printf("%d", a);
//	return 0;
//}



//int Gcd(int a, int b)
//{
//    if (a <= 0 || b <= 0)
//        return -1;
//    if (a > b)
//    {
//        return Gcd(a - b, b);
//    }
//    if (a < b)
//    {
//        return Gcd(b - a, a);
//    }
//    else
//        return a;
//}
//int main()
//{
//    int a, b, c;
//    scanf("%d %d", &a, &b);
//    c = Gcd(a, b);
//    if (c != -1)
//    {
//        printf("%d\n", c);
//    }
//    else
//    {
//        printf("Input number should be positive!\n");
//    }
//    return 0;
//}


//int Gcd(int a, int b)
//{
//    int c = a > b ? b : a;
//    while (c)
//    {
//        if (a % c == 0 && b % c == 0)
//        {
//            return c;
//        }
//        c--;
//    }
//}
//int main()
//{
//    int a, b, c;
//    scanf("%d %d", &a, &b);
//    c = Gcd(a, b);
//    if (c != -1)
//    {
//        printf("%d\n", c);
//    }
//    else
//    {
//        printf("Input number should be positive!\n");
//    }
//    return 0;
//}


//unsigned long  Fact(unsigned int  n)
//{
//    unsigned int  i;
//    unsigned long result = 1;
//    for (i = 2; i <= n; i++)
//        result *= i;
//    return result;
//}
//int main()
//{
//    unsigned int n = 0, i = 0;
//    scanf("%u", &n);
//    for (i = 1; i <= n; i++)
//    {
//        unsigned long ret = Fact(i);
//        printf("%u! = %u", i, ret);
//        if(i!=n)
//        printf("\n");
//    }
//    return 0;
//}

//int main() 
//{
//    int a = 0, b = 0; int i = 0;
//    while (scanf("%d %d", &a, &b) != EOF)
//    {
//        int j = 0;
//        for (j = a; j <= b; j++)
//        {
//            int m = 0;
//            for (m = 2; m <= j / 2; m++)
//            {
//                if (j % m == 0)
//                {
//                    break;
//                }
//            }
//            if (m == j / 2 + 1)
//            {
//                printf("%d ", j);
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}


//
//int main()
//{
//    int flag = 0;
//    int i, j, t, n;
//    int s[10];
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//        scanf("%d", &s[i]);
//    for (i = 0; i < n-1; i++)
//    {
//        for (j = 0; j < n -1- i; j++)
//        {
//            if (s[j] > s[j + 1])
//            {
//                t = s[j];
//                s[j] = s[j + 1];
//                s[j + 1] = t;
//            }
//        }
//        for (j = 0; j < n; j++)
//        {
//            if (flag != 0)
//            {
//                printf(" ");
//            }
//            printf("%d", s[j]);
//            flag++;
//        }
//        if (i != n)
//            printf("\n");
//        flag = 0;
//
//    }
//    return 0;
//}


//int main()// 死循环
////栈区的默认使用是从高到低，数组随着下角标的增加，地址由低到高变化，数组随着越界改变就有可能把i改变2019版
////2022版的是默认先存储在低地址处
////栈区没有严格意义上的高低而是先使用后出
//{
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int i = 0;
//	printf("%p\n", arr);
//	printf("%p\n", &i);
//	system("pause");
//	for (i = 0; i <= 15; i++)
//	{
//		printf("hehe\n");
//		arr[i] = 0;
//	}
//	return 0;
//}

//void move(int arr[], int sz)
//{
//	int right = sz - 1;
//	int left = 0;
//	while (right > left)
//	{
//		if (arr[right] % 2 != 0)
//		{
//			if (arr[left] % 2 == 0)
//			{
//				int tmp = arr[right];
//				arr[right] = arr[left];
//				arr[left] = tmp;
//				right--;
//			}
//			left++;
//		}
//		else
//		{
//			right--;
//		}
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//}





//void move(int arr[],int sz)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < sz - 1; i++)//趟数
//	{
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] % 2 == 0 && arr[j + 1] % 2 != 0)
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr,sz);
//	print(arr, sz);
//	return 0;
//}

//喝汽水问题

//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	total = money;
//	empty = money;
//	while (empty >= 2)
//	{//换汽水
//		total += empty / 2;
//		empty =empty%2+ empty / 2;
//	}
//	printf("%d", total);
//	return 0;
//}

//int fid(int n)
//{
//	if (n >= 2 && n % 2 == 0)
//	{
//		return n + fid(n / 2);
//	}
//	else if (n >= 2 && n % 2 == 1)
//		return n + fid(n / 2 + 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = fid(n);
//	printf("%d", sum);
//	return 0;
//}

//打印棱形
//
//int main()
//{
//	int len, i = 0;
//	scanf("%d", &len);//7
//	//上半部分
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		for (j = 0; j < len - 1-i; j++)
//			printf(" ");
//		for (j = 0; j < 2 * i + 1; j++)
//			printf("*");
//		printf("\n");	
//	}
//	//下半部分
//	for (i = 0; i < len - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < i + 1; j++)
//			printf(" ");
//		for (j = 0; j < 2*(len-2-i)+1; j++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}

//输出0-100000所有的水仙花数

//int f(int i)
//{
//	int count = 1;
//	while (i >9 )
//	{
//		count++;
//		i /= 10;
//	}
//	return count;
//}
//int Sum(int i, int n)
//{
//	int ret = 0;
//	while (i)
//	{
//		ret += (int)pow(i % 10, n);
//		i /= 10;
//	}
//	return ret;
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		
//		///算出位数
//		int n = f(i);
//		//计算每一位的n次方和
//		int sum = Sum(i, n);
//		//判断是否为水仙花数
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int f(int i)
//{
//	int s = 0;
//	if (i > 1)
//	{
//		return i * f(i - 1);
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int a = 0;
//	a = f(5);
//	printf("%d", a);
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	while (scanf("%d", &a)==1)
//	{
//		if (a >= 140)
//		printf("Genius");
//	}
//	return 0;
//}

//int main()
//{
//	char* s[] = { "work","at","aibb" };
//	char** p = s;
//	p++;
//	printf("%s\n", *p);
//	return;
//}


//素数

//int isPrime(int num) 
//{
//    if (num <= 1) 
//    {
//        return 0;
//    }
//    for (int i = 2; i <= num / 2; i++)
//    {
//        if (num % i == 0) 
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main() {
//    printf("1-100之间的所有素数:\n");
//    for (int i = 1; i <= 100; i++) {
//        if (isPrime(i)) {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}


//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* prt1 = (int*)(&a + 1);
//	int* prt2 = (int*)((int)a + 1);
//	printf("%x", prt1[1]);
//	return 0;
//}



//struct test
//{
//	int num;
//	char* pc;
//	short sd;
//	char cha[2];
//	short sb[4];
//}*p;//此结构体占20个字节
//int main()
//{
//	printf("%p\n", p + 0x1);//+20
//	printf("%p\n", (unsigned long)p+ 0x1);//+1
//	printf("%p\n", (unsigned long*)p + 0x1);//+4
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d %d", *(a + 1), *(ptr - 1));//2 5
//	return 0;
//}


//自己实现qsort库函数  重点难

//struct stu
//{
//	char name[10];
//	int age;
//};
//int cmp_struct_by_age(const void* e1, const void* e2)//利用年龄排序
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;//返回的是整形
//}
//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++, buf2++;
//	}
//}
//void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{//趟数
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{//每趟比较次数
//			//先比较  利用函数指针cmp
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//void test()
//{
//	struct stu arr[3] = { {"zhangsan",10},{"lisi",30},{"wangwu",20} };
////	float arr[9] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };
////	int arr[]={9,8,7,6,5,4,3,2,1,0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
////	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	//
//	//结构体
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_struct_by_age);
//	int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%f ", arr[i]);
//	//}
//	//
//	//结构体
//	for (i = 0; i < sz; i++)
//	{
//		printf("naem:%s,age:%d\n", arr[i].name, arr[i].age);
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}




//qsort的使用与练习  含有结构体的打印

//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;//返回的是整形
//}
//test1()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//}
//int cmp_float(const void* e1, const void* e2)
//{
//	return (int)(*(float*)e1 - *(float*)e1);
//}
//test2()
//{
//	float f[9] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0 };//0.0 不进行排序？
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", f[i]);
//	}
//	printf("\n");
//}
//struct stu
//{
//	char name[10];
//	int age;
//};
//int cmp_struct_by_age(const void* e1, const void* e2)//利用年龄排序
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//int cmp_struct_by_name(const void* e1, const void* e2)//利用姓名排序
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}//比较字符串的大小需要用到strcmp
//test3()
//{
//	struct stu s[3] = { {"zhangsan",10},{"lisi",30},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
////	qsort(s, sz, sizeof(s[0]), cmp_struct_by_age);
//	qsort(s, sz, sizeof(s[0]), cmp_struct_by_name);
//	int i = 0;
	//for (i = 0; i < sz; i++)
	//{
	//	printf("naem:%s,age:%d\n",s[i].name,s[i].age);
	//}
//}
//int main()
//{
////	test1();//test1 为排序一个整形数组
////	test2();//test2 为排序一个浮点型的数组
//	test3();//test3 为排序一个结构体的数组
//	//第一个为 需要比较内容的首地址，第二个参数为比较内容的大小
//	//第三个为每个元素的类型占几字节，四为一个比较的函数指针；
//
//	return 0;
//}

//回调函数

//void print(char*str)//print被称为 回调函数
//{
//	printf("hehe:%s", str);
//}
//void test(void(*p)(char*))
//{
//	printf("test\n");
//	p("bit");
//}
//int main()
//{
//	test(print);
//	return 0;
//}
//另起一个函数简便写法的switch

//使用函数指针数组实现   各种算法（switch版本）

//void menu()
//{
//	printf("***********************\n");
//	printf("** 1.add      2.sub **\n");
//	printf("** 3.mul      4.div **\n");
//	printf("**     0   exit     **\n");
//	printf("***********************\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int safe_div(int a, int b) 
//{
//	if (b != 0)
//	{
//		return a / b;
//	}
//	else
//	{
//		return 0; // 返回一个默认值，表示除数为0
//	}
//}
//void calc(int (*pf)(int, int))
//{
//	int x = 0, y = 0;
//	printf("请输入两个操作数:>");
//	scanf ("%d%d", &x, &y);	
//	printf("%d\n", pf(x, y));
//}
//int main()
//{
//	int input = 0;
//	do {
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//		{
//			calc(add);
//			break;
//		}
//		case 2:
//		{
//			calc(sub);
//			break;
//		}
//		case 3:
//		{
//			calc(mul);
//			break;
//		}
//		case 4:
//		{
//			calc(safe_div);
//			break;
//		}
//		default:
//		{
//			printf("输入错误\n");
//			break;
//		}
//		}
//	} while(input);
//	return 0;
//}


//使用函数指针数组实现   各种算法（条件语句版本）

//void menu()
//{
//	printf("***********************\n");
//	printf("** 1.add      2.sub **\n");
//	printf("** 3.mul      4.div **\n");
//	printf("**     0   exit     **\n");
//	printf("***********************\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int safe_div(int a, int b) 
//{
//	if (b != 0)
//	{
//		return a / b;
//	}
//	else
//	{
//		return 0; // 返回一个默认值，表示除数为0
//	}
//}
//int main()
//{
//	int input = 0;
//	int x = 0, y = 0;//这种情况下的数组指针函数  叫做  转移表
//	int (*parr[5])(int, int) = {0, add,sub,mul, safe_div };
//	do {
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数:>");
//			scanf ("%d%d", &x, &y);	
//			int ret = parr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//			break;
//		}
//		else
//		{
//			printf("输入错误\n");
//		}
//	} while(input);
//	return 0;
//}


//对于数组指针函数练习（对于strcpy）

//char* my_strcpy(char* p1,const  char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* ret = p1;
//	while (*p1++ = *p2++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "########";
//	char arr2[] = "asdfg";
//	char* (*pf)(char*, const char*) = my_strcpy;
//	char* (*pfArr[4])(char*, const char*) = {my_strcpy ,my_strcpy,my_strcpy ,my_strcpy};
//	printf("%s\n",pf(arr1, arr2));
//	return 0;
//}



//数组指针函数

//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//div_t safe_div(int x, int y)
//{
//	if (y == 0)
//	{
//		fprintf(stderr, "Error: division by zero\n");
//		exit(EXIT_FAILURE);
//	}
//	return div(x, y);
//}
//int main()
//{
//	int (*parr[4])(int, int) = { add,sub,mul,safe_div };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", parr[i](2, 3));
//	}
//	return 0;
//}


//typedef  函数指针

//int main()
//{
//
//	void(*signal(int, void(*)(int)))(int);
//	//typedef unsigned int uint;//把unsigned int 名改为 uint
//	typedef void (*paw)(int);//把void (*)(int) 改名为paw
//	//使用
//	paw signal(int, paw);
//	return 0;
//}

//二维数组的传参

//void test(int(*pa)[])
//{
//
//}
//int main()
//{
//	int arr[3][4] = { {1,2,3,4} ,{2,3,4,5} ,{3,4,5,6} };
//	test(arr);
//	return 0;
//}

//数组指针打印二维数组

//void print1(int arr[3][4], int x, int y)
//{
//	int i = 0, j = 0;
//	for (i = 0.; i < x; i ++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int (*pa)[4], int x, int y)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(pa + i) + j));
//		}
//		printf("\n");
//	}
//}
////int main()
//{
//	int arr[3][4] = { {1,2,3,4} ,{2,3,4,5} ,{3,4,5,6} };
////	print1(arr, 3, 4);
//	print2(arr, 3, 4);
//	return 0;
//}

//打印数组指针

//int main()
//{
//	int arr[3] = {1,2,3};
//	int(*pa)[] = &arr;
//	int i = 0,j=0;
//	for (i = 0; i < 3; i++)
//	{		
//			printf("%d ",*(*pa + i));
//	}
//	return 0;
//}

//指针数组的使用与打印

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,4,5 };
//	int arr3[] = { 1,2,3,4,5 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "abcdef";
//	if (p1 == p2)
//	{
//		printf("hehe");
//	}
//	else
//	{
//		printf("haha");
//	}

//	char a[] = "adcsds";
////	int b = 5;
//	char* pc = a;
////	int * pa = &b;
//	printf("%d\n", pc);
////	printf("%s\n", a);
////	printf("%d\n", pa);
//	return 0;
//}



//int main()
//{
//	int b = 9;// 1, 093, 664, 768
//	float* p = (float*)&b;
//	printf("%f\n", *p);
//	*p = 9.0;
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	double b = 1E10;1.0*10的十次方
//	printf("%lf", b);
//	return 0;
//}

//int main()
//{
//	char arr2[] = { 'a' , 'b' , 'c' , 'd' , 'e' , 'f' };
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%c", arr2[i]);
//	}
//	printf("\n%d", strlen(arr2));//33
//	
//	return 0;
// }


//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		system("pause");
//	}
//	return 0;
//}


//不同类型的数进行运算

//int main()
//{
//	int a = -20;
//	//10000000 00000000 00000000 00010100
//	//11111111 11111111 11111111 11101011
//	//11111111 11111111 11111111 11101100
//	unsigned int b = 10;
//	//00000000 00000000 00000000 00001010
////相加11111111 11111111 11111111 11110110  因为打印位%d是有符号的故需要转位有符号的源码
////    11111111 11111111 11111111 11110101
////    10000000 00000000 00000000 00001010  -10
//	printf("%d", a+b);
//	return 0;
//}
//自制函数写法
 
//实现计算为大端存内存还是小端（函数）

//int check(const int n)//返回1 小端  返回0 大端
//{
//3
	//return *(char*)&n;
//2
	/*char* p = (char*)&n;
	return *p;*/
//1
	//char* p = (char*)&n;
	//if (*p == 1)
	//	return 1;
	//else
	//	return 0;
//}
//int main()
//{
//	int ret = check(1);
//	if (ret == 1)
//	{
//		printf("小端");
//	}
//	else
//		printf("大端");
//	return 0;
//}

//实现计算为大端存内存还是小端（普通法）

//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//	{
//		printf("小端");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//牛客网的题（目前错误）

//int main()
//{
//	//long long p[200];
//	char p[200];
//	double a, b, c;
//	int i = 0;
//	gets(p);
//	scanf("%lf,%lf,%lf", &a, &b, &c);
//	printf("%s%.2lf%.2lf%.2lf", p, a, b, c);
//	return 0;
//}