#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

void SetPos(short x, short y)
{
	//��ñ�׼����豸�ľ��
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//��λ����λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"��ӭ����̰����С��Ϸ\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"�� ��. �� . �� . �� �������ߵ��ƶ�����F3���٣�F4����\n");
	SetPos(25, 15);
	wprintf(L"�����ܹ��õ����ߵķ���\n");

	SetPos(42, 20);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//��
	int i = 0;
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//��
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}

	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}

}

void InitSnake(pSnake ps)
{
	int i = 0;
	pSnakeNode cur = NULL;

	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;

		//ͷ�巨��������
		if (ps->_pSnake == NULL) //������
		{
			ps->_pSnake = cur;
		}
		else //�ǿ�
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//����̰���ߵ�����
	ps->_dir = RIGHT;//Ĭ������
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//��λ�Ǻ���
	ps->_status = OK;

}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;

	//����x��2�ı���
	//x��2~54
	//y: 1~25
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);

	//x��y�����겻�ܺ��ߵ����������ͻ

	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//����ʳ��Ľڵ�
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}

	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	SetPos(x, y);//��λλ��
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
}

void GameStart(pSnake ps)
{
	//0. �����ô��ڵĴ�С���ٹ������
	system("mode con cols=100 lines=30");
	system("title ̰����");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//Ӱ�ع�����
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(houtput, &CursorInfo);//���ÿ���̨���״̬

	//1. ��ӡ��������͹��ܽ���
	WelcomeToGame();
	//2. ���Ƶ�ͼ
	CreateMap();
	//3. ������
	InitSnake(ps);
	//4. ����ʳ��
	CreateFood(ps);
}

void PrintHelpInfo()
{
	SetPos(64, 14);
	wprintf(L"%ls", L"���ܴ�ǽ������ҧ���Լ�");
	SetPos(64, 15);
	wprintf(L"%ls", L"�� ��. �� . �� . �� �������ߵ��ƶ�");
	SetPos(64, 16);
	wprintf(L"%ls", L"��F3���٣�F4����");
	SetPos(64, 17);
	wprintf(L"%ls", L"��ESC�˳���Ϸ�����ո���ͣ��Ϸ");

	SetPos(64, 18);
	wprintf(L"%ls", L"���ؾ�ҵ������");
}

#define KEY_PRESS(vk)  ((GetAsyncKeyState(vk)&1)?1:0)


void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

//int NextIsFood(pSnakeNode pn, pSnake ps)
//{
//	if (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y)
//		return 1;
//	else
//		return 0;
//}

int NextIsFood(pSnakeNode pn, pSnake ps)
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}

void EatFood(pSnakeNode pn, pSnake ps)
{
	//ͷ�巨
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	//�ͷ���һ��λ�õĽڵ�
	free(pn);
	pn = NULL;

	pSnakeNode cur = ps->_pSnake;
	//��ӡ��
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;

	//���´���ʳ��
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps)
{
	//ͷ�巨
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next != NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//�����һ������ӡ�ɿո�
	SetPos(cur->next->x, cur->next->y);
	printf("  ");

	//�ͷ����һ�����
	free(cur->next);

	//�ѵ����ڶ����ڵ�ĵ�ַ��ΪNULL
	cur->next = NULL;
}


void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}

void SnakeMove(pSnake ps)
{
	//����һ����㣬��ʾ�߼���������һ���ڵ�
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}

	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}

	//�����һ�����괦�Ƿ���ʳ��
	if (NextIsFood(pNextNode, ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}

	//������Ƿ�ײǽ
	KillByWall(ps);
	//������Ƿ�ײ���Լ�
	KillBySelf(ps);
}


void GameRun(pSnake ps)
{
	//��ӡ������Ϣ
	PrintHelpInfo();
	do
	{
		//��ӡ�ܷ�����ʳ��ķ�ֵ
		SetPos(64, 10);
		printf("�ܷ���:%d\n", ps->_score);
		SetPos(64, 11);
		printf("��ǰʳ��ķ���:%2d\n", ps->_food_weight);

		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//�����˳���Ϸ
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
			//����
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			//����
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}

		SnakeMove(ps);//����һ���Ĺ���

		Sleep(ps->_sleep_time);

	} while (ps->_status == OK);
}

void GameEnd(pSnake ps)
{
	SetPos(24, 12);
	switch (ps->_status)
	{
	case END_NORMAL:
		wprintf(L"������������Ϸ\n");
		break;
	case KILL_BY_WALL:
		wprintf(L"��ײ��ǽ�ϣ���Ϸ����\n");
		break;
	case KILL_BY_SELF:
		wprintf(L"��ײ�����Լ�����Ϸ����\n");
		break;
	}

	//�ͷ����������

	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}