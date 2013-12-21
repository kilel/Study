#include "StdAfx.h"
#include "index_list.h"

index_list::index_list(String^str, int n)
{
	count = 0;
	s = str->ToLower();
	list = gcnew array<bool>(n);
	for(int i = 0; i < n; i++)
		list[i] = false;
	Length = n;
}
index_list::~index_list()
{
	delete list;
}
void index_list::set(int i)
{
	if(! list[i])
		count++;
	list[i] = true;
}
bool index_list::get(int i)
{
	return list[i];
}
String^ index_list::get_str()
{
	return this->s;
}
bool index_list::check(String^ str, int i)
{
	if(!String::Compare(s, str->ToLower()))
	{
		this->set(i);
		return true;
	}
	return false;
}
index_list^ index_list::operator +(index_list ^a)
{
	int n = a->Length;
	index_list^ c = gcnew index_list("", n), ^b = this;
	for(int i = 0; i < n; i++)
		if(a->get(i)|b->get(i))
			c->set(i);
	return c;
}
index_list^ index_list::operator -(index_list ^a)
{
	int n = a->Length;
	index_list^ c = gcnew index_list("", n), ^b = this;
	for(int i = 0; i < n; i++)
		if(a->get(i)&b->get(i))
			c->set(i);
	return c;
}