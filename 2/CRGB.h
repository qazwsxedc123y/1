#pragma once
class CRGB
{
public:
    // ���캯������������
    CRGB();
    ~CRGB();

    // �������Ĺ��캯��������ָ����ɫ����ɫ����ɫ��͸���ȣ�Ĭ��͸����Ϊ0.0
    CRGB(double red, double green, double blue, double alpha = 0.0);

    // ��Ԫ���������ؼӷ���������������� CRGB �������
    friend CRGB operator + (const CRGB& c0, const CRGB& c1);

    // ��Ԫ���������س˷������������һ�������� CRGB �������
    friend CRGB operator * (double scalar, const CRGB& c);

    // ��Ա����������ɫ������һ���� [0,1] ����
    void Normalize(void);

public:
    // ���г�Ա�������洢��ɫ����ɫ����ɫ��͸���ȷ���
    double red;   // ��ɫ����
    double green; // ��ɫ����
    double blue;  // ��ɫ����
    double alpha; // ͸���ȷ���
};