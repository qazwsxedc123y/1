#define  _CRT_SECURE_NO_WARNINGS


#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//int main()
//{
//    char board[3][3] = { 0 };
//    char flag = 0;
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            scanf(" %c", &board[i][j]);
//        }
//    }
//    //判断输赢
//    for (int i = 0; i < 3; i++)
//    {
//        //行
//        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != 'O')
//        {
//            flag = board[i][2];
//            break;
//        }
//        //列
//        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != 'O')
//        {
//            flag = board[2][i];
//            break;
//        }
//    }
//    //对角线
//    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != 'O')
//    {
//        flag = board[2][2];
//    }
//    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != 'O')
//    {
//        flag = board[2][0];
//    }
//
//    if ('K' == flag)
//    {
//        printf("KiKi wins!\n");
//    }
//    else if ('B' == flag)
//    {
//        printf("BoBo wins!\n");
//    }
//    else
//    {
//        printf("No winner!\n");
//    }
//
//    return 0;
//}

char who_win(char arr[3][3], int x, int y)
{
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != 'O')
        return arr[0][0];
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != 'O')
        return arr[0][2];
    int i = 0;
    for (i = 0; i < x; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != 'O')
        {
            return arr[i][0];
        }
    }
    for (i = 0; i < y; i++)
    {
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != 'O')
        {
            return arr[0][i];
        }
    }
    return 'O'; // No winner
}

int main() {
    int i, j;
    char arr[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }
    char ret = who_win(arr, 3, 3);
    if (ret == 'K')
        printf("k wins");
    else if (ret == 'B')
        printf("B wins");
    else
        printf("No winner");
    return 0;
}

//
//char who_win(char board[3][3], int row, int col)
//{
//    int i;
//
//    for (i = 0; i < row; i++)
//    {
//        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 'O')
//        {
//            return board[i][0];
//        }
//    }
//
//    for (i = 0; i < col; i++)
//    {
//        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 'O')
//        {
//            return board[0][i];
//        }
//    }
//
//    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 'O')
//    {
//        return board[1][1];
//    }
//
//    if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != 'O')
//    {
//        return board[1][1];
//    }
//
//    // If no winner, return a space character
//    return 'O';
//}
//
//int main() {
//    int i, j;
//    char arr[3][3];
//
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 3; j++)
//        {
//            scanf(" %c", &arr[i][j]);
//        }
//    }
//
//    char ret = who_win(arr, 3, 3);
//
//    if (ret == 'K')
//        printf("K wins");
//    else if (ret == 'B')
//        printf("B wins");
//    else if (ret == 'O')
//        printf("No winner");
//    else
//        printf("Invalid input");
//
//    return 0;
//}




//char who_win(char board[3][3], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 'O')
//		{
//			return board[i][0];
//		}
//
//	}
//	for (i = 0; i < col; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 'O')
//		{
//			return board[0][i];
//		}
//	}
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 'O')
//	{
//		return board[1][1];
//	}
//	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
//	{
//		return board[1][1];
//	}
//	//判断是否平局
//		return 'Q';
//}
//int main() {
//    int i=0, j=0;
//    char arr[3][3];
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            scanf(" %c", &arr[i][j]);
//        }
//    }
//    char ret=who_win(arr, 3, 3);
//    if (ret == 'k')
//        printf("k");
//    else if (ret == 'B')
//        printf("b");
//    return 0;
//}


//int main() {
//    int a, arr[30][30];
//    scanf("%d", &a);
//    int i = 0, j = 0;
//    for (i = 0; i < a; i++)
//    {
//        for (j = 0; j <= i; j++)
//        {
//            if (j == 0 || i == j)
//                arr[i][j] = 1;
//            else if (i > 1 && j > 0)
//                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//        }
//    }
//    for (i = 0; i < a; i++)
//    {
//        for (j = 0; j < a; j++)
//        {
//            if (i >= j)
//            {
//                printf("%5d", arr[i][j]);
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}

//int main() {
//    int n, m, i, j;
//    int arr[10][10];
//    scanf("%d%d", &n, &m);
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < m; j++) {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    int p = 0, i1;
//    scanf("%d", &p);
//    char ch;
//    int a, b;
//    for (i1 = 0; i1 < p; i1++) {
//        scanf(" %c%d%d", &ch, &a, &b); // 注意这里的空格
//        if (ch == 'r') {
//            for (j = 0; j < m; j++) {
//                int tmp = arr[a - 1][j];
//                arr[a - 1][j] = arr[b - 1][j];
//                arr[b - 1][j] = tmp;
//            }
//        }
//        else if (ch == 'c') {
//            for (i = 0; i < n; i++) {
//                int tmp = arr[i][a - 1];
//                arr[i][a - 1] = arr[i][b - 1];
//                arr[i][b - 1] = tmp;
//            }
//        }
//    }
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < m; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}


//int main() {
//    int n, m, i, j;
//    int arr[10][10];
//    scanf("%d%d", &n, &m);
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    int p = 0, i1;
//    scanf("%d", &p);
//    char ch;
//    int a, b;
//    for (i1 = 0; i1 < p; i1++)//交换次数
//    {
//        scanf("%c%d%d", &ch, &a, &b);//r为列  c为行
//        if (ch == 'r')//交换行
//        {
//             for (j = 0; j < m; j++)
//            {
//                int tmp = arr[a - 1][j];
//                arr[b - 1][j] = arr[a - 1][j];
//                arr[a - 1][j] = arr[b - 1][j];
//             }
//        }
//        else if (ch == 'c')//交换列
//        {
//            for (i = 0; i < n; i++)
//            {
//                int tmp = arr[i][a - 1];
//                arr[i][a - 1] = arr[i][b - 1];
//                arr[i][b - 1] = tmp;
//            }
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//int main() {
//    int n, m, i, j;
//    scanf("%d%d", &n, &m);
//    int arr[100];
//    int sz = n * m;
//    for (i = 0; i < sz; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i < m; i++)//m=3  n=2
//    {
//        int c = 0;
//        for (j = i; j <= i + m; j = j + m)
//        {
//            printf("%d ", arr[j]);
//            c++;
//        }
//        if (c  % n == 0)// 1  2
//            printf("\n");
//    }
//    return 0;
//}


//int main() {
//    int a, b;
//    scanf("%d", &a);
//    int count = 1;
//    int i = 0, j = 0, arr[100][100];
//    int n = 1;
//    while (count <= a * a)
//    {
//        int m = 0;
//        if (i == 0)//1-->3-->5
//        {//左下走
//            arr[i][j] = count++;//1-->2*****
//            j++;//先向右走
//            for (m = 0; m < n; m++)
//            {
//                arr[i][j] = count++;//2-->3
//                j--, i++;
//            }
//            n++;
//        }
//        if (count == a * a - 1)
//        {
//            arr[a - 1][a - 1] = count++;
//            break;
//        }
//        if (j == 0)//2--4--6
//        {//右上走
//                arr[i][j] = count++;//3-->4
//            i++;//先下走
//            if (i == a)
//            {
//                arr[i][j] = count;
//            }
//            for (m = 0; m < n; m++)
//            {
//                arr[i][j] = count++;//4-->5
//                i--; j++;
//            }
//            n++;
//        }
//    }
//    for (i = 0; i < a; i++)
//    {
//        for (j = 0; j < a; j++)
//            printf("%d ", arr[i][j]);
//        printf("\n");
//    }
//    return 0;
//}


//int main() 
//{
//    int n;
//    scanf("%d", &n);
//    int arr[100][100];
//    int count = 1;
//    int i = 0, j = 0;
//    int direction = 1; // 1表示向上走，-1表示向下走
//    while (count <= n * n) {
//        arr[i][j] = count++;
//        if (direction == 1) {
//            if (j == n - 1) {
//                i++;
//                direction = -1;
//            }
//            else if (i == 0) {
//                j++;
//                direction = -1;
//            }
//            else {
//                i--;
//                j++;
//            }
//        }
//        else {
//            if (i == n - 1) {
//                j++;
//                direction = 1;
//            }
//            else if (j == 0) {
//                i++;
//                direction = 1;
//            }
//            else {
//                i++;
//                j--;
//            }
//        }
//    }
//
//    // 输出蛇形矩阵
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}