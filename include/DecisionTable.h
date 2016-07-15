#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "Set.h"
#include "Element.h"
using namespace std;


#ifndef DecisionTable_H
#define DecisionTable_H



//���߱�DT=(U,Q=CUD,V,f)������--------------------------------------------------------
class DecisionTable
{
public:
	static int iNo;//���ھ��߱������������ı��
	DecisionTable();
	DecisionTable(vector<char> &ConditionSet, vector<char> &DecisionSet, vector<Set> &ConditionValueSet,vector<Set> &DecisionValueSet);//ͨ��������ֵ����߼�ֵ�������߱�
	DecisionTable(vector<char> &ConditionSet, vector<char> &DecisionSet, vector<vector<int> > &ConditionValueSet, vector<vector<int> > &DecisionValueSet);
	const DecisionTable& operator=(DecisionTable &DT);//��ֵ���캯��
	DecisionTable(const char* FileName);//���޶���ʽ�ļ�FileName�������߱�
	void SaveToFile(const char* FileName);//�Ѿ��߱��浽�ļ�FileName�У��Զ������ļ���ʽ
	void SetConditionSet(vector<char> &condition);//�����������Լ�
	void SetDecisionSet(vector<char> &decision);//���þ������Լ�
	void SetU(int index, int newU);//�Ѿ��߱�ǰλ��Ϊindex�������������ΪnewU
	vector<int> SetToiVector(Set &s);//�Ѽ���ת��Ϊ����
	vector<char> GetConditionSet();//�����������Լ�
	vector<char> GetDecisionSet();//���ؾ������Լ�
	vector <Element> GetDT();//���ؾ��߱�
	Element GetElement(int u);//���ر��Ϊu������
	int NumberOfElement();//���ؾ��߱�DT�е�������
	void AddElement(Element &e);//�ھ��߱���������e
	void AddElement(Element &e,bool flag);//��flag=trueͬAddElement(Element &e),����������������Զ���ţ�ʹ����������ı��
	int FindElement(Element &e);//�ھ��߱��в�������e,�����򷵻������ı�ţ������ڷ���-1
	void RemoveElement(int iNo);//ɾ�����߱�DT�е�������ΪiNO�ĵ�һ������
	DecisionTable RemoveConditionAttribute(const char &c);//ɾ���������Լ��е�����c�����µľ��߱�
	DecisionTable AddConditionAttribute(const char &c, vector<int> &ValueOfc);//���������Լ����������c�����µľ��߱�
	DecisionTable SelAttrMakeDT(vector<char> &vec);//�����������Լ����Ӽ����ؾ��߱�
	Set ValueSetOfAttribute(const char &a);//������������a��Ӧ��ֵ��
	Set POS();//����߱�DT=(U,Q=CUD,V,f)��D��C������
	bool IsConsistentDecisionTable();//�жϾ��߱��Ƿ���һ�¾��߱�
	double RelyDegreeOfDToC();//������߱���D��C��������
	double RelyDegreeOfDToAttribute(const char &c);//������߱���D��C�е�����c��������
	double SigOfAttribute(const char &c);//�����������Լ�������c����Ҫ�̶�
	vector<char> Core();//����߱�ĺ˼�
	vector<char> NoCore();//����߱�ķǺ˼�
	bool IsIndependentOfConditionSet();//�жϾ��߱���������Լ��Ƿ��Ƕ�����
	int CountOf(Element &e);//ͳ������e�ھ��߱��г��ֵĴ���(ֻ��ָ����ֵ����ֵ��ͬ)
	int CountOfDecisionValue(vector<int> &decValue);//��������ľ���ֵdecValue���ֵĴ���
	DecisionTable GetConsistentSubDT();//�ֽ�õ�һ�¾��߱�
	DecisionTable GetNotConsistentSubDT();//�ֽ�õ���һ�¾��߱�
	DecisionTable Unique();//���ؾ��߱�ͬ�������ɵľ��߱�
	Set GetM(); //��ȡ�����еĽ���һ��������ż�
	double LooseRelyDegreeOfDToC();//����߱�D��C����ɢ������
	double LooseRelyDegreeOfDToAttribute(const char &c);//����߱�D������c����ɢ������
	void Print();//��ӡ���߱�
	////////////////////////////////////////////////////////////////////////////////////////


private:
	vector<char> ConditionSet;
	vector<char> DecisionSet;
	vector<Element> DT;
	int SerialNumberOfElement;
};
#endif








