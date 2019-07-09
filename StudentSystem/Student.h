#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct Student 
{
	char Name[32];
	char ID[10];
	char Sex[6];
	char Math[5];
	char CPP[5];
};

typedef struct Node* List;
typedef struct Node* Head;
struct Node
{
	int ListNum=0;
	Student Stu;
	List Next=NULL;
};

class Management
{
public:
	void SortMath(Head HD);//数学排序
	void SortCPP(Head HD);//C++排序
	void Add(Head HD, CString ID, CString NAME, CString SEX, CString MATH, CString CPP);//增
	void Delete(Head HD,int selection);//删
	void Revise(Head H,int selection, CString ID, CString NAME, CString SEX, CString MATH, CString CPP);//改
	bool SaveData(Head HD, CString filename);//保存数据
	void DeleteALL(Head HD);//清空数据
	Head LoadData(CString filename);//读取数据
};
