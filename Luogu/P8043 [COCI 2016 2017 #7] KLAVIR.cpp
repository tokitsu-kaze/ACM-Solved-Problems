#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=1e9+7;
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
int a[MAX],pwn[MAX],dp[MAX];
int main()
{
	int n,m,i;
	scanf("%d",&n);
	pwn[0]=1;
	for(i=1;i<MAX;i++) pwn[i]=1LL*pwn[i-1]*n%mod;
	scanf("%d",&m);
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	kmp.get_next(a,m);
	memset(dp,0,sizeof dp);
	for(i=1;i<=m;i++)
	{
		dp[i]=(pwn[i]+dp[kmp.nex[i]])%mod;
		printf("%d\n",dp[i]);
	}
	return 0;
}
/*
[CTSC2006] 歌唱王国 结论：E(S)=sum{K^len_i}，其中：
K 为字符集，len_i 为 字符串 S 的所有 border 长度。
求所有前缀答案，dp一下即可。
*/
