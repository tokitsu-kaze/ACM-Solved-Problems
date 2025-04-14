#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int n,m,k,h[MAX],x[MAX];
int ck(int cnt)
{
	int i,l,r,tmp,now;
	map<int,int> mp;
	for(i=1;i<=n;i++)
	{
		if(1LL*cnt*m<h[i]) continue;
		tmp=m-(h[i]+cnt-1)/cnt;
		l=x[i]-tmp;
		r=x[i]+tmp;
		mp[l]++;
		mp[r+1]--;
	}
	now=0;
	for(auto &it:mp)
	{
		now+=it.second;
		if(now>=k) return 1;
	}
	return 0;
}
int main()
{
	int T,i,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i++) scanf("%d",&h[i]);
		for(i=1;i<=n;i++) scanf("%d",&x[i]);
		l=0;
		r=1e9+1e5+10;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		if(!ck(l)) puts("-1");
		else printf("%d\n",l);
	}
	return 0;
}

