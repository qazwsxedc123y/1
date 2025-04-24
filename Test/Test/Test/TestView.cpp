
// TestView.cpp: CTestView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDR_Onplay, &CTestView::Onplay) 
END_MESSAGE_MAP()

// CTestView 构造/析构

CTestView::CTestView() noexcept
{
	// TODO: 在此处添加构造代码
	// TODO: 在此处添加构造代码
	cube.ReadPoint();
	cube.ReadFacet();
	transform.SetMatrix(cube.GetVertexArrayName(), 8);//初始化顶点矩阵
	double nEdge = 400;
	transform.Scale(nEdge, nEdge, nEdge);//将立方体的边长扩大400倍
	transform.Translate(-nEdge / 2, -nEdge / 2, -nEdge / 2);//将立方体中心点平移至坐标原点
	bPlay = false;
	alpha = 0, beta = 0;//模型绕x、y轴的初始旋转角度均为0
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTestView 绘图

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DoubleBuffer(pDC);
}

void CTestView::DoubleBuffer(CDC* pDC)//双缓冲函数
{
	CRect rect;
	GetClientRect(&rect);
	int nWidth = rect.Width();
	int nHeight = rect.Height();
	pDC->SetMapMode(MM_ANISOTROPIC);//自定义二维坐标系
	pDC->SetWindowExt(nWidth, nHeight);//设置窗口比例
	pDC->SetViewportExt(nWidth, -nHeight);//设置视窗比例, 且x轴水平向右为正, y轴垂直向上为正
	pDC->SetViewportOrg(nWidth / 2, nHeight / 2);//设置客户区中心为坐标原点

	rect.OffsetRect(-nWidth / 2, -nHeight / 2);//矩形与客户区重合
	CDC memDC;//声明内存DC
	memDC.CreateCompatibleDC(pDC);//创建一个与显示DC兼容的内存DC
	CBitmap NewBitmap, * pOldBitmap;
	NewBitmap.CreateCompatibleBitmap(pDC, nWidth, nHeight);//创建兼容内存位图
	pOldBitmap = memDC.SelectObject(&NewBitmap);//将兼容位图选入内存DC
	memDC.SetMapMode(MM_ANISOTROPIC);//在内存DC自定义坐标系
	memDC.SetWindowExt(nWidth, nHeight);
	memDC.SetViewportExt(nWidth, -nHeight);
	memDC.SetViewportOrg(nWidth / 2, nHeight / 2);
	// 创建一个 CBrush 对象，并使用背景颜色初始化它
	CBrush brush(pDC->GetBkColor());
	// 使用 CBrush 对象的指针调用 FillRect 函数
	memDC.FillRect(rect, &brush);
	DrawObject(&memDC);//绘图
	pDC->BitBlt(rect.left, rect.top, nWidth, nHeight, &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
	memDC.DeleteDC();
}
void CTestView::DrawObject(CDC* pDC)
{
	cube.Draw(pDC);
}


// CTestView 打印

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTestView 诊断

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView 消息处理程序


void CTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值。
	if (!bPlay)
	{
		switch (nChar)
		{
		case VK_UP:
			alpha = -5;
			transform.RotateX(alpha);
			break;
		case VK_DOWN:
			alpha = +5;
			transform.RotateX(alpha);
			break;
		case VK_LEFT:
			beta = -5;
			transform.RotateY(beta);
			break;
		case VK_RIGHT:
			beta = +5;
			transform.RotateY(beta);
			break;
		default:
			break;
		}
		Invalidate(FALSE);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTestView::OnUpdatePlay(CCmdUI* pCmdUI)
{
	// 更新播放按钮的UI状态
	if (bPlay)
		pCmdUI->SetCheck(TRUE);  // 显示为按下状态
	else
		pCmdUI->SetCheck(FALSE); // 显示为弹起状态
}

void CTestView::OnTimer(UINT_PTR nIDEvent)
{
	// 定时器触发时的处理
	CView::OnTimer(nIDEvent);

	alpha = 10; // 设置X轴旋转角度
	beta = 10;  // 设置Y轴旋转角度

	transform.RotateX(alpha); // 绕X轴旋转
	transform.RotateY(beta);  // 绕Y轴旋转

	Invalidate(FALSE); // 请求重绘视图（不擦除背景）

	CView::OnTimer(nIDEvent); // 调用基类处理
}
void CTestView::Onplay()
{
	// TODO: 在此添加命令处理程序代码
	// 切换播放/暂停状态
	bPlay = !bPlay;

	if (bPlay) // 如果处于播放状态，设置定时器
		SetTimer(1, 300, NULL); // 300毫秒触发一次定时器
	else       // 如果处于暂停状态，销毁定时器
		KillTimer(1);
}
