#define  _CRT_SECURE_NO_WARNINGS
//
//#include <math.h>
//#include <stdio.h>
//int main()
//{  
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };  
//    
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}

//int main()
//{
//	int money = 20;
//	int total = 0;
//	int empty = 0;
//	int tmp = 0;
//	empty = money;//������
//	total += money;
//	while (empty >= 2)//���Խ��н���
//	{
//		tmp = empty / 2;//�����õ�tmpƿ
//		total += tmp;//����һ������  ���п�ƿ��
//		empty = empty - tmp * 2 + tmp;//����ʣ��Ŀ�ƿ
//	}
//	printf("%d", total);
//	return 0;
//}

//int main()
//{
//	int n = 7;
//	int i = 0;
//	//�ϰ벿��
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;//�ո� 6 5 4 3 2 1 0
//		for (j = n ; j > i+1; j--)
//		{
//			printf(" ");
//		}
//		//*�� 1 3 5 7 9 11 13   2*i+1
//		for (j = 0; j < i * 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//�°벿��  һ��6��
//	for (i = 1; i < n ; i++)//�ո� 1 2 3 4 5 6
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//*�� 11 9 7 5 3 1   -2*i+13
//		for (j = 1; j <= -2 * i + 13; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}



//#include <math.h>
//#include <stdio.h>
//int main() {
//    int n, num, sum, tmp;
//    sum = 0;
//    int i = 0;
//    for (i = 0; i <= 100000; i++)
//    {
//        num = i;
//        sum = 0;
//        int sz = i;
//        n = 0;
//        while (sz > 0)
//        {
//            sz /= 10;
//            n++;
//        }
//        while (num > 0)
//        {
//             tmp = num % 10;
//            sum += pow(tmp, n);
//            num /= 10;
//        }
//        if (sum == i)
//        {
//            printf("%d  ", i);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 99999; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//�ж�i�Ƿ�Ϊˮ�ɻ���
//		//1. ���ж����ֵ�λ��
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. ����ÿһλ�Ĵη���
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. �ж�
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0, n = 0, sum = 0, tmp = 0;
//	scanf("%d", &n);
//	sum = n;
//	for (i = 0; i < 5; i++)
//	{
//		tmp = tmp * 10 + n;
//		sum += tmp;
//	}
//	printf("%d", sum);
//	return 0;
//}
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	int sum = 0;
//	int tmp = 0;
//	scanf("%d%d", &a, &n);
//	for (i = 0; i < n; i++)
//	{
//		tmp = tmp * 10 + a;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//	return 0;
//}