

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DecisionTable.h"
// Decision Table DT=(U,Q=CUD,V,f)  --------------------------------------------
int DecisionTable::iNo=0;
DecisionTable::DecisionTable()//Ĭ�Ϲ��캯�� Serial Number  ���
{
	this->SerialNumberOfElement=0;
}

////////////////////////���������Լ����������Լ�����������ֵ������������ֵ����ʼ�����߱�/////////////////////

DecisionTable::DecisionTable(std::vector<char> &ConditionSet,std::vector<char> &DecisionSet,std::vector<Set> &ConditionValueSet,std::vector<Set> &DecisionValueSet)
{
	this->SerialNumberOfElement=0;
	this->ConditionSet=ConditionSet;
	this->DecisionSet=DecisionSet;
	if(ConditionValueSet.size()!=DecisionValueSet.size())
	{
		cout<<"����ֵ�������������ֵ����������ͬ!"<<endl;
	}
	else
	{
		vector<Set>::iterator it1=ConditionValueSet.begin();
		vector<Set>::iterator it2=DecisionValueSet.begin();
		Element temp;
		for(;it1<ConditionValueSet.end()&&it2<DecisionValueSet.end();it1++,it2++)
		{
			temp.SetCondition((*it1).ToIntVector());
			temp.SetDecision((*it2).ToIntVector());
			SerialNumberOfElement++;
			temp.SetU(SerialNumberOfElement);
			DT.push_back(temp);
		}
	}
	iNo++;
}
/////////////////////���������Լ����������Լ�����������ֵ������������ֵ����ʼ�����߱�///////////////////////////////

DecisionTable::DecisionTable(std::vector<char> &ConditionSet,std::vector<char> &DecisionSet,std::vector<vector<int> > &ConditionValueSet,std::vector<vector<int> > &DecisionValueSet)
{
	this->SerialNumberOfElement=0;
	this->ConditionSet=ConditionSet;
	this->DecisionSet=DecisionSet;
	if(ConditionValueSet.size()!=DecisionValueSet.size())
	{
		cout<<"����ֵ�������������ֵ����������ͬ!"<<endl;
	}
	else
	{
		vector<vector<int> >::iterator it1=ConditionValueSet.begin();
		vector<vector<int> >::iterator it2=DecisionValueSet.begin();
		Element temp;
		for(;it1 < ConditionValueSet.end() && it2 < DecisionValueSet.end(); it1++, it2++)
		{
			temp.SetCondition(*it1);
			temp.SetDecision(*it2);
			SerialNumberOfElement++;
			temp.SetU(SerialNumberOfElement);
			DT.push_back(temp);
		}
	}
	iNo++;
}


const DecisionTable& DecisionTable::operator=(DecisionTable &DT)
{
	if(this!=&DT)
	{
		this->ConditionSet=DT.GetConditionSet();
		this->DecisionSet=DT.GetDecisionSet();
		this->DT=DT.GetDT();
	}
	return *this;
}

DecisionTable::DecisionTable(const char *FileName)
{
	this->SerialNumberOfElement=0;
	string str;
	ifstream in(FileName);
	if(!in)
	{
		cerr<<"���ܴ�"<<FileName<<endl;
		exit(-1);
	}
	while(getline(in,str))
	{
		istringstream line(str);
		line>>str;
		if(str=="@ConditionAttribute")
		{
			char ch;
			line>>ch;
			ConditionSet.push_back(ch);
		}
		if(str=="@DecisionAttribute")
		{
			char ch;
			line>>ch;
			DecisionSet.push_back(ch);
		}
		if(str=="@data")
		{
			while(getline(in,str))
			{
				if(str!="@end")
				{
					int x;
					istringstream dataline(str);
					Element e;
					vector<int> C;
					vector<int> D;
					for(unsigned int i=0;i<ConditionSet.size();i++)
					{
						dataline>>x;
						C.push_back(x);
					}
					for(unsigned int j=0;j<DecisionSet.size();j++)
					{
						dataline>>x;
						D.push_back(x);
					}
					e.SetCondition(C);
					e.SetDecision(D);
					AddElement(e);
				}
				else
				{
					break;
				}
			}
		}
	}
	in.close();
}


void DecisionTable::SaveToFile(const char *FileName)
{
	ofstream out(FileName);
	if(!out)
	{
		cerr<<"���ܴ�"<<FileName<<endl;
		exit(-1);
	}
	//���ļ�FileName��д����߱�Ļ�����Ϣ------------------------
	vector<char>::iterator it;
	for(it=ConditionSet.begin();it<ConditionSet.end();it++)
	{
		out<<"@ConditionAttribute"<<*it<<endl;
	}
	for(it=ConditionSet.begin();it<ConditionSet.end();it++)
	{
		out<<"@ConditionAttribute"<<*it<<endl;
	}
	for(it=DecisionSet.begin();it<DecisionSet.end();it++)
	{
		out<<"@DecisionAttribute"<<*it<<endl;
	}
	out<<endl<<"@data"<<endl;
	//���ļ�FileName��д����߱��е�����--------------------------------------
	vector<int> con;
	vector<int> dec;
	int u;
	Element e;
	vector<Element>::iterator it1=DT.begin();
	vector<int> ::iterator it2,it3;
	for(;it1<DT.end();it1++)
	{
		e=*it1;
		con=e.GetCondition();
		dec=e.GetDecision();
		u=e.GetU();
		for(it2=con.begin();it2<con.end();it2++)
		{
			out<<*it2<<'\t';
		}
		for(it3=dec.begin();it3<dec.end();it3++)
		{
			out<<*it3<<'\t';//'\t'Ϊˮƽ�Ʊ�
		}
		out<<u<<endl;
	}
	out<<"@end";
	out.close();
}


void DecisionTable::SetConditionSet(std::vector<char> &condition)
{
	this->ConditionSet=condition;
}


void DecisionTable::SetDecisionSet(std::vector<char> &decision)
{
	this->DecisionSet=decision;
}

void DecisionTable::SetU(int index,int newU)
{
	DT[index].SetU(newU);
}


vector<int> DecisionTable::SetToiVector(Set &s)
{
	vector<int> temp;
	for(int i=0;i<s.Card();i++)
	{
		temp.push_back(s.KeyAt(i));
	}
	return temp;
}


int DecisionTable::NumberOfElement()
{
	int Number=0;
	vector<Element>::iterator it=DT.begin();
	for(;it!=DT.end();it++)
	{
		Number++;
	}
		return Number;
}


void DecisionTable::AddElement(Element &e)
{
	SerialNumberOfElement++;
	if(iNo<INT_MAX)
	{
		e.SetU(SerialNumberOfElement);
		DT.push_back(e);
	}
	else
	{
		cout<<"���ñ������!\n�Ƿ�����ɾ���������������±��?Y(y)/N(n)"<<endl;
	}
}


void DecisionTable::AddElement(Element &e,bool flag)
{
	if(flag)
	{
		AddElement(e);
	}
	else
	{
		DT.push_back(e);
	}
}


void DecisionTable::Print()
{
	if(!DT.empty()&&!ConditionSet.empty()&&!DecisionSet.empty())
	{
		////////////////////////////////////��ӡ���߱�DT�ı�ͷ//////////////////////////////
		vector<char>::iterator it1=ConditionSet.begin();
		cout<<"(";
		cout<<*it1++;
		for(;it1<ConditionSet.end();it1++)
		{
			cout<<",\t"<<*it1;
		}
		cout<<")\t->\t(";
		vector<char>::iterator it2=DecisionSet.begin();
		cout<<*it2++;
		for(;it2<DecisionSet.end();it2++)
		{
			cout<<",\t"<<*it2;
		}
		cout<<")\tU"<<endl;
		////////////////////////////////////////��ӡ���߱�DT�����е�����//////////////////////
		vector<Element>::iterator iter=DT.begin();
		for(;iter<DT.end();iter++)
		{
			(*iter).Print();
		}
	}
	else
	{
		cout<<"���߱���û���������������Լ�Ϊ�ռ���������Լ�Ϊ�ռ�!"<<endl;
	}
}


Set DecisionTable::POS()
{
	bool flag;
	Set pos;
	vector<Element>::iterator it1;
	vector<Element>::iterator it2;

	for(it1=DT.begin();it1<DT.end();it1++)
	{
		flag=true;
		for(it2=DT.begin();it2<DT.end();it2++)
		{
			if((*it1).ConditionEqual(*it2)&&!((*it1).DecisionEqual(*it2)))
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			pos.Add((*it1).GetU());
		}
	}
	return pos;
}




vector<char> DecisionTable::GetConditionSet()
{
	return ConditionSet;
}



vector<char> DecisionTable::GetDecisionSet()
{
	return DecisionSet;
}





vector<Element>DecisionTable::GetDT()
{
	return DT;
}


Element DecisionTable::GetElement(int u)
{
	Element e;
	vector<Element>::iterator it=DT.begin();
	for(;it<DT.end();it++)
	{
		if(u==(*it).GetU())
		{
			e=(*it);
			return e;
		}
	}
	cout<<"�������������ڵľ��߱���!���ص�����û������!"<<endl;
	return e;
}


int DecisionTable::FindElement(Element &e)
{
	vector<Element>::iterator it=DT.begin();
	for(;it!=DT.end();it++)
	{
		if((*it).Equal(e))
		{
			return(*it).GetU();
		}
	}
	return -1;
}


void DecisionTable::RemoveElement(int iNo)
{
	bool flag=false;
	if(iNo>=1&&iNo<=this->SerialNumberOfElement)
	{
		vector<Element>::iterator it=DT.begin();
		for(;it<DT.end();it++)
		{
			if((*it).GetU()==iNo)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			DT.erase(it);
		}
	}
	else
	{
		cout<<"���������ռ䷶Χ:"<<"0-"<<this->SerialNumberOfElement<<endl;
	}
}

bool DecisionTable::IsConsistentDecisionTable()
{
	Set pos;
	pos=this->POS();
	if(pos.Card()==this->NumberOfElement())
	{
		return true;
	}
	else
	{
		return false;
	}
}

double DecisionTable::RelyDegreeOfDToC()
{
	double r=0.0;
	Set pos;
	pos=this->POS();
	r=(double)pos.Card()/this->NumberOfElement();
	return r;
}

DecisionTable DecisionTable::RemoveConditionAttribute(const char &c)
{
	//DecisionTable temp;
	int index=0;


	vector<char>::iterator it=ConditionSet.begin();
	for(;it<ConditionSet.end();it++,index++)
	{
		if(*it==c)
			break;
	}

	if(it!=ConditionSet.end())
	{
		ConditionSet.erase(it);
		vector<Element>::iterator it1=DT.begin();
		vector<int>::iterator it2;
		for(;it1<DT.end();it1++)
		{
			it2=(*it1).GetConditionBegin()+index;
			(*it1).RemoveConditionAttribute(it2);
		}
	}
	return *this;
}

DecisionTable DecisionTable::SelAttrMakeDT(vector<char> &vec)
{
	bool flag;
	DecisionTable temp=*this;
	vector<char>::iterator it1;
	vector<char>::iterator it2=ConditionSet.begin();
	for(;it2<ConditionSet.end();it2++)
	{
		flag=false;
		for(it1=vec.begin();it1<vec.end();it1++)
		{
			if(*it2==*it1)
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			temp.RemoveConditionAttribute(*it2);
		}
	}
	return temp;
}

Set DecisionTable::ValueSetOfAttribute(const char &a)
{
	Set result;
	bool flag=false;
	int index=0;
	vector<char>::iterator it=ConditionSet.begin();
	for(;it<ConditionSet.end();it++,index++)
	{
		if(*it==a)
		{
			flag=true;
			break;
		}
	}
	if(flag)
	{
		for(vector<Element>::iterator it1=DT.begin();it1<DT.end();it1++)
		{
			vector<int> condition=(*it1).GetCondition();
			result.Add(condition[index]);
		}
	}
	else
	{
		cout<<"����"<<a<<"���������Լ����Ҳ���!"<<endl;
	}
	
	return result;
}


DecisionTable DecisionTable::AddConditionAttribute(const char &c,vector<int> &ValueOfc)
{
	int index=0;
	vector<char>::iterator it=ConditionSet.begin();
	for(;it<ConditionSet.end();it++,index++)
	{
		if(*it==c)
		{
			cout<<"�������Ѿ����ڣ������������Ƴ�ͻ!"<<endl;
			return *this;
		}
	}
	if(ValueOfc.size()!=DT.size())
	{
		cout<<"��ӵ�����ֵ�����ߴ粻��!����Ƿ���ھ��߱��е�������!"<<endl;
		return *this;
	}


	ConditionSet.push_back(c);
	vector<Element>::iterator it1=DT.begin();
	vector<int>::iterator it2=ValueOfc.begin();
	for(;it1<DT.end()&&it2<ValueOfc.end();it1++,it2++)
	{
		(*it1).AddConditionAttribute(*it2);
	}

	return *this;
}




double DecisionTable::RelyDegreeOfDToAttribute(const char &c)   //����D������c��������
{
	DecisionTable DT;  //����һ�����߱����
	double r=0.0;

	DT=*this;
	vector<char> vec;
	vector<char>::iterator it=ConditionSet.begin();
	while(it<ConditionSet.end())
	{
		if(c!=*it)
		{
			vec.push_back(*it);
		}
		it++;
	}
	it=vec.begin();
	while(it<vec.end())
	{
		DT.RemoveConditionAttribute(*it);
		it++;
	}
	Set pos;
	pos=DT.POS();
	r=(double)pos.Card()/this->NumberOfElement();
	return r;
}


double DecisionTable::SigOfAttribute(const char &c)
{
	double sig=0.0;
	double x,y;
	DecisionTable dt;
	dt=*this;
	dt.RemoveConditionAttribute(c);
	//����D��C��������
	Set pos1;
	pos1=this->POS();
	x=(double)pos1.Card()/this->NumberOfElement();

	//����D��C-{c}��������
	Set pos2;
	pos2=dt.POS();
	y=(double)pos2.Card()/dt.NumberOfElement();
	//��������c����Ҫ�̶�
	sig=x-y;
	return sig;
}


vector<char> DecisionTable::Core()
{
	vector<char> vec;
	vector<char>::iterator it=this->ConditionSet.begin();
	for(;it<this->ConditionSet.end();it++)
	{
		if(this->SigOfAttribute(*it)!=0)
		{
			vec.push_back(*it);
		}
	}
	return vec;
}



vector<char> DecisionTable::NoCore()
{
	vector<char>vec;
	vector<char>::iterator it=this->ConditionSet.begin();
	for(;it<this->ConditionSet.end();it++)
	{
		if(this->SigOfAttribute(*it)==0)
		{
			vec.push_back(*it);
		}
	}
	return vec;
}




bool DecisionTable::IsIndependentOfConditionSet()
{
	bool flag=true;
	vector<char>::iterator it=this->ConditionSet.begin();
	for(;it<this->ConditionSet.end();it++)
	{
		if(this->SigOfAttribute(*it)==0)
		{
			flag=false;
			break;
		}
	}
	return flag;
}

int DecisionTable::CountOf(Element &e)
{
	vector<Element>::iterator it=DT.begin();
	int iCount=0;
	for(;it<DT.end();it++)
	{
		if(e.Equal(*it))
		{
			iCount++;
		}
	}
	return iCount;
}


int DecisionTable::CountOfDecisionValue(vector<int> &decValue)
{
	vector<Element>::iterator it=DT.begin();
	Element e;
	e.SetDecision(decValue);
	int iCount=0;
	for(;it<DT.end();it++)
	{
		if((*it).DecisionEqual(e))
		{
			iCount++;
		}
	}
	return iCount;
}


DecisionTable DecisionTable::GetConsistentSubDT()
{
	DecisionTable consistentDT;
	bool flag;
	int i=0;
	vector<Element>::iterator it1;
	vector<Element>::iterator it2;
	consistentDT.SetConditionSet(ConditionSet);
	consistentDT.SetDecisionSet(DecisionSet);

	for(it1=DT.begin();it1<DT.end();it1++)
	{
		flag=true;
		for(it2=DT.begin();it2<DT.end();it2++)
		{
			if((*it1).ConditionEqual(*it2)&&!((*it1).DecisionEqual(*it2)))
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			Element e=*it1;
			consistentDT.AddElement(e);
			consistentDT.SetU(i,(*it1).GetU());
			i++;
		}
	}
	return consistentDT;
}




DecisionTable DecisionTable::GetNotConsistentSubDT()
{
	DecisionTable notConsistentDT;
	bool flag;
	int i=0;
	vector<Element>::iterator it1;
	vector<Element>::iterator it2;
	notConsistentDT.SetConditionSet(ConditionSet);
	notConsistentDT.SetDecisionSet(DecisionSet);
	for(it1=DT.begin();it1<DT.end();it1++)
	{
		flag=true;
		for(it2=DT.begin();it2<DT.end();it2++)
		{
			if((*it1).ConditionEqual(*it2)&&!((*it1).DecisionEqual(*it2)))
			{
				flag=false;
				break;
			}
		}
		if(!flag)
		{
			Element e=*it1;
			notConsistentDT.AddElement(e);
			notConsistentDT.SetU(i,(*it1).GetU());
			i++;
		}
	}
	return notConsistentDT;
}

DecisionTable DecisionTable::Unique()
{
	DecisionTable temp;
	Element e;
	vector<char>::iterator it=ConditionSet.begin();
	vector<int> vec;
	for(;it<ConditionSet.end();it++)
	{
		vec.push_back(INT_MAX);
	}
	e.SetCondition(vec);
	vec.clear();
	for(it=DecisionSet.begin();it<DecisionSet.end();it++)
	{
		vec.push_back(INT_MAX);
	}
	e.SetDecision(vec);
	int max=INT_MAX;
	e.SetU(max);
	vector<Element>::iterator it1,it2;
	vector<Element> dt=DT;
	for(it1=dt.begin();it1<dt.end();it1++)
	{
		if(!e.Equal(*it1))
		{
			temp.AddElement(*it1,false);
			for(it2=it1+1;it2<dt.end();it2++)
			{
				if((*it1).Equal(*it2))
				{
					(*it2)=e;
				}
			}
		}
	}
	temp.SetConditionSet(ConditionSet);
	temp.SetDecisionSet(DecisionSet);
	return temp;
}


Set DecisionTable::GetM()
{
	Set m;
	DecisionTable temp=this->GetNotConsistentSubDT();
	DecisionTable dt=temp.Unique();
	vector<Element> eVec=dt.GetDT();
	vector<Element>::iterator it=eVec.begin();
	vector<int> iVec;
	for(;it<eVec.end();it++)
	{
		iVec.push_back(temp.CountOf(*it));
	}
	Set s;
	for(unsigned int i=0;i<eVec.size();i++)
	{
		unsigned int index=i;
		for(unsigned int j=0;j<eVec.size();j++)
		{
			if(eVec[i].ConditionEqual(eVec[j])&&!eVec[i].DecisionEqual(eVec[j]))
			{
				if(iVec[i]<iVec[j])
				{
					index=j;
					eVec[i].SetDecision(eVec[j].GetDecision());
				}
				else if(iVec[i]==iVec[j])
				{
					if((*this).CountOfDecisionValue(eVec[i].GetDecision())<(*this).CountOfDecisionValue(eVec[j].GetDecision()))
					{
						index=j;
						eVec[i].SetDecision(eVec[j].GetDecision());
					}
				}
			}
		}
		s.Add(index);
	}
	s=s.ValueOfAttribute();
	vector<int> v=s.ToIntVector();
	vector<Element> vec=temp.GetDT();
	for(i=0;i<v.size();i++)
	{
		Element e=eVec[v[i]];
		for(unsigned int j=0;j<vec.size();j++)
		{
			if(e.Equal(vec[j]))
			{
				m.Add(vec[j].GetU());
			}
		}
	}
	return m.ValueOfAttribute();
}


double DecisionTable::LooseRelyDegreeOfDToC()
{
	double lr=0.0;
	Set M;
	M=this->GetM();
	//������ɢ������
	lr=this->RelyDegreeOfDToC()+(double)M.Card()/this->NumberOfElement();
	return lr;
}

double DecisionTable::LooseRelyDegreeOfDToAttribute(const char &c)
{
	DecisionTable temp=*this;
	vector<char>::iterator it=ConditionSet.begin();

	for(;it<ConditionSet.end();it++)
	{
		if(c!=*it)
		{
			temp.RemoveConditionAttribute(*it);
		}
	}
	return temp.LooseRelyDegreeOfDToC();
}

































































































