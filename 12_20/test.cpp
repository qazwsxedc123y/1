#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int n, a[114514], p, l;//���鿪��һ��
string q;
void C()//�˷�
{
	for (int i = 1; i <= l; i++)
		a[i] *= 2;//��λ��2
	for (int i = 1; i <= l; i++)//��λ
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if (a[l + 1])//������λ��ǰһλ��λ����0��Ҫ���ӳ���
		l++;
}
int main()
{
	cin >> n >> q;//qΪ�����С��
	reverse(q.begin(), q.end());//��תq�����������
	p = q.find(".");//p�����ָ�������С������
	q.erase(p, 1);//�ѷ��˵�С����ɾ��
	l = q.size();//lΪС���ܳ�
	for (int i = 0; i < l; i++)
		a[i + 1] = q[i] - 48;//�ַ���ת��������
	for (int i = 1; i <= n; i++)//n�γ�2
		C();
	if (a[p] >= 5)//С�����ֵ�һλΪ5���������λ
		a[p + 1]++;
	for (int i = p + 1; i <= l; i++)//����λ
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if (a[l + 1])//�ٴμ�����λ
		l++;
	for (int i = l; i > p; i--)//��Ϊǰ���������������ﵹ�����
		cout << a[i];
	return 0;
}