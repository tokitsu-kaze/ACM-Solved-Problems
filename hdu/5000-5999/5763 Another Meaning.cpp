#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const int mod=1000000007;
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
char s[MAX],t[MAX];
int dp[MAX];
int main()
{
	int T,cas,n,m,i,j;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		kmp.get_next(t,m);
		vector<int> res=kmp.match(s,n);
		dp[0]=1;
		for(i=1,j=0;i<=n;i++)
		{
			dp[i]=dp[i-1];
			if(j<res.size()&&res[j]+m-1==i)
			{
				dp[i]=(dp[i]+dp[i-m])%mod;
				j++;
			}
		}
		printf("Case #%d: %d\n",cas,dp[n]);
	}
	return 0;
}
