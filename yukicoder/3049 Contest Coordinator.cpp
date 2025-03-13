#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int a[MAX];
int main()
{
	int n,t,x,y,i,j,l,now;
	ll ans;
	scanf("%d%d%d%d",&n,&t,&x,&y);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	vector<int> res;
	l=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]>t)
		{
			res.push_back(i-l);
			l=i;
		}
	}
	res.push_back(n-l+1);
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	j=0;
	now=res[0];
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(i>now)
		{
			ans+=min(x,y);
			j++;
			now+=res[j];
		}
		printf("%lld%c",ans," \n"[i==n]);
	}
	return 0;
}
/*
顺序自选
所以可以sort之后，选区间一定是最优的
1 2 3 4 5 11 12 13 14 15
11 12 13 14 15 1 2 3 4 5
min(x,y)
*/
