#include<iostream>
#include<vector>
#include<algorithm>
#include"Set.h"
using namespace std;
  

#ifndef Element_H            //条件编译
#define Element_H
//定义决策表元素类----------------------------------------------
class Element
{
public:
	Element(){};
	Element(vector<int> condition, vector<int> decision, int iNo);
	//通过条件属性、决策属性集值域论域中的样本编号初始化样本
	Element(Set &condition, Set &decision, int iNo);
	//通过条件属性、决策属性集值域论域中样本的编号初始化样本
	const Element& operator=(const Element &e);//赋值构造函数
	vector<int> GetCondition()const;//获取样本的条件属性集值
	vector<int>::iterator GetConditionBegin();//返回条件属性值向量的开始位置
	vector<int>::iterator GetConditionEnd();//返回条件属性值向量的结尾的下一个位置
	vector<int> GetDecision()const;//获取样本决策属性集值
	int GetU()const;  //获取样本在论域中的编号
	void SetCondition(vector<int> &condition);//设置样本的条件属性集值
	void SetDecision(vector<int> &decision);//设置样本的决策属性集值
	void SetU(int &u);//设置样本在论域中的编号
	bool ConditionEqual(Element &other);//判断两个样本的条件属性集值是否相等
	bool DecisionEqual(Element &other);//判断两个样本的决策属性集值是否相等
	bool UEqual(Element &other);//判断两个样本在论域中的编号是否相等
	bool Equal(Element &other);//只判断条件值与决策值相等，不包括论域U
	void RemoveConditionAttribute(vector<int>::iterator it);//删除it位置的条件属性值
	void AddConditionAttribute(int &a);//添加条件属性值
	void Print();//打印样本

private:
	vector<int> ValueOfCondition;
	vector<int> ValueOfDecision;
	int u;
};

#endif

