#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2000+10;
int x[MAX],y[MAX];
int main()
{
	int n,i,j,nx,ny,g;
	ll ans,tmp,now,dis;
	scanf("%d",&n);
	map<pair<int,int>,vector<ll>> mp;
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			nx=x[i]-x[j];
			ny=y[i]-y[j];
			dis=1LL*nx*nx+1LL*ny*ny;
			g=__gcd(nx,ny);
			nx/=g;
			ny/=g;
			if(nx<0)
			{
				nx*=-1;
				ny*=-1;
			}
			mp[{nx,ny}].push_back(dis);
		}
	}
	ans=tmp=0;
	for(auto &it:mp)
	{
		now=it.second.size();
		ans+=now*(now-1)/2;
		map<ll,int> cnt;
		for(auto &d:it.second)
		{
			tmp+=cnt[d];
			cnt[d]++;
		}
	}
	printf("%lld\n",ans-tmp/2);
	return 0;
}
