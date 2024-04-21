#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
const int mod=376544743;
int a[MAX],b[MAX];
int dp[2][(1<<16)+5];
int spj(int n,int m,int k)
{
	int i,ok;
	ok=1;
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		if(i&&a[i]==a[i-1]) ok=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		if(i&&b[i]==b[i-1]) ok=0;
	}
	if(k==1)
	{
		if(n>1||m>1) ok=0;
		if(a[0]!=b[0]) ok=0;
		return ok;
	}
	
	for(i=0;i<m;i++)
	{
		if(n&1)
		{
			if(a[i]!=b[i]) ok=0;
		}
		else
		{
			if(a[i]==b[i]) ok=0;
		}
	}
	return ok;
}
int main()
{
	int n,m,k,i,j,be,ed,x,s,f,up,lf,tmp,now;
	scanf("%d%d%d",&n,&m,&k);
	if(k<=2) return 0*printf("%d\n",spj(n,m,k));
	be=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		be=(be<<2)|x;
	}
	ed=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		ed=(ed<<2)|x;
	}
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][be]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			f^=1;
			memset(dp[f],0,sizeof dp[f]);
			for(s=0;s<(1<<(2*m));s++)
			{
				up=(s>>(2*j))&3;
				if(j==0) lf=-1;
				else lf=(s>>(2*(j-1)))&3;
				tmp=(((1<<(2*m))-1)^(3<<(2*j)))&s;
				for(x=0;x<k;x++)
				{
					if(lf==x||up==x) continue;
					now=tmp|(x<<(2*j));
					dp[f][now]=(dp[f][now]+dp[f^1][s])%mod;
				}
			}
		}
	}
	printf("%d\n",dp[f][ed]);
	return 0;
}

