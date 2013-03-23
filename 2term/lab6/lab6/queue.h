#pragma once
//12.	ќдносторонн€€ очередь

template <class Type>
ref class queue
{
private:
	queue<Type> ^prev;
	Type info;
	queue<Type> ^beg, ^end;
	
public:
	queue()
	{
		end = beg = nullptr;
		prev = nullptr;
	}
	void add(Type k)
	{
		queue ^temp = gcnew queue();
		temp->doinfo(k);
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
	int find(Type k)
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
	int del(Type k)
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
	queue<Type>^ retbeg() {return beg;}
	Type reti() {return info;}
	queue<Type>^ retpr() {return prev;}	
	void doinfo(Type k) {info = k;}
};
