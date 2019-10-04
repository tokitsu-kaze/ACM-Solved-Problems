#include <bits/stdc++.h>
using namespace std;
set<string>se[11];

void build(string s,int id)
{
	for(int i=1;i<(1<<s.length());i++)
	{
		string s2;
		for(int j=0;j<s.length();j++)
		{
			if(i&(1<<j))
			{
				s2.push_back(s[j]);
			}
		}
		se[id].insert(s2);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			se[i].clear();
			string temp;
			cin>>temp;
			int len=temp.length();
			for(int j=0;j<len+1;j++)
			{
				build(temp,i);
				char now=temp[0];
				temp.erase(temp.begin());
				temp.push_back(now);
			}
		}
		string now="";
		for(auto &i:se[0])
		{
			for(int j=1;j<n;j++)
			{
				if(!se[j].count(i))
					goto end;
			}
			if(now.length()<i.length())
			{
				now=i;
			}
			if(now.length()==i.length())
				now=min(now,i);
			end:;
		}
		if(now=="")
		{
			puts("0");
		}
		else
		{
			puts(now.c_str());
		}
	}
}
