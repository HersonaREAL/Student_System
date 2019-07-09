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
	void SortMath(Head HD);//��ѧ����
	void SortCPP(Head HD);//C++����
	void Add(Head HD, CString ID, CString NAME, CString SEX, CString MATH, CString CPP);//��
	void Delete(Head HD,int selection);//ɾ
	void Revise(Head H,int selection, CString ID, CString NAME, CString SEX, CString MATH, CString CPP);//��
	bool SaveData(Head HD, CString filename);//��������
	void DeleteALL(Head HD);//�������
	Head LoadData(CString filename);//��ȡ����
};
