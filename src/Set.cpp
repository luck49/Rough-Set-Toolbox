#include "Set.h"
////////////////////////////////////////集合类Set的实现///////////////////////////////////////


Set::Set(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		vec.push_back(A[i]);
	}
}



Set::Set(const Set &s)
{
	vec=s.vec;
}



Set::Set(vector<int> v)
{
	vec=v;
}



int Set::Card()
{
	return (int) vec.size();
}



const Set& Set::operator=(const Set &s)
{
	if(this !=&s)
	{
		vec=s.vec;
	}
	return *this;
}



bool Set::IsEmpty()
{
	return vec.empty();
}



void Set::Clear()
{
	vec.clear();
}



int Set::Find(int a)
{
	for(int i=0; i<(*this).Card();i++)
	{
		if(a==vec[i])
			return i;
	}
	return -1;
}



int Set::KeyAt(int i)
{
	return vec[i];
}



void Set::SetKey(int index, int Val)
{
	vec[index]=Val;
}



void Set::Sort()
{
	sort(vec.begin(),vec.end());
}



void Set::Remove(int a)
{
	if(Find(a)!=-1)
	{
		vector<int> v;
		for(vector<int>::iterator it=vec.begin();it<vec.end();it++)
		{
			if(*it !=a)
			{
				v.push_back(*it);
			}
		}
		vec=v;
	}
}


void Set::Add(int a)
{
	vec.push_back(a);
}



bool Set::BelongTo(Set &s)
{
	for(int i=0;i<(int)vec.size();i++)
	{
		if(s.Find(vec[i])==-1)
			return false;
	}
	return true;
}



bool Set::operator ==(Set &s)
{
	if(this->BelongTo(s)&&s.BelongTo(*this))
	{
		return true;
	}
	else
	{
		return false;
	}
}
Set Set::Sub(Set &s) const
{
	Set temp(vec);
	for (int i=0;i<s.Card();i++)
	{
		temp.Remove(s.KeyAt(i));
	}
	return temp;
}




Set Set::Union(Set &s)const
{
	Set temp(vec);
	for (int i=0;i<s.Card();i++)
	{
		if(temp.Find(s.KeyAt(i))==-1)
		{
			temp.Add(s.KeyAt(i));
		}
	}
	return temp;
}



Set Set::InterSect(Set &s)const
{
	Set temp(vec);
	for(int i=0;i<(int)vec.size();i++)
	{
		if(s.Find(vec[i])==-1)
		{
			temp.Remove(vec[i]);
		}
	}
	Set VOfa=temp.ValueOfAttribute();
	return VOfa;
}



Set Set::ValueOfAttribute()
{
	Set temp;
	for(int i=0;i<Card();i++)
	{
		if(KeyAt(i)!=INT_MAX)
		{
			temp.Add(KeyAt(i));
			for(int j=i+1;j<Card();j++)
			{
				if(KeyAt(i)==KeyAt(j))
					SetKey(j,INT_MAX);
			}
		}
		else
		{
			continue;
		}
	}
	return temp;
}




vector<int> Set::ToIntVector()
{
	vector<int> temp;
	for(int i=0;i<this->Card();i++)
	{
		temp.push_back(this->KeyAt(i));
	}
	return temp;
}





void Set::Print()
{
	vector<int>::iterator it=vec.begin();
	cout<<"{";
	if(!vec.empty())
	{
		cout<<*it++;
	}
	for(;it<vec.end();++it)
	{
		cout<<","<<*it;
	}
	cout<<"}";
}














