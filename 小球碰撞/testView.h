
// testView.h: CtestView 类的接口
//

#pragma once
#include "CSphere.h"
#include "CExa2_17Doc.h"

class CtestView : public CView
{
public:
	CtestView()
	{
		bPlay = FALSE;
		sphere.R = GetSystemMetrics(SM_CXFULLSCREEN) / 20;
		sphere.CenterPoint.x = 200, sphere.CenterPoint.y = 200;
		Direction.x = 1;
		Direction.y = 1;
	}
	void OnDraw(CDC* pDC)
	{
		CExa2_17Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
	}
protected: // 仅从序列化创建
	CtestView() noexcept;
	DECLARE_DYNCREATE(CtestView)

// 特性
public:
	CtestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CtestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	void DoubleBuffer(CDC* pDC);    // 双缓冲函数
	void CollisionDetection(void);  // 碰撞检测函数
	void DrawObject(CDC* pDC);      // 绘图函数
protected:
	int nWidth, nHeight;
	CSphere sphere;
	CPoint Direction;
	BOOL bPlay;
};

#ifndef _DEBUG  // testView.cpp 中的调试版本
inline CtestDoc* CtestView::GetDocument() const
   { return reinterpret_cast<CtestDoc*>(m_pDocument); }
#endif

