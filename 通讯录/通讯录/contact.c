#define  _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void Initcon(struct contact* ps)
{
	assert(ps!=NULL);
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;
}

void Addcontact(struct contact* ps)
{
	assert(ps != NULL);
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法再进行添加\n");
	}
	else
	{
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
		printf("情输入姓名:>");
		scanf("%s", ps->date[pos].name);
		printf("情输入年龄:>");
		scanf("%d", &(ps->date[pos].age));
		printf("情输入性别:>");
		scanf("%s", ps->date[pos].sex);
		printf("情输入电话:>");
		scanf("%s", ps->date[pos].tele);
		printf("情输入地址:>");
		scanf("%s", ps->date[pos].addr);
		printf("修改信息完成\n");
	}
}