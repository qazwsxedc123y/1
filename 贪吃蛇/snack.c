#define  _CRT_SECURE_NO_WARNINGS

#include"snack.h"

void cursor_hide()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标 
	SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态 
}

void SetPos(int x,int y)
{
	//获得标准输出设备的句柄
	HANDLE hOutput = NULL;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置,到pos
	COORD pos = { x,y };
	SetConsoleCursorPosition(hOutput, pos);
}

void Welcome_game()
{
	SetPos(35, 12);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(36, 18);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"用 ↑.↓.←.→ 来控制蛇的移动");
	SetPos(25, 15);
	wprintf(L"按F3加速，F4减速");
	SetPos(25, 16);
	wprintf(L"按ESC正常退出游戏，按空格暂停游戏");
	SetPos(25, 17);
	wprintf(L"加速可以获得更多的分数");
	SetPos(25, 18);
	wprintf(L"由能力有限公司提供技术支持");
	SetPos(0, 25);
	system("pause");
	system("cls");
}

void CreatMap()
{
	//上
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	}
	//下
	SetPos(0, 26);
	for (int i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'□');
	} 
	//左
	for (int i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", L'□');
	}
	//右
	for (int i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", L'□');
	}
}



void CreateSnack(pSnack ps)
{
	//默认开始初始化为5个结点
	pSnackNode cur = NULL;
	for (int i = 0; i < 5; i++)
	{
		cur =(pSnackNode)malloc(sizeof(SnackNode));
		cur->next = NULL;
		cur->x = POS_X + i * 2;
		cur->y = POS_Y;
		if (ps->_psnack == NULL)//第一次头插
		{
			ps->_psnack = cur;
		}
		else
		{
			cur->next = ps->_psnack;
			ps->_psnack = cur;
		}

	}
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", Body);
		cur = cur->next;
	}
	cur= ps->_psnack;

	//设置蛇的相关信息
	ps->_dir = RIGHT;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;
	ps->_status = OK;
}

void CreateFood(pSnack ps)
{
	int x = 0;//2-54
	int y = 0;//1-25
	again:
	do{
		x = rand() % 53 + 2;
		y = rand() % 24 + 1;
	} while (x%2!=0);

	//检测改坐标是否与蛇身重合 
	pSnackNode cur = ps->_psnack;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}
	pSnackNode SnackFood = (pSnackNode)malloc(sizeof(SnackNode));
	if (SnackFood == NULL)
	{
		perror("CreateFood malloc fail");
		return;
	}
	SnackFood->x = x;
	SnackFood->y = y;
	SnackFood->next = NULL;
	SetPos(x, y);
	wprintf(L"%lc", Food);
	ps->_pfood = SnackFood;
}

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

void GameStart(pSnack ps)
{
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	//1光标隐藏
	cursor_hide();

	//2.打印环境界面
	//第一个界面，欢迎
	// 第二个界面，介绍怎么操作游戏
	Welcome_game();//+3.功能介绍
	CreatMap();
	

	//创建蛇
	CreateSnack(ps);
	//创建食物
	CreateFood(ps);


	//SetPos(0, 29);
	//system("pause");
}

void PrintHelpInfo()
{
	SetPos(64, 10);
	wprintf(L"不能穿墙，不能咬到自己");
	SetPos(64, 12);
	wprintf(L"用 ↑.↓.←.→ 来控制蛇的移动");
	SetPos(64, 14);
	wprintf(L"按F3加速，F4减速");
	SetPos(64, 16);
	wprintf(L"按ESC正常退出游戏，按空格暂停游戏");
	SetPos(64, 18);
	wprintf(L"能力有限公司提供支持");
	SetPos(0, 29);
	//	system("pause");
}

bool Next_Is_Food(pSnackNode pn, pSnack ps)
{
	return (ps->_pfood->x == pn->x && ps->_pfood->y == pn->y);
}

void Eat_Food(pSnackNode pn, pSnack ps)
{
	ps->_pfood->next = ps->_psnack;
	ps->_psnack = ps->_pfood;
	free(pn);
	pn = NULL;
	pSnackNode cur = ps->_psnack;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", Body);
		cur = cur->next;
	}
	ps->_sum_score += ps->_food_weight;
	//在重新生成食物
	CreateFood(ps);
}

void No_Food(pSnackNode pn, pSnack ps)
{
	pn->next = ps->_psnack;
	ps->_psnack = pn;
	pSnackNode cur = ps->_psnack;
	//打印出来五个了
	while (cur->next->next != NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", Body);
		cur = cur->next;
	}
	//将第六个位置打印为空格
    //释放第六个
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	
	free(cur->next);
	//再将倒数第二个的next为NULL
	cur->next = NULL;
}

void Kill_By_Wall(pSnack ps)
{
	if(ps->_psnack->x == 0 || ps->_psnack->x == 56 ||
		ps->_psnack->y == 0 || ps->_psnack->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

void Kill_By_Self(pSnack ps)
{
	pSnackNode cur = ps->_psnack -> next;
	while (cur)
	{
		if (cur->x == ps->_psnack->x && cur->y == ps->_psnack->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}

void SnackMove(pSnack ps)
{
	pSnackNode pNextNode = (pSnackNode)malloc(sizeof(SnackNode));
	if (pNextNode == NULL)
	{
		perror("SnackMove::malloc fail");
		return;
	}
	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_psnack->x;
		pNextNode->y = ps->_psnack->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_psnack->x;
		pNextNode->y = ps->_psnack->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_psnack->x - 2;
		pNextNode->y = ps->_psnack->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_psnack->x + 2;
		pNextNode->y = ps->_psnack->y;
		break;
	}
	//下一个位置是食物
	if (Next_Is_Food(pNextNode, ps))
	{
		Eat_Food(pNextNode,ps);
	}
	else
	{
		No_Food(pNextNode, ps);
	}

	//检测是否被撞墙死
	Kill_By_Wall(ps);

	//检测是否被撞自己死
	Kill_By_Self(ps);
}

void GameRun(pSnack ps)
{
	PrintHelpInfo();
	//SetPos(64, 10);
	do {
		SetPos(64, 6);
		wprintf(L"当前的总分数为：");
		printf("%d ", ps->_sum_score);
		SetPos(64, 8);
		wprintf(L"当前单个食物分数为：");
		printf("%d ", ps->_food_weight);

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
		//暂停  退出  加速  减速  
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//正常退出游戏
			ps->_status = END_OK;
		}
		else if (KEY_PRESS(VK_F3))
		{
			//加速
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			//减速
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}

		//实现蛇的移动
		SnackMove(ps);
		Sleep(ps->_sleep_time);
	} while (ps->_status==OK);
	//移动
	//实施打印情况
}



void GameEnd(pSnack ps)
{
	SetPos(24, 12);
	switch (ps->_status)
	{
	case END_OK:
		wprintf(L"您主动结束游戏\n");
		break;
	case KILL_BY_WALL:
		wprintf(L"您撞到墙上，游戏结束\n");
		break;
	case KILL_BY_SELF:
		wprintf(L"您撞到了自己，游戏结束\n");
		break;
	}

	//释放蛇身的链表

	pSnackNode cur = ps->_psnack;
	while (cur)
	{
		pSnackNode del = cur;
		cur = cur->next;
		free(del);
	}
}
