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
	void SerParameter(int R_, CPoint CenterPoint_) // 设置球心，半径
	{
		this->R = R_;
		this->CenterPoint = CenterPoint_;
	}
	void Draw(CDC* pDC)  // 绘制球体
	{
		CPoint TopLeft(CenterPoint.x - R, CenterPoint.y - R);  // 正方形的左上角点
		CPoint BottomRight(CenterPoint.x + R, CenterPoint.y + R);  // 正方形的右下角点
		CRect Square(TopLeft, BottomRight); // 定义正方形
		pDC->Ellipse(Square);
	}
public:
	int R;
	CPoint CenterPoint;
};

