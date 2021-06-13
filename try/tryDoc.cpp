
// tryDoc.cpp: CtryDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "try.h"
#endif

#include "tryDoc.h"
#include "Dib.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CtryDoc

IMPLEMENT_DYNCREATE(CtryDoc, CDocument)

BEGIN_MESSAGE_MAP(CtryDoc, CDocument)
END_MESSAGE_MAP()


// CtryDoc 构造/析构

CtryDoc::CtryDoc() noexcept
{
	// TODO: Doc中的m_pDib变量和恢复变量m_pBuffer置空
	m_pDib = NULL;
	m_pBuffer = NULL;
}

CtryDoc::~CtryDoc()
{
	if (m_pDib != NULL) {
		delete m_pDib;
		m_pDib = NULL;
	}
	if (m_pBuffer != NULL) {
		delete m_pBuffer;
		m_pBuffer = NULL;
	}
}

BOOL CtryDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CtryDoc 序列化

void CtryDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CtryDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CtryDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CtryDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CtryDoc 诊断

#ifdef _DEBUG
void CtryDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtryDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtryDoc 命令


BOOL CtryDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  在此添加您专用的创建代码
	if (m_pDib != NULL) {
		delete m_pDib;
		m_pDib = NULL;
	}
	if (m_pBuffer != NULL)
	{
		delete m_pBuffer;
		m_pBuffer = NULL;
	}
	m_pDib = new CDib;
	m_pDib->LoadFile(lpszPathName);
	m_pBuffer = new CDib(*m_pDib);
	UpdateAllViews(NULL);
	return TRUE;
}
