#include"pch.h"
#include "framework.h"
#include"Student.h"
#include"StudentSystem.h"
#include"DialogADD.h"
#include "afxdialogex.h"

void Management::SortMath(Head HD) {
	//��ѧ����
	List tail = HD;
	for (int k = 1; k <= HD->ListNum; k++) {
		tail = tail->Next;
		List tp = tail->Next;
		for (int j = 0; j < HD->ListNum - k; j++) {
			char temp[32];
			if (atoi(tail->Stu.Math) < atoi(tp->Stu.Math)) { //atoi�����ǽ�char*����ת����int����
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
	//C++����
	List tail = HD;
	for (int k = 1; k <= HD->ListNum; k++) {
		tail = tail->Next;
		List tp = tail->Next;
		for (int j = 0; j < HD->ListNum - k; j++) {
			char temp[32];
			if (atoi(tail->Stu.CPP) < atoi(tp->Stu.CPP)) { //atoi�����ǽ�char*����ת����int����
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
	//��Ӻ���
	List temp = new Node;

	//��Ӳ���
	strcpy_s(temp->Stu.ID, ID);
	strcpy_s(temp->Stu.Name, NAME);
	strcpy_s(temp->Stu.Sex, SEX);
	strcpy_s(temp->Stu.Math, MATH);
	strcpy_s(temp->Stu.CPP, CPP);

	//�����ͷ�ڵ��
	temp->Next = HD->Next;
	HD->Next = temp;
	HD->ListNum++;//�ڵ���+1
}

void Management::Delete(Head HD,int selection) {
	//ɾ������
	List pre;//Ҫɾ������ǰ�ڵ�
	List temp;
	
	pre = HD;
	for (int k = 1; k < selection; k++) {//Ѱ��ǰ�ڵ�
		pre = pre->Next;
	}
	temp = pre->Next;
	pre->Next = temp->Next;//ǰ�ڵ����ӵ�ɾ���ڵ����һ���ڵ�
	delete temp;
	HD->ListNum--;//�ڵ���-1
}

void Management::Revise(Head HD,int selection, CString ID, CString NAME, CString SEX, CString MATH, CString CPP) {
	//�޸ĺ���

	List temp=HD;
	for (int k = 0; k < selection; k++) {//Ѱ�ҽڵ�
		temp = temp->Next;
	}
	strcpy_s(temp->Stu.ID, ID);
	strcpy_s(temp->Stu.Name, NAME);
	strcpy_s(temp->Stu.Sex, SEX);
	strcpy_s(temp->Stu.Math, MATH);
	strcpy_s(temp->Stu.CPP, CPP);

}

bool Management::SaveData(Head HD,CString filename) {
	//��������
	ofstream fpw;
	List tp;//��ʱ����
	if (filename != "") {
		fpw.open(filename);

		for (tp = HD->Next; tp != NULL; tp = tp->Next) {
			if (tp->Next != NULL)//�ж��Ƿ���д���һ�У����һ����Ҫȥ������
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
	//��������
	fstream fp;
	fp.open(filename);
	//ͳ���ļ�����
	int count = 0;
	while (!fp.eof())
	{
		char line[512];
		fp.getline(line, 512, '\n');
		count++;
	}
	theApp.HD->ListNum = count;//��¼��������������ͷ��

	//ʹ�ļ�ָ�뷵��ͷλ��
	fp.clear();
	fp.seekg(0);

	//���ļ����ݶ�������
	List tp = theApp.HD;//��ʱ����
	for (int i = 0; i < theApp.HD->ListNum; i++) {
		//�½�����
		List temp = new Node;
		tp->Next = temp;
		temp->Next = NULL;
		tp = temp;
	}
	for (tp = theApp.HD->Next; tp != NULL; tp = tp->Next) {
		//д��
		fp >> tp->Stu.ID >> tp->Stu.Name >> tp->Stu.Sex >> tp->Stu.Math >> tp->Stu.CPP;
	}
	fp.close();
	return theApp.HD;
}

void Management::DeleteALL(Head H) {
	//ɾ�������е�����
	List tempbefore,tempafter;
	tempbefore = H->Next;
	tempafter = H->Next->Next;
	for (int i = 0; i <H->ListNum; i++) {
		delete tempbefore;
		if (i != H->ListNum - 1) {//ָ���ƶ������һ������delete����next��ָ����Ҫ�ж�
			tempbefore = tempafter;
			tempafter = tempafter->Next;
		}
		else
			tempbefore = tempafter;
	}
	theApp.HD->Next = NULL;//��ԭȫ������ͷ
}