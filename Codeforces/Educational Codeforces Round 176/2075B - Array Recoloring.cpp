#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int a[MAX],vis[MAX],tmp[MAX];
int main()
{
	int T,n,k,i,j,mx,pos,cnt,tot;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		a[0]=0;
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=n;i++) vis[i]=0;
			now=a[j];
			vis[j]=1;
			cnt=0;
			mx=pos=0;
			for(i=1;i<j;i++)
			{
				if(a[i]>mx)
				{
					mx=a[i];
					pos=i;
				}
			}
			if(pos)
			{
				cnt++;
				now+=a[pos];
				vis[pos]=1;
			}
			mx=pos=0;
			for(i=j+1;i<=n;i++)
			{
				if(a[i]>mx)
				{
					mx=a[i];
					pos=i;
				}
			}
			if(pos)
			{
				cnt++;
				now+=a[pos];
				vis[pos]=1;
			}
			if(cnt>k) continue;
			tot=0;
			for(i=1;i<=n;i++)
			{
				if(vis[i]) continue;
				tmp[++tot]=a[i];
			}
			sort(tmp+1,tmp+1+tot);
			reverse(tmp+1,tmp+1+tot);
			for(i=1;i<=min(tot,k-cnt);i++) now+=tmp[i];
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
