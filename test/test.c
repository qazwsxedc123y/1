//#define  _CRT_SECURE_NO_WARNINGS
//////#include<iostream>
//////#include<vector>
//////using namespace std;
//////class Solution {
//////public:
//////    int findComplement(int num) {
//////        vector<int> v;
//////        while (num)
//////        {
//////            if (num % 2 == 1)
//////            {
//////                v.push_back(1);
//////            }
//////            else
//////            {
//////                v.push_back(0);
//////            }
//////            num /= 2;
//////        }
//////        int ret = 0;
//////        for (int i = v.size() - 1; i >= 0; i--)
//////        {
//////            ret = ret * 2 + v[i];
//////        }
//////        return ret;
//////    }
//////};
//////int main()
//////{
//////    double s = 2.2;
//////    const int& t = s;
//////    double& r = s;
//////	return 0;
//////}
////
////
////
////
////
//////for (int i = 1; i <= a; i++)
//////{
//////    for (int j = 1; j <= b; j++)
//////    {
//////        int tmp = count_mine(arr, i, j);
//////        if (tmp == -1)
//////        {
//////            printf("*");
//////        }
//////        else {
//////            printf("%d", tmp);
//////        }
//////    }
//////    printf("\n");
//////}
////
////
////
//////#include <stdio.h>
//////#define ROW 1000
//////#define COL 1000
//////int count_mine(char arr[ROW][COL], int x, int y)
//////{
//////    if (arr[x][y] == '*')
//////    {
//////        return -1;
//////    }
//////    else
//////    {
//////        int count = 0;//计算(x, y)位置八个方向的*的个数
//////        if (arr[x - 1][y - 1] == '*')
//////        {
//////            count++;
//////        }
//////        if (arr[x - 1][y] == '*')
//////        {
//////            count++;
//////        }
//////        if (arr[x - 1][y + 1] == '*')
//////        {
//////            count++;
//////        }
//////        if (arr[x][y - 1] == '*')
//////        {
//////            count++;
//////        }
//////        if (arr[x][y + 1] == '*')
//////        {
//////            count++;
//////        }
//////        if (arr[x + 1][y - 1] == '*')
//////        {
//////            count++;
//////        }
//////        if (arr[x + 1][y] == '*')
//////        {
//////            count++;
//////        }
//////        if (arr[x + 1][y + 1] == '*')
//////        {
//////            count++;
//////        }
//////        return count;
//////    }
//////}
//////int main() {
//////    int a, b;
//////    scanf("%d%d", &a, &b);
//////    char arr[ROW][COL] = { '0' };
//////    getchar();//对应换行
//////    for (int i = 1; i <= a; i++)
//////    {
//////        for (int j = 1; j <= b; j++)
//////        {
//////            scanf("%c", &arr[i][j]);
//////        }
//////        getchar();//对应换行
//////    }
//////    for (int i = 1; i <= a; i++)
//////    {
//////        for (int j = 1; j <= b; j++)
//////        {
//////            printf("%c", arr[i][j]);
//////        }
//////        printf("\n");
//////    }
//////    return 0;
//////}
////
////
////#include <stdio.h>
////#include<math.h>
////int convertToBaseN(int num, int Base)
////{
////    if (num == 0) {
////        return 0;
////    }
////    int d = 0, i = 0, r;
////    while (num != 0)
////    {
////        r = num % 10;
////        num /= Base;
////        d += r * pow(10, i);
////        ++i;
////    }
////    return d;
////}
////
////int main()
////{
////    int ret=convertToBaseN(1220,2);
////    printf("%d", ret);
////    return 0;
////}
////
////#include <stdio.h>
////#include<stdlib.h>
///*int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
//    *returnSize = 0;
//    num[numSize - 1] += k;
//    int ans = 0;
//    for (int i = numSize - 1; i >= 0; i--)
//    {
//        int tmp = num[i]+ans;
//        num[i] = (num[i] + ans)%10;
//        ans = tmp / 10;
//    }
//    returnSize = numSize;
//    if (ans != 0)
//    {
//        int* tmp = (int*)realloc(num, sizeof(int) * (numSize + 1));
//        if (tmp != NULL)
//        {
//            num = tmp;
//        }
//        memmove(num + 1, num, sizeof(int) * numSize);
//        *returnSize = numSize + 1;
//        num[0] = ans;
//    }
//    return num;
//}
//int main()
//{
//    int *arr=(int*)malloc(sizeof(int) * 3);
//    arr[0] = 2;
//    arr[1] = 7;
//    arr[2] = 4;
//    addToArrayForm(arr, 3, 181, 0);
//    return 0;
//}*/