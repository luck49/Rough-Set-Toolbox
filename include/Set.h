#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#ifndef Set_H
#define Set_H
//定义适合本文的集合(Set)抽象数据类型
class Set
{
public:
	Set():vec(0){};
	Set(int A[], int n);//用于初始化集合
	Set(const Set &s);//用集合初始化集合
	Set(vector<int> v);
	const Set& operator=(const Set &s);//集合赋值运算符重载
	bool IsEmpty();
	int Card();//计算集合A的模
	void Clear();//集合清空
	int Find(int a);//在集合中查找元素a，返回位置，不存在返回-1
	int KeyAt(int i);//返回集合中i位置的key
	void SetKey(int index,int Val);//设置index位置的值为Val
	void Sort();//对集合中的元素从小到大排序
	void Remove (int a);//在集合中删去元素a得到的新的集合
	void Add(int a);//在集合中添加元素a得到的新的集合
	bool BelongTo(Set &s);//判断集合A是否属于集合B
	bool operator==(Set &s);//判断两个集合是否相等
	Set Sub(Set &s)const;//集合A减B的运算
	Set Union(Set &s) const;//集合A并B的运算
	Set InterSect(Set &s)const;//集合A交B的运算
	Set ValueOfAttribute();//求属性a值集的值域
	vector<int> ToIntVector();//把该集合转化成整型向量
	void Print();//在屏幕上打印集合A
private:
	vector<int> vec;
};

#endif





