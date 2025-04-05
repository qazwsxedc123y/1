
// testView.h: CtestView 类的接口
//

#pragma once
#include "Cwindmill.h"

class CtestView : public CView
{
public:
	void DoubleBuffer(CDC* pDC);
	void DrawObject(CDC* memDC);
	void OnPlay();
	void OnTimer(UINT_PTR nIDEvent);
protected:
	int nWidth, nHeight;
	Cwindmill windmill;
	bool bPlay;
	double beta;
	CTransform transform;
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
};

#ifndef _DEBUG  // testView.cpp 中的调试版本
inline CtestDoc* CtestView::GetDocument() const
   { return reinterpret_cast<CtestDoc*>(m_pDocument); }
#endif

