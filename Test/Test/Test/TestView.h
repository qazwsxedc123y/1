﻿
// TestView.h: CTestView 类的接口
//

#pragma once
#include "CCube.h"
#include "CTransform3.h"

class CTestView : public CView
{
protected: // 仅从序列化创建
	CTestView() noexcept;
	DECLARE_DYNCREATE(CTestView)

// 特性
public:
	CTestDoc* GetDocument() const;

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
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	void DoubleBuffer(CDC* pDC);
	void DrawObject(CDC* pDC);
	CCube cube;
	CTransform3 transform;
	bool bPlay;
	int alpha, beta;

	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnTimer(UINT_PTR nIDEvent);
	void OnUpdatePlay(CCmdUI* pCmdUI);
	afx_msg void Onplay();
};

#ifndef _DEBUG  // TestView.cpp 中的调试版本
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

