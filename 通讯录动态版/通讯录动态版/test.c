#define  _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void menu()
{
	printf("**************************************\n");
	printf("*****    1.add        2.del      *****\n");
	printf("*****    3.search     4.modify   *****\n");
	printf("*****    5.show       6sort      *****\n");
	printf("*****    7.save       0.exit     *****\n");
	printf("**************************************\n");
}
int main()
{
	int input = 0;
	//创建结构体数组
	struct contact con;
	//初始化结构体数组
	Initcon(&con);
	do {
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入:>\n");
			break;
		}

	} while (input);
	return 0;
}