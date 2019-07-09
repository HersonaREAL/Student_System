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
	void SortMath(Student* A);//数学排序
	void SortCPP(Student* A);//C++排序
	void Add(Student* A);//增
	void Delete(Student* A);//删
	void Revise(Student *A);//改
	void SaveData(Student *A);//保存数据
	Student ReadData();//读取数据
};