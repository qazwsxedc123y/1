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
	//���ļ�����Ϣ������ͨѶ¼����
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
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("%s\n", strerror(errno));
			printf("����ʧ��\n");
		}
	}
}

void Addcontact(struct contact* ps)
{
	assert(ps != NULL);
	Checkcapacity(ps);
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

//void Modifycontact(struct contact* ps)
//{
//	assert(ps != NULL);
//	char name[MAX_NAME];
//	printf("������Ҫ�޸���ϵ�˵�����:>");
//	scanf("%s", name);
//	int pos = Find_by_name(ps, name);
//	if (pos == -1)
//	{
//		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
//	}
//	else
//	{
//		printf("����������:>");
//		scanf("%s", ps->date[pos].name);
//		printf("����������:>");
//		scanf("%d", &(ps->date[pos].age));
//		printf("�������Ա�:>");
//		scanf("%s", ps->date[pos].sex);
//		printf("������绰:>");
//		scanf("%s", ps->date[pos].tele);
//		printf("�������ַ:>");
//		scanf("%s", ps->date[pos].addr);
//		printf("�޸���Ϣ���\n");
//	}
//}


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
		int input = 0;
		do
		{
			printf("�����������޸Ĵ��û���������Ϣ\n");
			printf(" 0.�˳� 1.���� 2.���� 3.�Ա� 4.�绰 5.��ַ:>\n");
			scanf("%d", &input);
			switch (input)
			{
			case NAME:
				printf("����������:>");
				scanf("%s", ps->date[pos].name);
				break;
			case AGE:
				printf("����������:>");
				scanf("%d", &(ps->date[pos].age));
				break;
			case SEX:
				printf("�������Ա�:>");
				scanf("%s", ps->date[pos].sex);
				break;
			case TELE:
				printf("������绰:>");
				scanf("%s", ps->date[pos].tele);
				break;
			case ADDR:
				printf("�������ַ:>");
				scanf("%s", ps->date[pos].addr);
				break;
			case ERRO:
				printf("�޸����\n");
				break;
			default:
				printf("�����������������:>\n");
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
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
		return;
	}
	qsort(ps->date, ps->size, sizeof(ps->date[0]), con_name);
	printf("����ɹ�\n");
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
	printf("���ٳɹ�\n");
}
