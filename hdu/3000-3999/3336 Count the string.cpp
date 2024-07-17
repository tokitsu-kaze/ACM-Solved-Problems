#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
const int mod=10007;
struct KMP
{
	#define type char
	int nex[MAX],len;
	type t[MAX];
	void get_next(type *s,int n)
	{
		int i,j;
		len=n;
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]=0;
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	vector<int> match(type *s,int n)
	{
		int i,j;
		vector<int> res;
		for(i=1,j=0;i<=n;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			if(j==len)
			{
				res.push_back(i-len+1);
				j=nex[j];
			}
		}
		return res;
	}
	#undef type
}kmp;
/*
kmp.get_next(t,len); // t[1..len]
kmp.match(s,n); // s[1..n] return all pos t in s 
*/
char s[MAX];
vector<int> mp[MAX];
int sz[MAX],ans;
void dfs(int x)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		dfs(to);
		sz[x]+=sz[to];
	}
	if(x) ans=(ans+sz[x])%mod;
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		kmp.get_next(s,n);
		for(i=0;i<=n;i++) mp[i].clear();
		for(i=1;i<=n;i++) mp[kmp.nex[i]].push_back(i);
		ans=0;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}

