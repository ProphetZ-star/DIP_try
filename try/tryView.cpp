
// tryView.cpp: CtryView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "try.h"
#endif

#include "tryDoc.h"
#include "tryView.h"
#include "Dib.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtryView

IMPLEMENT_DYNCREATE(CtryView, CView)

BEGIN_MESSAGE_MAP(CtryView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CtryView 构造/析构

CtryView::CtryView() noexcept
{
	// TODO: 在此处添加构造代码

}

CtryView::~CtryView()
{
}

BOOL CtryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtryView 绘图

void CtryView::OnDraw(CDC* pDC)
{
	CtryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->m_pDib != NULL) {
		pDoc->m_pDib->Draw(pDC->m_hDC, 0, 0);
	}
}


// CtryView 打印

BOOL CtryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CtryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CtryView 诊断

#ifdef _DEBUG
void CtryView::AssertValid() const
{
	CView::AssertValid();
}

void CtryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtryDoc* CtryView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtryDoc)));
	return (CtryDoc*)m_pDocument;
}
#endif //_DEBUG


// CtryView 消息处理程序
