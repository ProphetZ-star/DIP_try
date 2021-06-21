
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
	ON_COMMAND(Restore, &CtryDoc::OnRestore)
//	ON_COMMAND(ID_CT32773, &CtryDoc::OnCt32773)
//ON_COMMAND(ID_32772, &CtryDoc::OnLOAD_RAW)
END_MESSAGE_MAP()


// CtryDoc 构造/析构

CtryDoc::CtryDoc() noexcept
{
	// TODO: Doc中的m_pDib变量和恢复变量m_pBuffer置空
	m_pDib = NULL;
	m_pBuffer = NULL;
	width = 0;
	height = 0;
	deepth = 0;
	layer = 0;
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
	//GetFileExt();
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	if (m_pDib != NULL) {
		delete m_pDib;
		m_pDib = NULL;
	}
	if (m_pBuffer != NULL)
	{
		delete m_pBuffer;
		m_pBuffer = NULL;
	}

	CString ext(lpszPathName);
	int n = ext.ReverseFind('.');
	ext = ext.Right(ext.GetLength() - n - 1);
	if (ext == "raw") {
		LOAD_P dlg(this);
		dlg.DoModal();
		m_pDib = new CDib;
		m_pDib->LoadRAW(lpszPathName, width, height, deepth);

	}
	else {
		m_pDib = new CDib;
		m_pDib->LoadFile(lpszPathName);
		m_pBuffer = new CDib(*m_pDib);
		UpdateAllViews(NULL);
	}
	return TRUE;
}


void CtryDoc::OnRestore()
{
	// TODO: 图像恢复
	if (m_pDib != NULL)
	{
		delete m_pDib;
		m_pDib = NULL;
	}
	if (m_pBuffer != NULL)
	{
		m_pDib = new CDib(*m_pBuffer);
	}
	UpdateAllViews(NULL);
}


//void CtryDoc::OnCt32773()
//{
//	// TODO: 在此添加命令处理程序代码
//	if (m_pDib != NULL) {
//		LOAD_P dlg(this);
//		dlg.DoModal();
//	}
//}


//void CtryDoc::OnLOAD_RAW()
//{
//	// TODO: 在此添加命令处理程序代码
//
//}
