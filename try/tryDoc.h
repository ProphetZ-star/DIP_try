
// tryDoc.h: CtryDoc 类的接口
//


#pragma once
#include "resource.h"
#include "LOAD_P.h"
class CDib;
class CtryDoc : public CDocument
{
protected: // 仅从序列化创建
	CtryDoc() noexcept;
	DECLARE_DYNCREATE(CtryDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CtryDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CDib* m_pDib;
	CDib* m_pBuffer;
	int width;
	int height;
	int deepth;
	int layer;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	afx_msg void OnRestore();
//	afx_msg void OnCt32773();
//	afx_msg void OnLOAD_RAW();
};
