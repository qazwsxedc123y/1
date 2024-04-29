#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
class date
{
public:
	date(int year = 2, int month = 2, int day = 2);

	date(const date& d);

	bool operator<(date& d);

	bool operator==(date& d);

	bool operator!=(date& d);

	bool operator<=(date& d);

	int Get_month_day(int year, int month);

	date operator += (int day);

	date operator + (int day);

	date operator-=(int day);

	date operator-(int day);

	//���� �� ����

	int operator-(const date& d);

	date operator++();//ǰ��

	date operator++(int);//����

	//��ֵ
	date& operator=(const date& d);

	date operator--();
	date operator--(int);

	void print();
private:
	int _year;
	int _month;
	int _day;
};

