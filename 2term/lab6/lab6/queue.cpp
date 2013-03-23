#include "StdAfx.h"
#include "queue.h"
//template <class Type>
/*queue<Type>::queue()
{
	beg = nullptr;
	end = nullptr;
	info = 0;
}
//template <int>
template <typename Type>
queue<Type>::queue(int i)
{
	//beg = 0;
	//end = 0;
	this->info = i;
}
template <class Type>
void queue<Type>::add(Type k)
{
	queue<Type> ^temp = gcnew queue<Type>();
	if(beg == nullptr)
	{
		beg = end = temp;
		temp->prev = nullptr;
	}
	else
	{
		end->prev = temp;
		end = temp;
		end->prev = nullptr;
	}
}
template <class Type>
int queue<Type>::find(Type k)
{
	int t = 0;
	queue ^temp = beg;
	while(temp != nullptr)
	{
		if(temp->info == k)
		{
			t++;
		}
		temp = temp->prev;
	}
	return t;
}
template <class Type>
int queue<Type>::del(Type k)
{
	queue ^temp, ^temp2; 
	int t = find(k);
	if(t == 0)
		return 0;
	int i = 0;
	for(i = 0; i < t; i++)
	{
		temp = beg;
		if(temp->info == k)
		{
			beg = beg->prev;
			delete temp;
		}
		else
		{
			//temp = beg;
			if(end->info == k)
			{
				while((temp->prev)->prev != nullptr)
					temp = temp->prev;
				delete end;
				end = temp;
				temp->prev = nullptr;
			}
			else
			{
				while((temp->prev)->info != k)
					temp = temp->prev;
				temp2 = temp->prev;
				temp->prev = (temp->prev)->prev;
				delete temp2;
			}
		}
	}
	return t;
}
*/