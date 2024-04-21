#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
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
int lst[MAX],dp[MAX];
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	kmp.get_next(s,n);
	for(i=0;i<=n;i++) lst[i]=0;
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=i;
		if(lst[dp[kmp.nex[i]]]>=i-kmp.nex[i]) dp[i]=dp[kmp.nex[i]];
		lst[dp[i]]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}
