#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
ll x[MAX],y[MAX];
int main()
{
	int n,i,j;
	ll ans,a,b,g,k,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
	ans=cnt=0;
	map<pair<ll,ll>,set<ll>> mp;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			a=x[i]-x[j];
			b=y[i]-y[j];
			g=__gcd(a,b);
			a/=g;
			b/=g;
			if(a<0 || (a==0 && b<0))
			{
				a*=-1;
				b*=-1;
			}
			k=a*y[j]-b*x[j];
			if(mp[{a,b}].count(k)) continue;
			cnt++;
			mp[{a,b}].insert(k);
			ans+=cnt-mp[{a,b}].size();
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
求出斜率向量，然后与其中一个点的向量做叉积，
结果是位置关系，可以用来去掉共线的情况。
*/
