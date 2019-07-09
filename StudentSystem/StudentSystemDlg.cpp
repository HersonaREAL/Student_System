
// StudentSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "StudentSystem.h"
#include "StudentSystemDlg.h"
#include "afxdialogex.h"
#include "DialogADD.h"
#include "Student.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentSystemDlg 对话框



CStudentSystemDlg::CStudentSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENTSYSTEM_DIALOG, pParent)
	

	, EDIT_id(_T(""))
	, EDIT_name(_T(""))
	, EDIT_math(_T(""))
	, EDIT_cpp(_T(""))
	, EDIT_sex(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CStudentSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT_ID, EDIT_id);
	DDX_Text(pDX, IDC_EDIT_Name, EDIT_name);
	DDX_Text(pDX, IDC_EDIT_Math, EDIT_math);
	DDX_Text(pDX, IDC_EDIT_CPP, EDIT_cpp);
	DDX_Text(pDX, IDC_EDIT_Sex, EDIT_sex);
}

BEGIN_MESSAGE_MAP(CStudentSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_Info, &CStudentSystemDlg::OnLvnItemchangedInfo)
	ON_BN_CLICKED(IDC_ADD, &CStudentSystemDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Delete, &CStudentSystemDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_LoadData, &CStudentSystemDlg::OnBnClickedLoaddata)
	ON_BN_CLICKED(IDC_SaveData, &CStudentSystemDlg::OnBnClickedSavedata)
	ON_EN_CHANGE(IDC_EDIT_ID, &CStudentSystemDlg::OnEnChangeEditId)
	ON_NOTIFY(NM_CLICK, IDC_Info, &CStudentSystemDlg::OnNMClickInfo)
	ON_BN_CLICKED(IDC_Revise, &CStudentSystemDlg::OnBnClickedRevise)
	ON_BN_CLICKED(IDC_SortMath, &CStudentSystemDlg::OnBnClickedSortmath)
	ON_BN_CLICKED(IDC_SortCPP, &CStudentSystemDlg::OnBnClickedSortcpp)
	ON_BN_CLICKED(IDC_DeleteAll, &CStudentSystemDlg::OnBnClickedDeleteall)
	ON_BN_CLICKED(IDC_Analyse, &CStudentSystemDlg::OnBnClickedAnalyse)
END_MESSAGE_MAP()


// CStudentSystemDlg 消息处理程序

BOOL CStudentSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// 将“关于...”菜单项添加到系统菜单中。
	SetWindowText(_T("学生管理系统--蒋耀聪 网络184 1806200016"));
	// IDM_ABOUTBOX 必须在系统命令范围内。
	
	//初始化listcrtl
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_Info);
	pList->InsertColumn(0, _T("C++"), LVCFMT_CENTER, 88);
	pList->InsertColumn(0, _T("高等数学"), LVCFMT_CENTER, 88);
	pList->InsertColumn(0, _T("性别"), LVCFMT_CENTER, 50);
	pList->InsertColumn(0, _T("姓名"), LVCFMT_CENTER, 88);
	pList->InsertColumn(0, _T("学号"), LVCFMT_CENTER, 80);
	DWORD dwStyle = pList->GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES| LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;//网格线 选中高亮
	pList->SetExtendedStyle(dwStyle); //设置扩展风格
	pList->SetFocus();
	//👆设置表格头


	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStudentSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStudentSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStudentSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentSystemDlg::OnLvnItemchangedInfo(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CStudentSystemDlg::OnBnClickedAdd()//添加按钮
{
	// TODO: 在此添加控件通知处理程序代码
	DialogADD Dl;
	Dl.DoModal();//弹出添加对话框
	CStudentSystemDlg::refresh();
}


void CStudentSystemDlg::OnBnClickedDelete()//删除按钮
{
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_Info);
	int selection = pList->GetSelectionMark()+1;
	if (selection == 0) {
		//判断有无选中行
		MessageBox("未选中数据，删除失败！");
		return;
	}
	else {
		theApp.MG.Delete(theApp.HD, selection);
		CStudentSystemDlg::refresh();
	}
	
}


void CStudentSystemDlg::OnBnClickedLoaddata()//加载数据按钮
{
	// TODO: 在此添加控件通知处理程序代码

	//打开文件
	CString filename;//打开路径
	CFileDialog opendlg(TRUE, _T("*"), _T("*.txt"), OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"), NULL);
	if (opendlg.DoModal() == IDOK)
	{
		filename = opendlg.GetPathName();
	}

	if (filename == "")
		return;

	//如果有数据，清空数据
	if (theApp.HD->Next != NULL)
		theApp.MG.DeleteALL(theApp.HD);

	theApp.HD = theApp.MG.LoadData(filename);
	CStudentSystemDlg::refresh();
}


void CStudentSystemDlg::OnBnClickedSavedata()//保存数据按钮
{
	// TODO: 在此添加控件通知处理程序代码

	//保存文件的位置
	CString filename;//保存路径
	CFileDialog opendlg(FALSE, _T("*"), _T("*.txt"), OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"), NULL);
	if (opendlg.DoModal() == IDOK)
	{
		filename = opendlg.GetPathName();
	}

	if (theApp.HD->Next == NULL) {
		MessageBox("无数据记录，保存失败！");
			return;
	}
	else {
		int jud=theApp.MG.SaveData(theApp.HD,filename);
		if(jud)
			MessageBox("保存成功！");
	}
		
}

void CStudentSystemDlg::refresh() //刷新界面函数
{
	//刷新ListCtrl界面
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_Info);
	pList->DeleteAllItems();

	int i = 0;
	for (List tp = theApp.HD->Next; tp != NULL; tp = tp->Next) {
		pList->InsertItem(i, tp->Stu.ID);
		pList->SetItemText(i, 1, tp->Stu.Name);
		pList->SetItemText(i, 2, tp->Stu.Sex);
		pList->SetItemText(i, 3, tp->Stu.Math);
		pList->SetItemText(i, 4, tp->Stu.CPP);
		i++;
	}
}

void CStudentSystemDlg::OnEnChangeEditId()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CStudentSystemDlg::OnNMClickInfo(NMHDR* pNMHDR, LRESULT* pResult)//选中行显示到编辑框
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//点击某行显示在编辑框
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_Info);
	char p[32];
	int i = pList->GetSelectionMark();//获取当前行数，行数从0开始哦

	pList->GetItemText(i, 0,p, 10);
	EDIT_id.Format("%s", p);//char*转换Cstring
	pList->GetItemText(i, 1, p, 10);
	EDIT_name.Format("%s", p);
	pList->GetItemText(i, 2, p, 10);
	EDIT_sex.Format("%s", p);
	pList->GetItemText(i, 3, p, 10);
	EDIT_math.Format("%s", p);
	pList->GetItemText(i, 4, p, 10);
	EDIT_cpp.Format("%s", p);
	

	UpdateData(false);//刷新数据

	*pResult = 0;
}


void CStudentSystemDlg::OnBnClickedRevise()
{
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_Info);
	int selection = pList->GetSelectionMark() + 1;//获取点击行数

	UpdateData(true);
	if (EDIT_id == "" || EDIT_name == "" || EDIT_sex == "" || EDIT_math == "" || EDIT_cpp == "") {
		MessageBox("数据不足，修改失败！");
		return;
	}else if (selection == 0) {
		MessageBox("请选中后再修改！");
	}
	else {
		theApp.MG.Revise(theApp.HD, selection, EDIT_id, EDIT_name, EDIT_sex, EDIT_math, EDIT_cpp);
		MessageBox("修改成功！");
		CStudentSystemDlg::refresh();
	}
}


void CStudentSystemDlg::OnBnClickedSortmath()//高数排序
{
	// TODO: 在此添加控件通知处理程序代码
	if (theApp.HD->Next == NULL) {
		MessageBox("无数据，排序失败！");
		return;
	}
	else {
		theApp.MG.SortMath(theApp.HD);
		CStudentSystemDlg::refresh();
	}
}


void CStudentSystemDlg::OnBnClickedSortcpp()//C++排序
{
	// TODO: 在此添加控件通知处理程序代码
	if (theApp.HD->Next == NULL) {
		MessageBox("无数据，排序失败！");
		return;
	}
	else {
		theApp.MG.SortCPP(theApp.HD);
		CStudentSystemDlg::refresh();
	}
}


void CStudentSystemDlg::OnBnClickedDeleteall()//清空数据
{
	// TODO: 在此添加控件通知处理程序代码
	if (theApp.HD->Next == NULL) {
		MessageBox("无数据，清空失败！");
		return;
	}
	else {
		theApp.MG.DeleteALL(theApp.HD);
		CStudentSystemDlg::refresh();
	}
}


void CStudentSystemDlg::OnBnClickedAnalyse()
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;//打开路径
	CFileDialog opendlg(TRUE, _T("*"), _T("*.exe"), OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"), NULL);
	if (opendlg.DoModal() == IDOK)
	{
		filename = opendlg.GetPathName();
	}

	if (filename == "")
		return;
	WinExec(filename, SW_SHOW);
}
