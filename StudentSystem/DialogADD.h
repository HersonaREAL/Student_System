#pragma once


// DialogADD 对话框

class DialogADD : public CDialogEx
{
	DECLARE_DYNAMIC(DialogADD)

public:
	DialogADD(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DialogADD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ADD_id;
	CString ADD_name;
	CString ADD_math;
	CString ADD_sex;
	afx_msg void OnBnClickedOk();
	CString ADD_cpp;
};
