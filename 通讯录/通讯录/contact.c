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
		printf("ͨѶ¼�������޷��ٽ������\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->date[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->date[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰:>");
		scanf("%s", ps->date[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("¼����Ϣ���\n");
	}
}

void Showcontact(const struct contact* ps)
{
	assert(ps != NULL);
	int i = 0;
	if (ps->size == 0)
	{
		printf("ͨѶ¼����Ϊ�գ��޷���ӡ\n");
	}
	else
	{
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-3s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
{//static���ο���ʹ�亯���������ٱ���c��Ч
	//��������Ⱦ
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
	printf("������Ҫɾ����ϵ�˵�����:>");
	scanf("%s", name);
	//����
	//�ҵ�����pos�±�
	//�Ҳ�������-1
	int pos=Find_by_name(ps, name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
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
		printf("ɾ���ɹ�\n");
	}
}

void Searchcontact(const struct contact* ps)
{
	assert(ps != NULL);
	char name[MAX_NAME];
	printf("������Ҫ������ϵ�˵�����:>");
	scanf("%s", name);
	int pos = Find_by_name(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
	}
	else
	{
		printf("��Ϣ����:\n");
		printf("%-20s\t%-3s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = Find_by_name(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->date[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->date[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->date[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->date[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->date[pos].addr);
		printf("�޸���Ϣ���\n");
	}
}