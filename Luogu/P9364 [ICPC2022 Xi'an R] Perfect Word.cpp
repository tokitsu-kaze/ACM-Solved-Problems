#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
string s[MAX];
char tmp[MAX];
map<string,int> mp;
int ck(string x)
{
	int i,j;
	for(i=0;i<x.size();i++)
	{
		string now;
		for(j=i;j<x.size();j++)
		{
			now.push_back(x[j]);
			if(!mp.count(now)) return 0;
		}
	}
	return 1;
}
int main()
{
	int n,i,mx,pos,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",tmp);
		s[i]=string(tmp);
	}
	sort(s+1,s+1+n,[&](string x,string y){
		return x.size()<y.size();
	});
	mx=s[n].size();
	pos=n;
	for(i=2;i<=n;i++)
	{
		if(s[i-1].size()+2<=s[i].size())
		{
			mx=s[i-1].size();
			pos=i-1;
			break;
		}
	}
	mp.clear();
	for(i=1;i<=n;i++)
	{
		if(s[i].size()>mx) break;
		mp[s[i]]=1;
	}
	ans=0;
	for(i=pos;i;i--)
	{
		if(ck(s[i]))
		{
			ans=s[i].size();
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
