#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int cal(int x,int y,int l,int r)
{
	return max(0,min(y,r)-max(x,l)+1);
}
int main()
{
	int T,n,m,l,r,len,i,j,k;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&l,&r);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		len=r-l+1;
		map<int,int> mp;
		ans=0;
		for(i=1,j=k=0;i<=n;i++)
		{
			while(j+1<=n && mp.size()<m)
			{
				j++;
				mp[a[j]]++;
			}
			k=max(k,j);
			while(k+1<=n && mp.count(a[k+1])) k++;
			if(mp.size()==m) ans+=cal(i+l-1,i+r-1,j,k);
			mp[a[i]]--;
			if(mp[a[i]]==0) mp.erase(a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
