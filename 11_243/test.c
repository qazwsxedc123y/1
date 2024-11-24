#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int n;
    printf("请输入一个正整数n(1 < n < 20)：");
    scanf("%d", &n);

    while (n <= 1 || n >= 20) {
        printf("输入不符合要求，请重新输入一个正整数n(1 < n < 20)：");
        scanf("%d", &n);
    }

    int nums[50];
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个整数：", i + 1);
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

    printf("最大值是%d，其下标是%d\n", max_num, max_index);

    return 0;
}