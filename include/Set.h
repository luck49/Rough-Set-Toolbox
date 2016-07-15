#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#ifndef Set_H
#define Set_H
//�����ʺϱ��ĵļ���(Set)������������
class Set
{
public:
	Set():vec(0){};
	Set(int A[], int n);//���ڳ�ʼ������
	Set(const Set &s);//�ü��ϳ�ʼ������
	Set(vector<int> v);
	const Set& operator=(const Set &s);//���ϸ�ֵ���������
	bool IsEmpty();
	int Card();//���㼯��A��ģ
	void Clear();//�������
	int Find(int a);//�ڼ����в���Ԫ��a������λ�ã������ڷ���-1
	int KeyAt(int i);//���ؼ�����iλ�õ�key
	void SetKey(int index,int Val);//����indexλ�õ�ֵΪVal
	void Sort();//�Լ����е�Ԫ�ش�С��������
	void Remove (int a);//�ڼ�����ɾȥԪ��a�õ����µļ���
	void Add(int a);//�ڼ��������Ԫ��a�õ����µļ���
	bool BelongTo(Set &s);//�жϼ���A�Ƿ����ڼ���B
	bool operator==(Set &s);//�ж����������Ƿ����
	Set Sub(Set &s)const;//����A��B������
	Set Union(Set &s) const;//����A��B������
	Set InterSect(Set &s)const;//����A��B������
	Set ValueOfAttribute();//������aֵ����ֵ��
	vector<int> ToIntVector();//�Ѹü���ת������������
	void Print();//����Ļ�ϴ�ӡ����A
private:
	vector<int> vec;
};

#endif





