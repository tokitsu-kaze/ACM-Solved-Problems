#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
ll a[13],b[13];
vector<ll> res;
int n;
void dfs(int x,int tot,ll now)
{
	int i;
	if(x==n+1)
	{
		res.push_back(now);
		return;
	}
	for(i=1;i<=tot;i++)
	{
		now^=b[i];
		b[i]+=a[x];
		now^=b[i];
		dfs(x+1,tot,now);
		now^=b[i];
		b[i]-=a[x];
		now^=b[i];
	}
	b[tot+1]=a[x];
	dfs(x+1,tot+1,now^b[tot+1]);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	res.clear();
	memset(b,0,sizeof b);
	dfs(1,0,0);
	sort(res.begin(),res.end());
	res.resize(unique(res.begin(),res.end())-res.begin());
	printf("%d\n",(int)res.size());
	return 0;
}

