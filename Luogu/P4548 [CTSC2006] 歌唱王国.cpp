#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct KMP
{
	#define type int
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
const int mod=10000;
int a[MAX],pwn[MAX];
int main()
{
	int n,T,m,i,ans,now;
	scanf("%d%d",&n,&T);
	pwn[0]=1;
	for(i=1;i<MAX;i++) pwn[i]=pwn[i-1]*n%mod;
	while(T--)
	{
		scanf("%d",&m);
		for(i=1;i<=m;i++) scanf("%d",&a[i]);
		kmp.get_next(a,m);
		ans=0;
		now=m;
		while(now)
		{
			ans=(ans+pwn[now])%mod;
			now=kmp.nex[now];
		}
		printf("%04d\n",ans);
	}
	return 0;
}
/*
结论：E(S)=sum{K^len_i}，其中：
K 为字符集，len_i 为 字符串 S 的所有 border 长度。
*/
