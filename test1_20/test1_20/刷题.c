#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


//int main() {
//    char ar1[100], ar2[20];
//    gets(ar1);
//    int i = 0, j = 0;
//    while (ar1[i])
//    {
//        if (ar1[i] == ' ')
//        {
//            if (ar1[i + 1] >= 97)
//            {
//                ar1[i + 1] = ar1[i + 1] - 32;
//            }
//            ar2[j] = ar1[i + 1];
//            j++; 
//        }
//        if (i == 0)
//        {
//            if (ar1[i] >= 97)
//            {
//                ar1[i] = ar1[i] - 32;
//            }
//            ar2[j] = ar1[i];
//            j++;
//        }
//        i++;
//    }
//    for (i = 0; i < j; i++)
//    {
//        printf("%c", ar2[i]);
//    }
//    return 0;
//}

//int main() {
//    int n, m;
//    scanf("%d%d", &n, &m);
//    char s[100];
//    gets(s);
//    while (m)
//    {
//        int i, r;
//        scanf("%d%d", &i, &r);
//        char ch1, ch2;
//        scanf("%c%c", &ch1, &ch2);
//        int j = 0;
//        for (j = i - 1; j < r; j++)
//        {
//            if (s[j] == ch1)
//                s[j] = ch2;
//        }
//        m--;
//    }
//    int j = 0;
//    for (j = 0; j < strlen(s); j++)
//    {
//        printf("%c", s[j]);
//    }
//    return 0;
//}


//int main() {
//    long long int a = 0;
//    scanf("%lld", &a);
//    int arr[10];
//    int i = 0;
//    int sz = 0;
//    while (a)
//    {
//        arr[i] = a % 1000;
//        i++;
//        a /= 1000;
//        sz++;
//    }
//    int flag = 0;
//    for (i = sz-1; i >=0; i--)
//    {
//        if (flag != 0)
//            printf(",");
//        printf("%03d", arr[i]);
//        flag++;
//    }
//    return 0;
//}


//int main()
//{
//	int a = 5;
//
//	printf("%d", a++);
//}



//int main() {
//    char word[20];
//    int i = 0, sz = 0;
//    gets(word);
//    while (word[i]) {
//        sz++;
//        i++;
//    }
//    int j = 0, sum = 0, maxn = 0, minn = 10;
//    for (i = 0; i < sz; i++)
//    {
//        sum = 0;
//        int j;
//        for (j = 0; j < sz; j++)
//        {
//            if (word[i] == word[j])
//            {
//                sum++;
//            }
//        }
//        if (maxn < sum)
//        {
//            maxn = sum;
//        }
//        if (minn > sum)
//        {
//            minn = sum;
//        }
//    }
//    int c = maxn - minn;
//    int fac = 0;
//    for (i = 2; i < c; i++) { //ÅÐ¶ÏÊÇ·ñÎªËØÊý
//        if (c % i == 0) {
//            fac = 1;
//            break;
//        }
//    }
//    if (fac == 0 && c != 0 && c != 1)
//        printf("Lucky Word\n%d", c);
//    else
//        printf("No Answer\n0");
//    return 0;
//}