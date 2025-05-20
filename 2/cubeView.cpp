
// cubeView.cpp: CcubeView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "cube.h"
#endif

#include "cubeDoc.h"
#include "cubeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcubeView

IMPLEMENT_DYNCREATE(CcubeView, CView)

BEGIN_MESSAGE_MAP(CcubeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_COMMAND(OnPlay, &CcubeView::OnOnplay)
    ON_WM_KEYDOWN()
    ON_WM_TIMER()
END_MESSAGE_MAP()

// CcubeView 构造/析构

CcubeView::CcubeView() noexcept
{
	// TODO: 在此处添加构造代码
	cube.ReadVertex();
	cube.ReadFace();
    transform.SetMatrix(cube.GetVertexArrayName(), 8); // 初始化顶点矩阵
    double nEdge = 400;
    transform.Scale(nEdge, nEdge, nEdge); // 将立方体的边长扩大400倍
    transform.Translate(-nEdge / 2, -nEdge / 2, -nEdge / 2); // 将立方体中心点平移至坐标原点
    bPlay = false;
    alpha = 0, beta = 0; // 模型绕x、y轴的初始旋转角度均为0
}

CcubeView::~CcubeView()
{
}

BOOL CcubeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CcubeView 绘图

void CcubeView::OnDraw(CDC* pDC)
{
	CcubeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DoubleBuffer(pDC);
}


// CcubeView 打印

BOOL CcubeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CcubeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CcubeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CcubeView 诊断

#ifdef _DEBUG
void CcubeView::AssertValid() const
{
	CView::AssertValid();
}

void CcubeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcubeDoc* CcubeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcubeDoc)));
	return (CcubeDoc*)m_pDocument;
}
#endif //_DEBUG


// CcubeView 消息处理程序
void CcubeView::DoubleBuffer(CDC* pDC) //双缓冲函数
{
    CRect rect;
    GetClientRect(&rect);
    nWidth = rect.Width(); nHeight = rect.Height();

    pDC->SetMapMode(MM_ANISOTROPIC); //自定义二维坐标系
    pDC->SetWindowExt(nWidth, nHeight); //设置窗口比例
    pDC->SetViewportExt(nWidth, -nHeight); //设置视区比例，且x轴水平向右为正，y轴垂直向上为正
    pDC->SetViewportOrg(nWidth / 2, nHeight / 2); //设置客户区中心为坐标系原点

    rect.OffsetRect(-rect.Width() / 2, -nHeight / 2); //矩形与客户区重合

    CDC memDC; //声明内存DC
    memDC.CreateCompatibleDC(pDC); //创建一个与显示DC兼容的内存DC
    CBitmap NewBitmap, * pOldBitmap;
    NewBitmap.CreateCompatibleBitmap(pDC, nWidth, nHeight); //创建兼容内存位图
    pOldBitmap = memDC.SelectObject(&NewBitmap); //将兼容位图选入内存DC

    memDC.SetMapMode(MM_ANISOTROPIC); //内存DC自定义坐标系
    memDC.SetWindowExt(nWidth, nHeight);
    memDC.SetViewportExt(nWidth, -nHeight);
    memDC.SetViewportOrg(nWidth / 2, nHeight / 2);

    memDC.FillSolidRect(rect, pDC->GetBkColor()); //按原来背景色填充客户区，否则是黑色
    DrawObject(&memDC); //绘图

    pDC->BitBlt(rect.left, rect.top, nWidth, nHeight, &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
    memDC.SelectObject(pOldBitmap);
    NewBitmap.DeleteObject();
    memDC.DeleteDC();
}

void CcubeView::OnOnplay()
{
    // TODO: 在此添加命令处理程序代码
    bPlay = !bPlay;

    if (bPlay) // 如果开始播放，则设置定时器
        SetTimer(1, 300, NULL);
    else // 如果停止播放，则销毁定时器
        KillTimer(1);
}


void CcubeView::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值

    CView::OnTimer(nIDEvent);

    alpha = 10, beta = 10;
    transform.RotateX(alpha); // 绕X轴旋转
    transform.RotateY(beta);  // 绕Y轴旋转

    Invalidate(FALSE); // 使窗口无效，触发重绘
    CView::OnTimer(nIDEvent); // 再次调用基类的 OnTimer 方法
}
void CcubeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch (nChar) // 根据按下的键执行不同的操作
    {
    case VK_UP:    // 上箭头键：绕 X 轴正方向旋转
        alpha += 10;
        transform.RotateX(10);
        break;

    case VK_DOWN:  // 下箭头键：绕 X 轴负方向旋转
        alpha -= 10;
        transform.RotateX(-10);
        break;

    case VK_LEFT:  // 左箭头键：绕 Y 轴负方向旋转
        beta -= 10;
        transform.RotateY(-10);
        break;

    case VK_RIGHT: // 右箭头键：绕 Y 轴正方向旋转
        beta += 10;
        transform.RotateY(10);
        break;

    default:       // 其他按键不做处理
        break;
    }

    Invalidate(FALSE); // 刷新视图以显示更新后的模型
    CView::OnKeyDown(nChar, nRepCnt, nFlags); // 调用基类方法
}
void CcubeView::DrawObject(CDC* pDC) // ZBuffer 面消隐
{
 
    CZBuffer* pZBuffer = new CZBuffer;
    pZBuffer->InitialDepthBuffer(1000, 1000, 1000);
    cube.Draw(pDC, pZBuffer);
    delete pZBuffer;
}