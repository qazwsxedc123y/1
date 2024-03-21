#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
int row = 0;//��
int col = 0;//��
int mine_num = 0;//�׵ĸ���
int cmp(const void* a, const void* b)//����qsort�����Ĳ����ȽϺ���
{
	Rank* aa = (Rank*)a;
	Rank* bb = (Rank*)b;
	return aa->time > bb->time;//�Ƚ�ʱ��
}
//���а�
void Update_Rank(Rank info)
{
	Rank arr[6] = { 0 };//������һ���ṹ������
	for (int i = 0; i < 6; i++)
	{
		arr[i].time = INT_MAX;//Ĭ��Ϊint��Χ�����ֵ
	}
	FILE* fp1 = fopen("rank.bin", "ab+"); //��ֹ��ʧ��
	if (!fp1)
	{
		printf("open failed");
		return;
	}
	fseek(fp1, 0, SEEK_SET);//�ļ�λ��ָ��ص��ļ���ͷ
	int num = fread(arr, sizeof(Rank), 5, fp1);//���ļ�
	arr[num] = info;//���ṹ�����info���������±�Ϊnum��
	qsort(arr, num + 1, sizeof(Rank), cmp);//����
	//��ӡ����
	if (num <= 4)
	{
		for (int i = 0; i <= num; i++)
		{
			printf("%-20s %-20d   ���������ǣ�%d\n", arr[i].name, arr[i].time, i + 1);
		}
	}
	else if (num >= 5)
	{
		for (int i = 0; i <= 4; i++)
		{
			printf("%-20s %-20d   ���������ǣ�%d\n", arr[i].name, arr[i].time, i + 1);

		}
	}
	FILE* fp2 = fopen("rank.bin", "wb"); //������ab+
	if (!fp2)
	{
		printf("open failed");
		return;
	}
	num = num < 5 ? num + 1 : 5;//���ֻ��5��
	fwrite(arr, sizeof(Rank), num, fp2);//д�ļ�
	//�ر�
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
	printf("�������û���: ");
	scanf("%s", name);

	printf("��ѡ����Ϸ�Ѷ�: \n");
	printf("***** 1.easy   *****\n");
	printf("***** 2.normal *****\n");
	printf("***** 3.hard   *****\n");

	scanf("%d", &input);
	//ѡ���Ѷ�
	do {
		scanf("%d", &input);
		//ѡ���Ѷ�
		switch (input)
		{
		case 1:row = 4, col = 4, mine_num = 15; break;
		case 2:row = 9, col = 9, mine_num = 10; break;
		case 3:row = 11, col = 11, mine_num = 15; break;
		default:printf("ѡ�����,����������\n");
			break;
		}
	} while (input != 1 && input != 2 && input != 3);

	//��������
	char** mine = (char**)malloc(sizeof(char*) * (row + 2));
	char** show = (char**)malloc(sizeof(char*) * (row + 2));
	for (int i = 0; i < row + 2; i++)
	{
		mine[i] = (char*)malloc(sizeof(char) * (col + 2));
		show[i] = (char*)malloc(sizeof(char) * (col + 2));
	}
	//��ʼ��mine����Ϊȫ�ַ�'0'
	InitBoard(mine, '0');
	//��ʼ��show����Ϊȫ'*'
	InitBoard(show, '*');
	//��ӡ����
	DisplayBoard(show);//ֻ��ӡ9*9������
	//������
	SetMine(mine);
	//DisplayBoard(mine);
	//���ǲ�����ҿ�����
	//�Ų���
	int start = (int)clock();
	int ret = FindMine(mine, show);//��mine���Ų�ŵ�show��
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
		printf("��ѡ��: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//ɨ��		
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����");
			break;

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}