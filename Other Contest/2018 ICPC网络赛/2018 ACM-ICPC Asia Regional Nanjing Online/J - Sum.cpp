#include<bits/stdc++.h>
using namespace std;

const int N=2e7+2;

int mobius[N],prim[N/5],num,sum[N];
bool vis[N];
int ok[N];
int tot;
void mobiusfun()
{
	mobius[1]=1;
	sum[1]=1;
	tot=0;
	ok[tot++]=1;
	for(register int i=2;i<N;i++)
	{
		if(!vis[i])
			prim[++num]=i,mobius[i]=-1;
		for(register int j=1;prim[j]*i<N;j++)
		{
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)
			{
				mobius[i*prim[j]]=0;
				break;
			}
			mobius[i*prim[j]]=-mobius[i];
		}
		if(mobius[i])sum[i]=1;
        sum[i]+=sum[i-1];
        if(mobius[i]!=0)
		{
			ok[tot]=i;
			tot++;
		}
	}
}

int main()
{
	mobiusfun();
	int t;
	scanf("%d",&t);
	int n;
	long long s0;
	while(t--)
	{
		scanf("%d",&n);
		s0=0;
		for(register int i=0;ok[i]<=n;i++)
		{
			s0+=sum[n/ok[i]];
		}
		printf("%lld\n",s0);
	}
}