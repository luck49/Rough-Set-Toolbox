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



//决策表DT=(U,Q=CUD,V,f)类声明--------------------------------------------------------
class DecisionTable
{
public:
	static int iNo;//用于决策表论域中样本的编号
	DecisionTable();
	DecisionTable(vector<char> &ConditionSet, vector<char> &DecisionSet, vector<Set> &ConditionValueSet,vector<Set> &DecisionValueSet);//通过条件集值与决策集值创建决策表
	DecisionTable(vector<char> &ConditionSet, vector<char> &DecisionSet, vector<vector<int> > &ConditionValueSet, vector<vector<int> > &DecisionValueSet);
	const DecisionTable& operator=(DecisionTable &DT);//赋值构造函数
	DecisionTable(const char* FileName);//由限定格式文件FileName创建决策表
	void SaveToFile(const char* FileName);//把决策表保存到文件FileName中，自动生成文件格式
	void SetConditionSet(vector<char> &condition);//设置条件属性集
	void SetDecisionSet(vector<char> &decision);//设置决策属性集
	void SetU(int index, int newU);//把决策表当前位置为index的样本编号设置为newU
	vector<int> SetToiVector(Set &s);//把集合转化为向量
	vector<char> GetConditionSet();//返回条件属性集
	vector<char> GetDecisionSet();//返回决策属性集
	vector <Element> GetDT();//返回决策表
	Element GetElement(int u);//返回编号为u的样本
	int NumberOfElement();//返回决策表DT中的样本数
	void AddElement(Element &e);//在决策表后添加样本e
	void AddElement(Element &e,bool flag);//当flag=true同AddElement(Element &e),否则添加样本，不自动编号，使用样本本身的编号
	int FindElement(Element &e);//在决策表中查找样本e,存在则返回样本的编号，不存在返回-1
	void RemoveElement(int iNo);//删除决策表DT中的样本号为iNO的第一个样本
	DecisionTable RemoveConditionAttribute(const char &c);//删除条件属性集中的属性c构成新的决策表
	DecisionTable AddConditionAttribute(const char &c, vector<int> &ValueOfc);//网条件属性集中添加属性c构成新的决策表
	DecisionTable SelAttrMakeDT(vector<char> &vec);//按给定的属性集的子集返回决策表
	Set ValueSetOfAttribute(const char &a);//返回条件属性a对应的值集
	Set POS();//求决策表DT=(U,Q=CUD,V,f)的D的C正区域
	bool IsConsistentDecisionTable();//判断决策表是否是一致决策表
	double RelyDegreeOfDToC();//计算决策表中D对C的依赖度
	double RelyDegreeOfDToAttribute(const char &c);//计算决策表中D对C中的属性c的依赖度
	double SigOfAttribute(const char &c);//计算条件属性集中属性c的重要程度
	vector<char> Core();//求决策表的核集
	vector<char> NoCore();//求决策表的非核集
	bool IsIndependentOfConditionSet();//判断决策表的条件属性集是否是独立的
	int CountOf(Element &e);//统计样本e在决策表中出现的次数(只是指条件值决策值相同)
	int CountOfDecisionValue(vector<int> &decValue);//计算给定的决策值decValue出现的次数
	DecisionTable GetConsistentSubDT();//分解得到一致决策表
	DecisionTable GetNotConsistentSubDT();//分解得到不一致决策表
	DecisionTable Unique();//返回决策表不同样本构成的决策表
	Set GetM(); //获取论域中的近似一致样本编号集
	double LooseRelyDegreeOfDToC();//求决策表D对C的松散依赖度
	double LooseRelyDegreeOfDToAttribute(const char &c);//求决策表D对属性c的松散依赖度
	void Print();//打印决策表
	////////////////////////////////////////////////////////////////////////////////////////


private:
	vector<char> ConditionSet;
	vector<char> DecisionSet;
	vector<Element> DT;
	int SerialNumberOfElement;
};
#endif








