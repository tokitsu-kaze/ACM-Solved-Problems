#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int a[MAX],dp[MAX],n,k;
ll bit[MAX];
int ck(ll mn)
{
	int i,j;
	ll premn=0;
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(bit[i]-premn<mn)
		{
			premn=min(premn,bit[i]);
			continue;
		}
		premn=min(premn,bit[i]);
		for(j=0;j<tot;j++)
		{
			if(i-p[j]<0) break;
			if(bit[i]-bit[i-p[j]]>=mn)
			{
				dp[i]=max(dp[i],dp[i-p[j]]+1);
				break;
			}
		}
		if(dp[i]>=k) return 1;
	}
//	cout<<mn<<" "<<dp[n]<<endl;
	return dp[n]>=k;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,i;
	ll l,r,mid;
	init(MAX-10);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			bit[i]=bit[i-1]+a[i];
		}
		l=-2e9;
		r=2e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		if(ck(l)) cout<<l<<"\n";
		else cout<<"impossible\n";
	}
	return 0;
}

