
// StudentSystemDlg.h: 头文件
//

#pragma once


// CStudentSystemDlg 对话框
class CStudentSystemDlg : public CDialogEx
{
// 构造
public:
	CStudentSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnLvnItemchangedInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedLoaddata();
	afx_msg void OnBnClickedSavedata();
	afx_msg void refresh();
	afx_msg void OnEnChangeEditId();
	afx_msg void OnNMClickInfo(NMHDR* pNMHDR, LRESULT* pResult);

	CString EDIT_id;
	CString EDIT_name;
	CString EDIT_math;
	CString EDIT_cpp;
	CString EDIT_sex;
	afx_msg void OnBnClickedRevise();
	afx_msg void OnBnClickedSortmath();
	afx_msg void OnBnClickedSortcpp();
	afx_msg void OnBnClickedDeleteall();
	afx_msg void OnBnClickedAnalyse();
};
