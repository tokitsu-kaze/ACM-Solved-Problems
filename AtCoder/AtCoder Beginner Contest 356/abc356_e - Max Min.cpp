#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
const int mod=998244353;
int cnt[MAX],bit[MAX];
int main()
{
	int n,i,j,l,r,x;
	ll ans;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	bit[0]=0;
	for(i=1;i<=MAX-10;i++) bit[i]=bit[i-1]+cnt[i];
	ans=0;
	for(i=1;i<=MAX-10;i++)
	{
		if(cnt[i]==0) continue;
		ans-=1LL*cnt[i]*cnt[i];
		ans+=1LL*cnt[i]*(cnt[i]-1)/2;
		for(j=1;1LL*i*j<=MAX-10;j++)
		{
			l=i*j;
			r=min(i*j+i-1,MAX-10);
			ans+=1LL*cnt[i]*j*(bit[r]-bit[l-1]);
	//		cout<<" "<<j<<" "<<l<<" "<<r<<" "<<ans<<endl;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
