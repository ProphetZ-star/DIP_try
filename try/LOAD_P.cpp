// LOAD_P.cpp: 实现文件
//

#include "pch.h"
#include "try.h"
#include "LOAD_P.h"
#include "afxdialogex.h"


// LOAD_P 对话框

IMPLEMENT_DYNAMIC(LOAD_P, CDialogEx)

LOAD_P::LOAD_P(CtryDoc* dptr, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOAD, pParent)
	, width(512)
	, height(512)
	, deep(16)
	, layer(0)
{
	ptr = dptr;
}

LOAD_P::~LOAD_P()
{
	ptr = nullptr;
}

void LOAD_P::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, width);
	DDX_Text(pDX, IDC_EDIT2, height);
	DDX_Text(pDX, IDC_EDIT3, deep);
	DDX_Text(pDX, IDC_EDIT4, layer);
}


BEGIN_MESSAGE_MAP(LOAD_P, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &LOAD_P::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &LOAD_P::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &LOAD_P::OnEnChangeEdit4)
//	ON_EN_CHANGE(IDC_EDIT1, &LOAD_P::OnChangeEdit1)
ON_EN_CHANGE(IDC_EDIT1, &LOAD_P::OnEnChangeEdit1)
ON_BN_CLICKED(IDOK, &LOAD_P::OnBnClickedOk)
END_MESSAGE_MAP()


// LOAD_P 消息处理程序
void LOAD_P::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void LOAD_P::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void LOAD_P::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void LOAD_P::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}





void LOAD_P::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	UpdateData(TRUE);
	ptr->width = width;
	ptr->height = height;
	ptr->deepth = deep;
	ptr->layer = layer;
}
