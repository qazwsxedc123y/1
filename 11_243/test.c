#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int n;
    printf("������һ��������n(1 < n < 20)��");
    scanf("%d", &n);

    while (n <= 1 || n >= 20) {
        printf("���벻����Ҫ������������һ��������n(1 < n < 20)��");
        scanf("%d", &n);
    }

    int nums[50];
    for (int i = 0; i < n; i++) {
        printf("�������%d��������", i + 1);
        scanf("%d", &nums[i]);
    }

    int max_num = nums[0];
    int max_index = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] > max_num) {
            max_num = nums[i];
            max_index = i;
        }
    }

    printf("���ֵ��%d�����±���%d\n", max_num, max_index);

    return 0;
}