#include"Element.h"
//决策表元素类的实现------------------------------------
Element::Element(std::vector<int> condition,std::vector<int> decision,int iNo)
{
	ValueOfCondition=condition;
	ValueOfCondition=decision;
	u=iNo;
}
Element::Element(Set &condition,Set &decision, int iNo)
{
	ValueOfCondition= condition.ToIntVector();
	ValueOfCondition= decision.ToIntVector();
	u=iNo;
}
const Element& Element::operator =(const Element &e)
{
	if(this!=&e)
	{
		ValueOfCondition=e.GetCondition();
		ValueOfDecision=e.GetDecision();
		u=e.GetU();
	}
	return *this;
}


void Element::SetU(int &u)
{
	this->u=u;
}


void Element::SetCondition(vector<int> &condition)
{
	ValueOfCondition=condition;
}
void Element::SetDecision(std::vector<int> &decision)
{
	ValueOfDecision=decision;
}
int Element::GetU()const
{
	return u;
}
vector<int> Element::GetCondition()const
{
	return ValueOfCondition;
}
vector<int>::iterator Element::GetConditionBegin()
{
	return ValueOfCondition.begin();
}
vector<int>::iterator Element::GetConditionEnd()
{
	return ValueOfCondition.end();
}
vector<int> Element::GetDecision()const
{
	return ValueOfDecision;
}
bool Element::ConditionEqual(Element &other)
{
	vector<int>::iterator it1 = ValueOfCondition.begin();
	vector<int> temp= other.GetCondition();
	vector<int>::iterator it2 = temp.begin();
	for(;it1<ValueOfCondition.end()&&it2<temp.end();it1++,it2++)
	{
		if(*it1!=*it2)
		{
			return false;
		}
	}
	return true;
}

bool Element::DecisionEqual(Element &other)
{
	vector<int>::iterator it1= ValueOfDecision.begin();
	vector<int> temp=other.GetDecision();
	vector<int>::iterator it2= temp.begin();
	for(;it1<ValueOfDecision.end()&&it2<temp.end();it1++,it2++)
	{
		if(*it1!=*it2)
		{
			return false;
		}
	}
	return true;
}

bool Element::UEqual(Element &other)
{
	if(u!=other.GetU())
	{
		return false;
	}
	return true;
}
bool Element::Equal(Element &other)
{
	if((*this).ConditionEqual(other)&&(*this).DecisionEqual(other))
	{
		return true;
	}
	return false;
}



void Element::RemoveConditionAttribute(vector<int>::iterator it)
{
	ValueOfCondition.erase(it);
}




void Element::AddConditionAttribute(int &a)
{
	ValueOfCondition.push_back(a);
}






void Element::Print()
{
	if(!ValueOfCondition.empty()&&!ValueOfDecision.empty())
	{
		cout<<"(";
		vector<int>::iterator it=ValueOfCondition.begin();
		cout<<*it++;
		for(;it<ValueOfCondition.end();it++)
		{
			cout<<",\t";
			cout<<*it;
		}
		cout<<")\t->\t(";
		it=ValueOfDecision.begin();
		cout<<*it++;
		for(;it<ValueOfDecision.end();it++)
		{
			cout<<",\t";
			cout<<*it;
		}
		cout<<")\tu"<<u<<endl;
	}
	else
	{
		cout<<"该样本没有意义！请初始化，或者赋值！"<<endl;
	}
}














