#include"pch.h"
#include "framework.h"
#include"Student.h"
#include"StudentSystem.h"
#include"DialogADD.h"
#include "afxdialogex.h"

void Management::SortMath(Head HD) {
	//数学排序
	List tail = HD;
	for (int k = 1; k <= HD->ListNum; k++) {
		tail = tail->Next;
		List tp = tail->Next;
		for (int j = 0; j < HD->ListNum - k; j++) {
			char temp[32];
			if (atoi(tail->Stu.Math) < atoi(tp->Stu.Math)) { //atoi函数是将char*类型转化成int类型
				strcpy_s(temp, tail->Stu.ID);
				strcpy_s(tail->Stu.ID, tp->Stu.ID);
				strcpy_s(tp->Stu.ID, temp);

				strcpy_s(temp, tail->Stu.Name);
				strcpy_s(tail->Stu.Name, tp->Stu.Name);
				strcpy_s(tp->Stu.Name, temp);

				strcpy_s(temp, tail->Stu.Sex);
				strcpy_s(tail->Stu.Sex, tp->Stu.Sex);
				strcpy_s(tp->Stu.Sex, temp);

				strcpy_s(temp, tail->Stu.Math);
				strcpy_s(tail->Stu.Math, tp->Stu.Math);
				strcpy_s(tp->Stu.Math, temp);

				strcpy_s(temp, tail->Stu.CPP);
				strcpy_s(tail->Stu.CPP, tp->Stu.CPP);
				strcpy_s(tp->Stu.CPP, temp);
			}
			tp = tp->Next;
		}
	}
}

void Management::SortCPP(Head HD) {
	//C++排序
	List tail = HD;
	for (int k = 1; k <= HD->ListNum; k++) {
		tail = tail->Next;
		List tp = tail->Next;
		for (int j = 0; j < HD->ListNum - k; j++) {
			char temp[32];
			if (atoi(tail->Stu.CPP) < atoi(tp->Stu.CPP)) { //atoi函数是将char*类型转化成int类型
				strcpy_s(temp, tail->Stu.ID);
				strcpy_s(tail->Stu.ID, tp->Stu.ID);
				strcpy_s(tp->Stu.ID, temp);

				strcpy_s(temp, tail->Stu.Name);
				strcpy_s(tail->Stu.Name, tp->Stu.Name);
				strcpy_s(tp->Stu.Name, temp);

				strcpy_s(temp, tail->Stu.Sex);
				strcpy_s(tail->Stu.Sex, tp->Stu.Sex);
				strcpy_s(tp->Stu.Sex, temp);

				strcpy_s(temp, tail->Stu.Math);
				strcpy_s(tail->Stu.Math, tp->Stu.Math);
				strcpy_s(tp->Stu.Math, temp);

				strcpy_s(temp, tail->Stu.CPP);
				strcpy_s(tail->Stu.CPP, tp->Stu.CPP);
				strcpy_s(tp->Stu.CPP, temp);
			}
			tp = tp->Next;
		}
	}
}

void Management::Add(Head HD, CString ID, CString NAME, CString SEX, CString MATH, CString CPP) {
	//添加函数
	List temp = new Node;

	//添加参数
	strcpy_s(temp->Stu.ID, ID);
	strcpy_s(temp->Stu.Name, NAME);
	strcpy_s(temp->Stu.Sex, SEX);
	strcpy_s(temp->Stu.Math, MATH);
	strcpy_s(temp->Stu.CPP, CPP);

	//添加在头节点后
	temp->Next = HD->Next;
	HD->Next = temp;
	HD->ListNum++;//节点数+1
}

void Management::Delete(Head HD,int selection) {
	//删除函数
	List pre;//要删除结点的前节点
	List temp;
	
	pre = HD;
	for (int k = 1; k < selection; k++) {//寻找前节点
		pre = pre->Next;
	}
	temp = pre->Next;
	pre->Next = temp->Next;//前节点连接到删除节点的下一个节点
	delete temp;
	HD->ListNum--;//节点数-1
}

void Management::Revise(Head HD,int selection, CString ID, CString NAME, CString SEX, CString MATH, CString CPP) {
	//修改函数

	List temp=HD;
	for (int k = 0; k < selection; k++) {//寻找节点
		temp = temp->Next;
	}
	strcpy_s(temp->Stu.ID, ID);
	strcpy_s(temp->Stu.Name, NAME);
	strcpy_s(temp->Stu.Sex, SEX);
	strcpy_s(temp->Stu.Math, MATH);
	strcpy_s(temp->Stu.CPP, CPP);

}

bool Management::SaveData(Head HD,CString filename) {
	//保存数据
	ofstream fpw;
	List tp;//临时变量
	if (filename != "") {
		fpw.open(filename);

		for (tp = HD->Next; tp != NULL; tp = tp->Next) {
			if (tp->Next != NULL)//判断是否在写最后一行，最后一行需要去掉换行
				fpw << tp->Stu.ID << " " << tp->Stu.Name << " " << tp->Stu.Sex << " " << tp->Stu.Math << " " << tp->Stu.CPP << endl;
			else
				fpw << tp->Stu.ID << " " << tp->Stu.Name << " " << tp->Stu.Sex << " " << tp->Stu.Math << " " << tp->Stu.CPP;
		}

		fpw.close();
		return true;
	}
	else {
		return false;
	}


}

Head Management::LoadData(CString filename) {
	//加载数据
	fstream fp;
	fp.open(filename);
	//统计文件行数
	int count = 0;
	while (!fp.eof())
	{
		char line[512];
		fp.getline(line, 512, '\n');
		count++;
	}
	theApp.HD->ListNum = count;//记录链表数（除链表头）

	//使文件指针返回头位置
	fp.clear();
	fp.seekg(0);

	//把文件数据读入链表
	List tp = theApp.HD;//临时变量
	for (int i = 0; i < theApp.HD->ListNum; i++) {
		//新建链表
		List temp = new Node;
		tp->Next = temp;
		temp->Next = NULL;
		tp = temp;
	}
	for (tp = theApp.HD->Next; tp != NULL; tp = tp->Next) {
		//写入
		fp >> tp->Stu.ID >> tp->Stu.Name >> tp->Stu.Sex >> tp->Stu.Math >> tp->Stu.CPP;
	}
	fp.close();
	return theApp.HD;
}

void Management::DeleteALL(Head H) {
	//删除链表中的数据
	List tempbefore,tempafter;
	tempbefore = H->Next;
	tempafter = H->Next->Next;
	for (int i = 0; i <H->ListNum; i++) {
		delete tempbefore;
		if (i != H->ListNum - 1) {//指针移动到最后一个链表，delete掉后next无指向，需要判断
			tempbefore = tempafter;
			tempafter = tempafter->Next;
		}
		else
			tempbefore = tempafter;
	}
	theApp.HD->Next = NULL;//复原全局链表头
}