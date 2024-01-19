#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000][1000];
    int count = 1;
    int i = 0, j = 0;
    int direction = 1; // 1表示向上走，-1表示向下走
    while (count <= n * n) {
        arr[i][j] = count++;

        if (direction == 1) {
            if (j == n - 1) {
                i++;
                direction = -1;
            }
            else if (i == 0) {
                j++;
                direction = -1;
            }
            else {
                i--;
                j++;
            }
        }
        else {
            if (i == n - 1) {
                j++;
                direction = 1;
            }
            else if (j == 0) {
                i++;
                direction = 1;
            }
            else {
                i++;
                j--;
            }
        }
    }

    // 输出蛇形矩阵
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//void Bubble_sort(int arr[], int size)
//{
//	int j, i, tem;
//	for (i = 0; i < size - 1; i++)//size-1是因为不用与自己比较，所以比的数就少一个
//	{
//		int count = 0;
//		for (j = 0; j < size - 1 - i; j++)	//size-1-i是因为每一趟就会少一个数比较
//		{
//			if (arr[j] > arr[j + 1])//这是升序排法，前一个数和后一个数比较，如果前数大则与后一个数换位置
//			{
//				tem = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tem;
//				count = 1;
//
//			}
//		}
//		if (count == 0)			//如果某一趟没有交换位置，则说明已经排好序，直接退出循环
//			break;
//	}
//
//}
//int main()
//{
//	int arr[10];
//	int i;
//
//	printf("请输入10个数\n");
//	for (i = 0; i < 10; i++)		//接收用户的数值
//	{
//		scanf("%d", &arr[i]);
//	}
//	printf("排序前的数组>");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	printf("\n排序后的数组>");
//	Bubble_sort(arr, 10);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//int main() {
//    int a, b, i = 0, j = 0, n; // i表示行，j表示列
//    int count = 1;
//    scanf("%d", &n); // 大小
//    int arr[19][19];
//    a = 0;
//    b = n - 1;
//    while (count <= n * n) {
//        for (j = a; j <= b; j++) // 向右
//        {
//            arr[a][j] = count++;
//        }
//        for (i = a + 1; i <= b; i++) // 向下
//        {
//            arr[i][b] = count++;
//        }
//        for (j = b - 1; j >= a; j--) // 向左
//        {
//            arr[b][j] = count++;
//        }
//        for (i = b - 1; i >= a + 1; i--) // 向上
//        {
//            arr[i][a] = count++;
//        }
//        a++;
//        b--;
//    }
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) 
//            printf("%d ", arr[i][j]);
//        printf("\n");
//    }
//    return 0;
//}


//bc129

//int main() {
//    int a, b, i, j, arr[5][25];
//    scanf("%d%d", &a, &b);
//    for (i = 0; i < a; i++)
//    {
//        for (j = 0; j < b; j++)
//        {
//            scanf("%d", arr[i][j]);
//        }
//    }
//    scanf("%d%d", &a, &b);
//    printf("%d", arr[a - 1][b - 1]);
//    return 0;
//}

//bc125

//int main() {
//    int a, arr[100], b, i = 0, j = 0, arrr[100];
//    scanf("%d", &a);
//    for (i = 0; i < a; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    scanf("%d", &b);
//    for (i = 0; i < a; i++)
//    {
//        if (arr[i] != b)
//        {
//            arrr[j] = arr[i];
//            j++; 
//        }
//    }
//    for (i = 0; i < j; i++)
//    {
//        printf("%d ", arrr[i]);
//    }
//    return 0;
//}

//bc122

//void bu(int* p, int sz)
//{
//    int i = 0, j = 0;
//    int flag = 0;
//    for (j = 0; j < sz - 1; j++)//判断是否为升序
//    {
//        if (p[j] < p[j + 1])
//        {
//            flag = 1;
//        }
//        else
//        {
//            flag = 0;
//            break;
//        }
//    }
//    if (flag == 1)
//    {
//        goto again;
//    }
//    for (j = 0; j < sz - 1; j++)//降序
//    {
//        if (p[j] > p[j + 1])
//        {
//            flag = 2;
//        }
//        else
//        {
//            flag = 0;
//            break;
//        }
//    }
//    if (flag == 2)
//    {
//        goto again;
//    }
//    int fla = 1;
//    for (j = 0; j < sz - i - 1; j++)//是否为常数
//    {
//        if (p[j] < p[j + 1])
//        {
//            fla = 0;
//        }
//    }
//    if (fla == 1)
//    {
//        flag = 1;
//    }
//again:
//    if (flag == 1 || flag == 2) {
//        printf("sorted\n");
//    }
//    else {
//        printf("unsorted\n");
//    }
//}
//
//int main()
//{
//    int arr[100] = { 4,4,4,4 }, b = 4, i = 0;
//    scanf("%d", &b);
//    for (i = 0; i < b; i++) {
//        scanf("%d", &arr[i]);
//    }
//    bu(arr, b);
//    return 0;
//}

//bc121

//void bu(int* p, int sz)
//{
//    int i = 0, j = 0;
//    for (i = 0; i < sz - 1; i++)//趟数
//    {
//        int flag = 0;
//        for (j = 0; j < sz - i - 1; j++)//比较
//        {
//            if (p[j] > p[j + 1])
//            {
//                int tmp = p[j];
//                p[j] = p[j + 1];
//                p[j + 1] = tmp;
//                flag = 1;
//            }
//        }
//        if (flag == 0)
//            break;
//    }
//}
//int main() {
//    int arr[1000], b, c, i, j;
//    scanf("%d%d", &b, &c);
//    for (i = 0; i < b + c; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int sz = b + c;
//    bu(arr, sz);
//    for (i = 0; i < sz; i++)
//        printf("%d ", arr[i]);
//    return 0;
//}
//bc117

//void f(int* p)
//{
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", *(p - i));
//    }
//}
//int main() {
//    int arr[10], b, i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    f(&arr[9]);
//    return 0;
//}

//bc116

//int main() {
//    int a, b, i = 0, count = 0;
//    scanf("%d%d", &a, &b);
//    for (i = 1; i <= a; i++)
//    {
//        int j = i;
//        while (j)
//        {       
//            int tmp = j % 10;
//            if (tmp == b)
//                count++;
//            j /= 10;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//bc114

//int main() {
//    int h, i = 0, j = 0, n = 0;
//    scanf("%d", &h);
//    for (j = 1; j <= 3 * h; j++)//行数
//    {
//        if (j % 3 == 1)
//        {
//            for (i = j; i < 3 * h; i++)
//            {
//                printf(" ");
//            }
//            for (n = j; n > 0; n = n - 3)
//            {
//                printf("*     ");
//            }
//        }
//        else if (j % 3 == 2)
//        {
//            for (i = j; i < 3 * h; i++)
//            {
//                printf(" ");
//            }
//            for (n = j; n > 0; n = n - 3)
//            {
//                printf("* *   ");
//            }
//        }
//        else
//        {
//            for (i = j; i < 3 * h; i++)
//            {
//                printf(" ");
//            }
//            for (n = j; n > 0; n = n - 3)
//            {
//                printf("* * * ");
//            }
//        }
//        printf("\n");
//    }
//    for (i = 0; i < h; i++)
//    {
//        for (j = 0; j < 3 * h - 1; j++)
//            printf(" ");
//        printf("*\n");
//    }
//    return 0;
//}


//bc112

//int main() {
//    int a, i = 0, j = 0;
//    while (scanf("%d", &a) != EOF) {
//        for (i = 1; i < a; i++)//行数
//        {
//            printf("* ");
//            for (j = 2; j <= i; j++)
//            {
//                if (i == j)
//                    printf("* ");
//                else
//                    printf("  ");
//            }
//            printf("\n");
//        }
//        for (j = 0; j < a; j++)
//            printf("* ");
//    }
//    return 0;
//}

//bc97

//int main() {
//    int a, i, b=0,c;
//    scanf("%d", &a);
//    for (i = 1; i <= a; i++)
//    {
//        c = i;
//            int sz = 0;
//            while (c)
//            {
//                c /= 10;
//                sz++;
//            }
//            int n = 0, sum = 0;
//            c = i;
//            b = 0;
//            for (n = 0; n < sz; n++)
//            {
//                b += (int)pow(10, sz - n-1) * (c % 10);
//                c = c / 10;
//            }
//        if (b == i)
//            printf("%d\n", i);
//    }
//    return 0;
//}

//bc92

//int main() {
//    int a, b, c, i = 0;
//    for (i = 10000; i <= 99999; i++) {
//        int j = 0, sum = 0;
//        for (j = 1; j <= 4; j++) {
//            a = i / (int)pow(10, j);
//            c = i % (int)pow(10, j);
//            sum = sum + a * c;
//        }
//        if (sum == i)
//            printf("%d ", i);
//    }
//    return 0;
//}


//bc91

//int main() {
//    int a, b;
//    while (scanf("%d%d", &a, &b) != EOF)
//    {
//        int i = 0, count = 0;
//        int flag = 0;
//        for (i = a; i <= b; i++)
//        {
//            int tmp = i, sum = 0;
//            while (tmp)
//            {
//                int c = tmp % 10;
//                tmp = tmp / 10;
//                sum += pow(c, 3);
//            }
//
//            if (sum == i)
//            {
//                if (flag != 0)
//                    printf(" ");
//                printf("%d", i);
//                flag++;
//                count++;
//            }
//        }
//        if (count == 0)
//            printf("no");
//        printf("\n");
//    }
//    return 0;
//}

//bc90

//int ave(int* p)
//{
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i < 3; i++)
//    {
//        sum += p[i];
//    }
//    int ave = sum / 3;
//    return ave;
//}
//
//int main() {
//    int a, arr[3], i = 0, count = 0;
//    scanf("%d", &a);
//    for (i = 0; i < a; i++)
//    {
//        scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
//        int ret = ave(arr);
//        if (ret < 60)
//            count++;
//    }
//    printf("%d", count);
//    return 0;
//}

//bc73

//int main() {
//    double a, b, c;
//    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
//        double m = b * b - 4 * a * c;
//        if (a == 0)
//            printf("Not quadratic equation\n");
//        else {
//            double x1 = (-b - sqrt(m)) / (2 * a), x2 = (-b + sqrt(m)) / (2 * a);
//            if (x2 == -0)
//                x2 = 0;
//            if (m == 0) {
//                printf("x1=x2=%.2lf\n", x2);
//            }
//            else if (m > 0)
//                printf("x1=%.2lf;x2=%.2lf\n", x1, x2);
//            else {
//                double y1 = -b / (2 * a), y2 = sqrt(-m) / (2 * a);
//                if (a > 0) {
//                    printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n", y1, y2, y1, y2);
//                }
//                else {
//                    printf("x1=%.2lf%.2lfi;x2=%.2lf%.2lfi\n", y1, y2, y1, y2);
//                }
//            }
//        }
//    }
//    return 0;
//}


//bc71

//int main() {
//    int a, b, c;
//    while (scanf("%d%d%d", &a, &b, &c) != EOF)
//    {
//        if ((a + b > c) && (a + c > b) && (b + c > a))
//        {
//            if (a == b && a == c)
//                printf("Equilateral triangle!\n");
//            else if ((a ^ b ^ c) == a || (a ^ b ^ c) == b || (a ^ b ^ c) == c)
//                printf("Isosceles triangle!\n");
//            else
//                printf("Ordinary triangle!\n");
//        }
//        else {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}
//bc64

//int main() {
//    double a = 0, money = 0;
//    char ch;
//    scanf("%lf %c", &a, &ch);
//    if (a <= 1)
//        money = 20;
//    else {
//        a -= 1;
//        money = 20 + a * 1;
//        if (money - (int)money != 0)
//            money = (int)money + 1;
//    }
//    if (ch == 'y')
//        money += 5;
//    printf("%.0lf", money);
//    return 0;
//}
//bc45

//int main() {
//    int a, b=0;
//    scanf("%d", &a);
//    int i = 0;
//    int j = 0;
//    while (a)
//    {
//        if (a % 2 == 0)
//        {
//                b = pow(10, i) * 0+b;
//                i++;
//        }
//        else
//        {
//            b = pow(10, i) * 1 + b;
//            i++;
//        }
//        a = a / 10;
//    }
//    printf("%d", b);
//    return 0;
//}

//bc41

//int main() {
//    int a, b;
//    scanf("%d%d", &a, &b);
//    double v = 3.14 * a * pow(b, 2) / pow(10, 3);
//    int ret = 0;
//    if (10 / v == 0)
//    {
//        ret = (int)10 / v;
//        printf("%d", ret);
//    }
//    else
//    {
//        ret = (int)10 / v + 1;
//        printf("%d", ret);
//    }
//    return 0;
//}


//bc34

//int main()
//{
//    double a, b, c;
//    scanf("%lf%lf%lf", &a, &b, &c);
//    double n1= a + b + c;
//    double s = n1 / 2;
//    double n2 = sqrt(s * (s - a) * (s - b) * (s - c));;
//    printf("circumference = %.2lf area=%.2lf", n1, n2);
//    return 0;
//}


//bc33

//double max(double* p, int sz)
//{
//    double max = p[0];
//    for (int i = 1; i < sz; i++)
//    {
//        if (p[i] > max)
//            max = p[i];
//    }
//    return max;
//}
//double min(double* p, int sz)
//{
//    double min = p[0];
//    for (int i = 1; i < sz; i++)
//    {
//        if (p[i] < min)
//            min = p[i];
//    }
//    return min;
//}
//double ave(double* p, int sz)
//{
//    double sum = 0;
//    for (int i = 0; i < sz; i++)
//    {
//        sum += p[i];
//    }
//    return sum / sz;
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//
//    double arr[100];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%lf", &arr[i]);
//    }
//    double m1 = max(arr, n);
//    double m2 = min(arr, n);
//    double m3 = ave(arr, n);
//    printf("%.2lf,%.2lf,%.2lf", m1, m2, m3);
//    return 0;
//}
