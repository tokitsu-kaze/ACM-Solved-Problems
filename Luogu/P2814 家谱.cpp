#include<bits/stdc++.h>
using namespace std;
struct dsu
{
	#define type string
	unordered_map<type,type> pre;
	void init(){pre.clear();}
	type find(type x)
	{
		if(pre.count(x)) pre[x]=find(pre[x]);
		else return x;
		return pre[x];
	}
	bool merge(type a,type b)
	{
		type ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
	#undef type
}dsu;
int main()
{
	char s[11];
	string fa;
	dsu.init();
	while(~scanf("%s",s))
	{
		if(s[0]=='$') break;
		if(s[0]=='#')
		{
			fa=string(s+1);
			dsu.merge(fa,fa);
		}
		else if(s[0]=='+') dsu.merge(s+1,fa);
		else printf("%s %s\n",s+1,dsu.find(s+1).c_str());
	}
	return 0;
}
