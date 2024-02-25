#define  _CRT_SECURE_NO_WARNINGS

#include"contact.h"

//void Initcon(struct contact* ps)
//{
//	assert(ps!=NULL);
//	ps->date = (struct PeoInfo*)malloc(ps->capacity * sizeof(struct PeoInfo));
//	if (ps->date == NULL)
//	{
//		return ;
//	}
//
//	ps->size = 0;
//	ps->capacity = CAPACITY;
//}

void Checkcapacity(struct contact* ps);

void Initcon(struct contact* ps)
{
	assert(ps != NULL);
	ps->size = 0;
	ps->capacity = CAPACITY;
	ps->date = (struct PeoInfo*)malloc(ps->capacity * sizeof(struct PeoInfo));
	if (ps->date == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//将文件的信息存贮到通讯录里面
	loadcontact(ps);
}


void loadcontact(struct contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		printf("loadcontact::%s\n", strerror(errno));
		return;
	}
	while (fread(&(tmp), sizeof(struct PeoInfo), 1, pfread))
	{
		Checkcapacity(ps);
		ps->date[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfread);
	pfread = NULL;
}


void Checkcapacity(struct contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* str=realloc(ps->date, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (str != NULL)
		{
			ps->date = str;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("%s\n", strerror(errno));
			printf("增容失败\n");
		}
	}
}

void Addcontact(struct contact* ps)
{
	assert(ps != NULL);
	Checkcapacity(ps);
	printf("情输入姓名:>");
	scanf("%s", ps->date[ps->size].name);
	printf("情输入年龄:>");
	scanf("%d", &(ps->date[ps->size].age));
	printf("情输入性别:>");
	scanf("%s", ps->date[ps->size].sex);
	printf("情输入电话:>");
	scanf("%s", ps->date[ps->size].tele);
	printf("情输入地址:>");
	scanf("%s", ps->date[ps->size].addr);
	ps->size++;
	printf("录入信息完成\n");
}

void Showcontact(const struct contact* ps)
{
	assert(ps != NULL);
	int i = 0;
	if (ps->size == 0)
	{
		printf("通讯录内容为空，无法打印\n");
	}
	else
	{
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-3s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-20s\t%-3d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
		}
}

static int Find_by_name(const struct contact* ps, char name[MAX_NAME])
{//static修饰可以使其函数仅可以再本。c生效
	//避免了污染
	assert(ps != NULL);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->date[i].name, name) == 0)
			return i;
	}
	return -1;
}
void Delcontact(struct contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];
	printf("请输入要删除联系人的姓名:>");
	scanf("%s", name);
	//查找
	//找到返回pos下标
	//找不到返回-1
	int pos=Find_by_name(ps, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j <ps->size ; j++)//
			//*******
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void Searchcontact(const struct contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];
	printf("请输入要查找联系人的姓名:>");
	scanf("%s", name);
	int pos = Find_by_name(ps, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
	}
	else
	{
		printf("信息如下:\n");
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

//void Modifycontact(struct contact* ps)
//{
//	assert(ps != NULL);
//	char name[MAX_NAME];
//	printf("请输入要修改联系人的姓名:>");
//	scanf("%s", name);
//	int pos = Find_by_name(ps, name);
//	if (pos == -1)
//	{
//		printf("要修改的联系人不存在\n");
//	}
//	else
//	{
//		printf("情输入姓名:>");
//		scanf("%s", ps->date[pos].name);
//		printf("情输入年龄:>");
//		scanf("%d", &(ps->date[pos].age));
//		printf("情输入性别:>");
//		scanf("%s", ps->date[pos].sex);
//		printf("情输入电话:>");
//		scanf("%s", ps->date[pos].tele);
//		printf("情输入地址:>");
//		scanf("%s", ps->date[pos].addr);
//		printf("修改信息完成\n");
//	}
//}


void Modifycontact(struct contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];
	printf("请输入要修改联系人的姓名:>");
	scanf("%s", name);
	int pos = Find_by_name(ps, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
	}
	else
	{
		int input = 0;
		do
		{
			printf("请输入你想修改此用户的哪项信息\n");
			printf(" 0.退出 1.姓名 2.年龄 3.性别 4.电话 5.地址:>\n");
			scanf("%d", &input);
			switch (input)
			{
			case NAME:
				printf("情输入姓名:>");
				scanf("%s", ps->date[pos].name);
				break;
			case AGE:
				printf("情输入年龄:>");
				scanf("%d", &(ps->date[pos].age));
				break;
			case SEX:
				printf("情输入性别:>");
				scanf("%s", ps->date[pos].sex);
				break;
			case TELE:
				printf("情输入电话:>");
				scanf("%s", ps->date[pos].tele);
				break;
			case ADDR:
				printf("情输入地址:>");
				scanf("%s", ps->date[pos].addr);
				break;
			case ERRO:
				printf("修改完成\n");
				break;
			default:
				printf("输入错误，请重新输入:>\n");
				break;
			}
		} while (input);
	}
}



int con_name(const void* e1, const void* e2)
{
	return (strcmp(((struct contact*)e1)->date->name, ((struct contact*)e2)->date->name));
}
void SortContact(struct contact* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("通讯录为空，无法排序\n");
		return;
	}
	qsort(ps->date, ps->size, sizeof(ps->date[0]), con_name);
	printf("排序成功\n");
	Showcontact(ps); 
}

void SaveContact(struct contact* ps)
{
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("SaveContact::%s", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct PeoInfo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}

void DestroyContact(struct contact* ps)
{
	assert(ps);
	free(ps->date);
	ps->date = NULL;
	ps->size = 0;
	printf("销毁成功\n");
}
