#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
map<int,int> mp;
int cal(int x,int y)
{
	if(x==y) return 0;
	if(x<y) return y-x;
	int res=x-y;
	for(int i=0;i<=30;i++) res=min(res,i+abs((x>>i)-y));
	return res;
}
int main()
{
	int t,n,m,a[505],i,j,x;
	ll now,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=LLINF;
		mp.clear();
		for(j=1;j<=n;j++)
		{
			x=a[j];
			while(x>=0)
			{
				if(mp.count(x)) break;
				mp[x]=1;
				vector<int> res;
				for(i=1;i<=n;i++) res.push_back(cal(a[i],x));
				sort(res.begin(),res.end());
				now=0;
				for(i=0;i<n-m;i++) now+=res[i];
				ans=min(ans,now);
				x>>=1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
