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
	//�����ṹ������
	struct contact con;
	//��ʼ���ṹ������
	Initcon(&con);
	do {
		menu();
		printf("���������ѡ��:>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������:>\n");
			break;
		}

	} while (input);
	return 0;
}