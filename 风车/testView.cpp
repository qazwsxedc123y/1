
// testView.cpp: CtestView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test.h"
#endif

#include "testDoc.h"
#include "testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestView

IMPLEMENT_DYNCREATE(CtestView, CView)

BEGIN_MESSAGE_MAP(CtestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CtestView 构造/析构

CtestView::CtestView() noexcept
{
	// TODO: 在此处添加构造代码
	int R = GetSystemMetrics(SM_CXFULLSCREEN) / 10;
	int r = GetSystemMetrics(SM_CXFULLSCREEN) / 20;
	windmill.SetParameter(R, r);
	windmill.ReadPoint();
	windmill.ReadFace();
	beta = 2;
	bPlay = false;
	transform.SetMat(windmill.GetPoint(), 9);
}

CtestView::~CtestView()
{
}

BOOL CtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtestView 绘图

void CtestView::OnDraw(CDC* pDC)
{
	CtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DoubleBuffer(pDC);
}
void CtestView::DoubleBuffer(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	int nWidth = rect.Width();
	int nHeight = rect.Height();
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(nWidth, nHeight);
	pDC->SetViewportExt(nWidth, -nHeight);
	pDC->SetViewportOrg(nWidth / 2, nHeight / 2);
	rect.OffsetRect(-rect.Width() / 2, -nHeight / 2);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap NewBitmap, * pOldBitmap;
	NewBitmap.CreateCompatibleBitmap(pDC, nWidth, nHeight);
	pOldBitmap = memDC.SelectObject(&NewBitmap);

	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(nWidth, nHeight);
	memDC.SetViewportExt(nWidth, -nHeight);
	memDC.SetViewportOrg(nWidth / 2, nHeight / 2);
	memDC.FillSolidRect(rect, pDC->GetBkColor());

	DrawObject(&memDC);
	pDC->BitBlt(rect.left, rect.top, nWidth, nHeight, &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);

	memDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
	memDC.DeleteDC();
}

void CtestView::DrawObject(CDC* memDC)
{
	windmill.Draw(memDC);
}

void CtestView::OnPlay()
{
	// TODO: 在此添加命令处理程序代码
	bPlay = !bPlay;
	if (bPlay)
		SetTimer(1, 20, NULL);
	else
		KillTimer(1);
}

void CtestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	transform.Rotate(beta);
	Invalidate(FALSE);
	CView::OnTimer(nIDEvent);
}

// CtestView 打印

BOOL CtestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CtestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CtestView 诊断

#ifdef _DEBUG
void CtestView::AssertValid() const
{
	CView::AssertValid();
}

void CtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestDoc* CtestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestDoc)));
	return (CtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestView 消息处理程序
