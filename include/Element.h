#include<iostream>
#include<vector>
#include<algorithm>
#include"Set.h"
using namespace std;
  

#ifndef Element_H            //��������
#define Element_H
//������߱�Ԫ����----------------------------------------------
class Element
{
public:
	Element(){};
	Element(vector<int> condition, vector<int> decision, int iNo);
	//ͨ���������ԡ��������Լ�ֵ�������е�������ų�ʼ������
	Element(Set &condition, Set &decision, int iNo);
	//ͨ���������ԡ��������Լ�ֵ�������������ı�ų�ʼ������
	const Element& operator=(const Element &e);//��ֵ���캯��
	vector<int> GetCondition()const;//��ȡ�������������Լ�ֵ
	vector<int>::iterator GetConditionBegin();//������������ֵ�����Ŀ�ʼλ��
	vector<int>::iterator GetConditionEnd();//������������ֵ�����Ľ�β����һ��λ��
	vector<int> GetDecision()const;//��ȡ�����������Լ�ֵ
	int GetU()const;  //��ȡ�����������еı��
	void SetCondition(vector<int> &condition);//�����������������Լ�ֵ
	void SetDecision(vector<int> &decision);//���������ľ������Լ�ֵ
	void SetU(int &u);//���������������еı��
	bool ConditionEqual(Element &other);//�ж������������������Լ�ֵ�Ƿ����
	bool DecisionEqual(Element &other);//�ж����������ľ������Լ�ֵ�Ƿ����
	bool UEqual(Element &other);//�ж����������������еı���Ƿ����
	bool Equal(Element &other);//ֻ�ж�����ֵ�����ֵ��ȣ�����������U
	void RemoveConditionAttribute(vector<int>::iterator it);//ɾ��itλ�õ���������ֵ
	void AddConditionAttribute(int &a);//�����������ֵ
	void Print();//��ӡ����

private:
	vector<int> ValueOfCondition;
	vector<int> ValueOfDecision;
	int u;
};

#endif

