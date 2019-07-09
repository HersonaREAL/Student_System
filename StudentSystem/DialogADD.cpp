// DialogADD.cpp: 实现文件
//

#include "pch.h"
#include "StudentSystem.h"
#include "DialogADD.h"
#include "afxdialogex.h"


// DialogADD 对话框

IMPLEMENT_DYNAMIC(DialogADD, CDialogEx)

DialogADD::DialogADD(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD, pParent)
	, ADD_id(_T(""))
	, ADD_name(_T(""))
	, ADD_math(_T(""))
	, ADD_sex(_T(""))
	, ADD_cpp(_T(""))
{
	
}

DialogADD::~DialogADD()
{
}

void DialogADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADDID, ADD_id);
	DDX_Text(pDX, IDC_EDIT_ADDNAME, ADD_name);
	DDX_Text(pDX, IDC_EDIT_ADDMATH, ADD_math);
	DDX_Text(pDX, IDC_EDIT_ADDSEX, ADD_sex);
	DDX_Text(pDX, IDC_EDIT_ADDCPP, ADD_cpp);
}


BEGIN_MESSAGE_MAP(DialogADD, CDialogEx)
	ON_BN_CLICKED(IDOK, &DialogADD::OnBnClickedOk)
END_MESSAGE_MAP()


// DialogADD 消息处理程序


void DialogADD::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (ADD_id == "" || ADD_name == "" || ADD_sex == "" || ADD_math == "" || ADD_cpp == "") {
		MessageBox("数据不足，添加失败！");
		return;
	}
	else {
		theApp.MG.Add(theApp.HD, ADD_id, ADD_name, ADD_sex, ADD_math, ADD_cpp);
	}

	CDialogEx::OnOK();
}
