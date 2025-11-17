#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
ull highbit(ll x){return 1ull<<(63-__builtin_clzll(x));}
ll a[MAX],sum[MAX];
ull sl[MAX],sr[MAX];
bool dp[MAX][MAX],okl[MAX],okr[MAX];
char res[MAX];
int main()
{
	int T,n,len,l,r,i,j;
	ll now;
	ull hb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]^a[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) dp[i][j]=0;
			sl[i]=sr[i]=okl[i]=okr[i]=0;
		}
		dp[1][n]=1;
		if(sum[n]) sl[1]=sr[n]=highbit(sum[n]);
		else okl[1]=okr[n]=1;
		for(len=n-1;len>=1;len--)
		{
			for(l=1;l+len-1<=n;l++)
			{
				r=l+len-1;
				now=sum[r]^sum[l-1];
				/*
				如果满足 (sl[l]&now)>0 || (sr[r]&now)>0
				- now只可能>0 
				如果满足 okl[l] || okr[r]，说明存在更长的合法区间使得sum=0
				- 如果 now!=0，那么一定能选出sum^now，所以合法
				- 如果 now=0，那么一定能选出sum^now，所以合法
				*/
				if((sl[l]&now)>0 || (sr[r]&now)>0 || okl[l] || okr[r])
				{
					dp[l][r]=1;
					if(now)
					{
						hb=highbit(now);
						sl[l]|=hb;
						sr[r]|=hb;
					}
					else okl[l]=okr[r]=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(dp[i][i]) res[i]='1';
			else res[i]='0';
		}
		res[n+1]='\0';
		puts(res+1);
	}
	return 0;
}
