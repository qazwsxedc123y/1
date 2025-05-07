#pragma once
#include "CP2.h"
#include "CP3.h"    
#include <math.h>
class CTransform3
{
public:
    CTransform3();
    virtual ~CTransform3(void);

    // ���ö�������Ͷ�������
    void SetMatrix(CP3* Point, int ptNumber);

    // ���任�����ʼ��Ϊ��λ����
    void Identity(void);

    // ƽ�Ʊ任
    void Translate(double tx, double ty, double tz);

    // �����任�������ԭ�㣩
    void Scale(double sx, double sy, double sz);

    // �����任�������ָ���㣩
    void Scale(double sx, double sy, double sz, CP3 p);

    // ��ת�任����X�ᣩ
    void RotateX(double beta);

    // ��ת�任����X�ᣬ��ָ����Ϊ���ģ�
    void RotateX(double beta, CP3 p);

    // ��ת�任����Y�ᣩ
    void RotateY(double beta);

    // ��ת�任����Y�ᣬ��ָ����Ϊ���ģ�
    void RotateY(double beta, CP3 p);

    // ��ת�任����Z�ᣩ
    void RotateZ(double beta);

    // ��ת�任����Z�ᣬ��ָ����Ϊ���ģ�
    void RotateZ(double beta, CP3 p);

    // ����任������ԭ�㣩
    void ReflectO(void);

    // ����任������XOYƽ�棩
    void ReflectXOY(void);

    // ����任������YOZƽ�棩
    void ReflectYOZ(void);

    // ����任������ZOXƽ�棩
    void ReflectZOX(void);

    // ���б任����ά�����ж�����ʽ�������ṩһ��ʵ�֣�
    void Shear(double b, double c, double d);

    // ������ˣ�Ӧ�ñ任��
    void MultiplyMatrix(void);

private:
    double T[4][4];  // 4x4 ��ά�任����
    CP3* P;          // ��������
    int ptNumber;     // ��������
};

