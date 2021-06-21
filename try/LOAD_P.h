#pragma once
#include"try.h"
#include"tryDoc.h"
// LOAD_P 对话框
class CtryDoc;
class LOAD_P : public CDialogEx
{
	DECLARE_DYNAMIC(LOAD_P)

public:
	LOAD_P(CtryDoc* dptr, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LOAD_P();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedOk();
private:
	CtryDoc* ptr;
	int width;
	int height;
	int deep;
	int layer;
};
