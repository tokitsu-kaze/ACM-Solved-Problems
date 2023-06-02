#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
struct KMP
{
	int nex[MAX],len;
	char t[MAX];
	void get_next(char *s)
	{
		int i,j;
		len=strlen(s+1);
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]='\0';
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	
	// s[1..n], return all pos t in s 
	vector<int> match(char *s)
	{
		int n,i,j;
		vector<int> res;
		n=strlen(s+1);
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
}kmp;// kmp.get_next(s); s[1..len]
char s[MAX];
int dp[MAX];
int dfs(int x)
{
	if(dp[x]!=-1) return dp[x];
	if(kmp.nex[x]==0) return dp[x]=x;
	dp[x]=dfs(kmp.nex[x]);
	return dp[x];
}
int main()
{
	int i,n,res;
	ll ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	kmp.get_next(s);
	ans=0;
	for(i=0;i<=n;i++) dp[i]=-1;
	for(i=1;i<=n;i++)
	{
		res=dfs(i);
		if(res>0) ans+=i-res;
	}
	printf("%lld\n",ans);
	return 0;
}

