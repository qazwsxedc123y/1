//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//int n, a[114514], p, l;//���鿪��һ��
//string q;
//#include<iostream>
//using namespace std;
//int main()
//{
//	int ans = 0;
//	for (int i = 1; i <= 5; i++)
//	{
//		char a, b, c, d;
//		cin >> a >> b >> c >> d;
//		if (a == c && d - b == 1) ans++;
//	}
//	cout << ans;
//	return 0;
//}
//void C()//�˷�
//{
//	for (int i = 1; i <= l; i++)
//		a[i] *= 2;//��λ��2
//	for (int i = 1; i <= l; i++)//��λ
//	{
//		a[i + 1] += a[i] / 10;
//		a[i] %= 10;
//	}
//	if (a[l + 1])//������λ��ǰһλ��λ����0��Ҫ���ӳ���
//		l++;
//}
//int main()
//{
//	cin >> n >> q;//qΪ�����С��
//	reverse(q.begin(), q.end());//��תq�����������
//	p = q.find(".");//p�����ָ�������С������
//	q.erase(p, 1);//�ѷ��˵�С����ɾ��
//	l = q.size();//lΪС���ܳ�
//	for (int i = 0; i < l; i++)
//		a[i + 1] = q[i] - 48;//�ַ���ת��������
//	for (int i = 1; i <= n; i++)//n�γ�2
//		C();
//	if (a[p] >= 5)//С�����ֵ�һλΪ5���������λ
//		a[p + 1]++;
//	for (int i = p + 1; i <= l; i++)//����λ
//	{
//		a[i + 1] += a[i] / 10;
//		a[i] %= 10;
//	}
//	if (a[l + 1])//�ٴμ�����λ
//		l++;
//	for (int i = l; i > p; i--)//��Ϊǰ���������������ﵹ�����
//		cout << a[i];
//	return 0;
//}


//#include <iostream>
//#include <string>
//
//using namespace std;
//long long n, t;
//string s;
//int main()
//{
//    cin >> n >> t;
//    cin >> s;
//
//    //��ʱ����Ҫ�Ż�
//    for (int i = 0; i < t; i++)
//    {
//        for (int j = n - 1; j >= 1; j--)
//        {
//            s[j] = (s[j] - '0') ^ (s[j - 1] - '0') + '0';
//        }
//    }
//    cout << s;
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;
long long n, t, x = 1;
string s;
int main()
{
    n = 5, t = 9;
    s = 10110;
    // 2 -> 2
    // 3 -> 4
    // 4 -> 4
    // 5 -> 8
    // 6 -> 8
    // 7 -> 16
    // �ֽ��� 1 3 5 7 9
    //��ʱ����Ҫ�Ż�
    while (n > x) 
        x = x << 1;
    t = t % x;
    for (int i = 0; i < t; i++)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            s[j] = (s[j] - '0') ^ (s[j - 1] - '0') + '0';
        }
    }
    cout << s;
    return 0;
}