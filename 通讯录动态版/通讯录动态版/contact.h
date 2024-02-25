#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

//#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define CAPACITY 3
enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW, 
	SORT,
	SAVE,
};
enum Information
{
	ERRO,
	NAME,
	AGE,
	SEX,
	TELE,
	ADDR,
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct contact
{
	struct PeoInfo *date;
	int size;
	int capacity;
};

void Initcon(struct contact* ps);

void Addcontact(struct contact* ps);

void Showcontact(const struct contact* ps);

void Delcontact(struct contact* ps);

void Searchcontact(const struct contact* ps);

void Modifycontact(struct contact* ps);

void SortContact(struct contact* ps);

void DestroyContact(struct contact* ps);

void SaveContact(struct contact* ps);

void loadcontact(struct contact* ps);