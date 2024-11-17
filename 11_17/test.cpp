#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<set>
#include<bitset>
#include<unordered_map>
#include<map>

using namespace std;
#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //ͼ�����ܴﵽ����󳤶�
using namespace std;
typedef struct
{//ͼ����Ϣ����
    char no[20];    //ͼ��ISBN
    char name[50];   //ͼ������
    float price;   //ͼ��۸�
}Book;
typedef struct
{//ͼ����˳��洢�ṹ����ΪSqList
    Book* elem;                   //�洢�ռ�Ļ���ַ
    int length;                   //ͼ����е�ǰͼ�����
}SqList;
int InitList_Sq(SqList& L)
{//����һ���յ�˳���L
    L.elem = new Book[MAXSIZE];     //Ϊ˳������һ����СΪMAXSIZE������ռ�
    if (!L.elem)exit(OVERFLOW);    //�洢����ʧ���˳�
    L.length = 0;                   //�ձ���Ϊ0
    return OK;
}
int Input_Sq(SqList& L)
{//˳��������
/**************begin************/
    for (int i = 0; i < MAXSIZE; i++)
    {
        cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
        if ((L.elem[i].no, "0") == 0 && (L.elem[i].name, "0") == 0 && (L.elem[i].price, '0') == 0)
            return OK;
        else
            L.length++;
    }
    return OK;


    /**************end************/
}
int Output_Sq(SqList L)
{//˳�������
/**************begin************/
    cout << L.length << endl;
    for (int i = 0; i < L.length; i++) {
        // if(L.elem[i].no == '0'&&L.elem[i].name=='0'&&L.elem[i].price=='0')
        //     break;
        cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2) << L.elem[i].price << endl;
    }
    return OK;


    /**************end************/
}
int main()
{
    SqList L;                   //����һ��SqList���͵ı���L
    InitList_Sq(L);             //��ʼ��һ���յ�˳���L
    Input_Sq(L);                //��������
    Output_Sq(L);               //�������
    return 0;
}
//struct KeyToInt1
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt1" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt2
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt2" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt3
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt3" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt4
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt4" << endl;
//		return (size_t)1;
//	}
//};
//
//struct KeyToInt5
//{
//	size_t operator()(const string& key)
//	{
//		cout << "KeyToInt5" << endl;
//		return (size_t)1;
//	}
//};
//
//
//// ���貼¡��������Ԫ������ΪK��ÿ��Ԫ�ض�Ӧ5����ϣ����
//template<class K, class KToInt1 = KeyToInt1, class KToInt2 = KeyToInt2,
//	class KToInt3 = KeyToInt3, class KToInt4 = KeyToInt4,
//	class KToInt5 = KeyToInt5>
//class BloomFilter
//{
//public:
//	BloomFilter(size_t size)  // ��¡��������Ԫ�ظ���
//		: _bmp(5 * size)
//		, _size(0)
//	{}
//
//	// ��������
//	bool Insert(const K& key)
//	{
//		size_t hashi1 = KeyToInt1()(key);
//		size_t hashi2 = KeyToInt2()(key);
//		size_t hashi3 = KeyToInt3()(key);
//		size_t hashi4 = KeyToInt4()(key);
//		size_t hashi5 = KeyToInt5()(key);
//		if (IsInBloomFilter(hashi1)
//			&& IsInBloomFilter(hashi2)
//			&& IsInBloomFilter(hashi3)
//			&& IsInBloomFilter(hashi4)
//			&& IsInBloomFilter(hashi5))
//		{
//			return false;
//		}
//		_bmp.set(hash1);
//		_bmp.set(hash2);
//		_bmp.set(hash3);
//		_bmp.set(hash4);
//		_bmp.set(hash5);
//		return true;
//	}
//	// ����ڲ���
//	// �ڷ���true�����ڷ���false
//	bool IsInBloomFilter(const K& key)
//	{
//		size_t hashi1 = KeyToInt1()(key);
//		size_t hashi2 = KeyToInt2()(key);
//		size_t hashi3 = KeyToInt3()(key);
//		size_t hashi4 = KeyToInt4()(key);
//		size_t hashi5 = KeyToInt5()(key);
//		if (_bmp.test(hashi1)
//			&& _bmp.test(hashi2)
//			&& _bmp.test(hashi3)
//			&& _bmp.test(hashi4)
//			&& _bmp.test(hashi5))
//		{
//			return true;
//		}
//		return false;
//	}
//	// λͼ��֧��ɾ��
//private:
//	bitset _bmp;
//	size_t _size;   // ʵ��Ԫ�صĸ���
//};
//
//
//class bitset
//{
//public:
//	bitset(size_t bitCount)
//		: _bit((bitCount >> 5) + 1)
//		, _bitCount(bitCount)
//	{}
//	// ��which����λ��1
//	void set(size_t which)
//	{
//		int i = which / 32;
//		int j = which % 32;
//		_bit[i] |= (1 << j);
//	}
//	// ��which����λ��0
//	void reset(size_t which)
//	{
//		int i = which / 32;
//		int j = which % 32;
//		_bit[i] &= (~(1 << j));
//	}
//	// ���λͼ��which�Ƿ�Ϊ1
//	bool test(size_t which)
//	{
//		int i = which / 32;
//		int j = which % 32;
//		int ret = (1 << j) & _bit[i];
//		return ret;
//	}
//	size_t size()const
//	{ 
//		return _bitCount; 
//	}
//
//private:
//	vector<int> _bit;
//	size_t _bitCount;
//};