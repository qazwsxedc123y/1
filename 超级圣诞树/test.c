#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n=5;
    //scanf("%d", &n);
    int arr[100][100] = { {0,0,1,0,0},{0,1,0,1,0},{1,0,1,0,1} };
    int i, j = 0, k, row = 3, col = 5;
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j < row; j++)//����
        {
            for (k = 0; k < col; k++)
            {
                arr[j + row][k] = arr[j][k];
                arr[j + row][k + col + 1] = arr[j][k];
            }
        }
        //����λ��
        //1.�����
        for (j = 0; j < row; j++)
        {
            for (k = 0; k < col; k++)
            {
                arr[j][k] = 0;
            }
        }
        //�������м�  ��i-1���
        for (j = 0; j < row; j++)
        {
            for (k = (col + 1) / 2; k < col + (col + 1) / 2; k++)
            {
                arr[j][k] = arr[j + row][k - (col + 1) / 2];
            }
        }
        //���ݹ��ɺ͵ݹ�˼�� �������ı仯��2�η��й�ϵ
        row *= 2;
        col = col * 2 + 1;//����ļ�1�Ƿ���Ϊ���м����������

    }
    //��ӡʥ����
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                printf(" ");
            }
            else if(arr[i][j] == 1)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < col / 2; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    return 0;
}