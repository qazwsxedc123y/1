#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
int row = 0;//行
int col = 0;//列
int mine_num = 0;//雷的个数
int cmp(const void* a, const void* b)//传给qsort函数的参数比较函数
{
	Rank* aa = (Rank*)a;
	Rank* bb = (Rank*)b;
	return aa->time > bb->time;//比较时间
}
//排行榜
void Update_Rank(Rank info)
{
	Rank arr[6] = { 0 };//定义了一个结构体数组
	for (int i = 0; i < 6; i++)
	{
		arr[i].time = INT_MAX;//默认为int范围的最大值
	}
	FILE* fp1 = fopen("rank.bin", "ab+"); //防止打开失败
	if (!fp1)
	{
		printf("open failed");
		return;
	}
	fseek(fp1, 0, SEEK_SET);//文件位置指针回到文件开头
	int num = fread(arr, sizeof(Rank), 5, fp1);//读文件
	arr[num] = info;//将结构体变量info存入数组下标为num处
	qsort(arr, num + 1, sizeof(Rank), cmp);//排序
	//打印排名
	if (num <= 4)
	{
		for (int i = 0; i <= num; i++)
		{
			printf("%-20s %-20d   您的排名是：%d\n", arr[i].name, arr[i].time, i + 1);
		}
	}
	else if (num >= 5)
	{
		for (int i = 0; i <= 4; i++)
		{
			printf("%-20s %-20d   您的排名是：%d\n", arr[i].name, arr[i].time, i + 1);

		}
	}
	FILE* fp2 = fopen("rank.bin", "wb"); //不能用ab+
	if (!fp2)
	{
		printf("open failed");
		return;
	}
	num = num < 5 ? num + 1 : 5;//最多只有5个
	fwrite(arr, sizeof(Rank), num, fp2);//写文件
	//关闭
	fclose(fp1);
	fclose(fp2);
}

void menu()
{
	printf("**********************\n");
	printf("*****  1.play  *******\n");
	printf("*****  0.exit  *******\n");
	printf("**********************\n");
}

void game()
{
	int input = 0;
	char name[20] = { 0 };
	printf("请输入用户名: ");
	scanf("%s", name);

	printf("请选择游戏难度: \n");
	printf("***** 1.easy   *****\n");
	printf("***** 2.normal *****\n");
	printf("***** 3.hard   *****\n");

	scanf("%d", &input);
	//选择难度
	do {
		scanf("%d", &input);
		//选择难度
		switch (input)
		{
		case 1:row = 4, col = 4, mine_num = 15; break;
		case 2:row = 9, col = 9, mine_num = 10; break;
		case 3:row = 11, col = 11, mine_num = 15; break;
		default:printf("选择错误,请重新输入\n");
			break;
		}
	} while (input != 1 && input != 2 && input != 3);

	//创建数组
	char** mine = (char**)malloc(sizeof(char*) * (row + 2));
	char** show = (char**)malloc(sizeof(char*) * (row + 2));
	for (int i = 0; i < row + 2; i++)
	{
		mine[i] = (char*)malloc(sizeof(char) * (col + 2));
		show[i] = (char*)malloc(sizeof(char) * (col + 2));
	}
	//初始化mine数组为全字符'0'
	InitBoard(mine, '0');
	//初始化show数组为全'*'
	InitBoard(show, '*');
	//打印棋盘
	DisplayBoard(show);//只打印9*9的内容
	//布置雷
	SetMine(mine);
	//DisplayBoard(mine);
	//这是不给玩家看到的
	//排查雷
	int start = (int)clock();
	int ret = FindMine(mine, show);//从mine中排查放到show中
	Rank info;
	strncpy(info.name, name, 20);
	int end = (int)clock();
	info.time = end - start;
	if (ret)
		Update_Rank(info);
	free(mine);
	free(show);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//扫雷		
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误");
			break;

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}