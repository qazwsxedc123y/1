#pragma once
class CSphere
{
public:
	CSphere(void)
	{
	}
	virtual ~CSphere(void)
	{
	}
	void SerParameter(int R_, CPoint CenterPoint_) // �������ģ��뾶
	{
		this->R = R_;
		this->CenterPoint = CenterPoint_;
	}
	void Draw(CDC* pDC)  // ��������
	{
		CPoint TopLeft(CenterPoint.x - R, CenterPoint.y - R);  // �����ε����Ͻǵ�
		CPoint BottomRight(CenterPoint.x + R, CenterPoint.y + R);  // �����ε����½ǵ�
		CRect Square(TopLeft, BottomRight); // ����������
		pDC->Ellipse(Square);
	}
public:
	int R;
	CPoint CenterPoint;
};

