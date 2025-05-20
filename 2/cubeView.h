
// cubeView.h: CcubeView 类的接口
//

#pragma once
#include "CCube.h"
#include "CTransform3.h"


class CcubeView : public CView
{
protected: // 仅从序列化创建
	CcubeView() noexcept;
	DECLARE_DYNCREATE(CcubeView)

// 特性
public:
	CcubeDoc* GetDocument() const;

// 操作
public:
	void DoubleBuffer(CDC* pDC); 
	void DrawObject(CDC* pDC);   
	CCube cube;
	int nWidth, nHeight;
	CTransform3 transform; // 变换对象
	bool bPlay; // 动画开关
	int alpha, beta; // 绕x、y轴的旋转角度
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
	virtual ~CcubeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOnplay();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags); // 键盘按下事件

};

#ifndef _DEBUG  // cubeView.cpp 中的调试版本
inline CcubeDoc* CcubeView::GetDocument() const
   { return reinterpret_cast<CcubeDoc*>(m_pDocument); }
#endif

