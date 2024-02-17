#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
int pre[MAX],dp[MAX];
void init(int n)
{
	int i,j;
	for(i=1;i<=n;i++) dp[i]=INF;
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;i-j*(j+1)/2>=0;j++)
		{
			if(dp[i]>dp[i-j*(j+1)/2]+j)
			{
				dp[i]=dp[i-j*(j+1)/2]+j;
				pre[i]=i-j*(j+1)/2;
			}
		}
	}
}
char res[MAX];
int main()
{
	int t,n,k,i,l,r,sq;
	init(1e5);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(dp[k]*2>n)
		{
			puts("-1");
			continue;
		}
		l=r=2e5;
		while(k>0)
		{
			sq=sqrt(2*(k-pre[k]));
			while(sq*(sq+1)/2<k-pre[k]) sq++;
			while(sq>=0 && sq*(sq+1)/2>k-pre[k]) sq--;
			assert(sq);
			k-=sq*(sq+1)/2;
			res[--l]='(';
			res[r++]=')';
			sq--;
			while(sq>0)
			{
				res[r++]='(';
				res[r++]=')';
				sq--;
			}
		}
		while(r-l<n) res[r++]='(';
		res[r]='\0';
		puts(res+l);
	}
	return 0;
}
