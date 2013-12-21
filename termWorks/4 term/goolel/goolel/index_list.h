#pragma once

ref class index_list
{
private:
	cli::array<bool> ^list;
public:
	String^ s;
	int count;
	int Length;
	index_list(String^ str,int n);
	~index_list();
	void set(int i);
	bool get(int i);
	String^ get_str();
	bool check(String^ s, int i);
	index_list^ operator +(index_list ^a);
	index_list^ operator -(index_list ^a);

};
