#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class Student 
{
public:
	string Name;
	string ID;
	bool Sex;
	double Math;
	double CPP;
};
class Management
{
public:
	void SortMath(Student* A);//��ѧ����
	void SortCPP(Student* A);//C++����
	void Add(Student* A);//��
	void Delete(Student* A);//ɾ
	void Revise(Student *A);//��
	void SaveData(Student *A);//��������
	Student ReadData();//��ȡ����
};