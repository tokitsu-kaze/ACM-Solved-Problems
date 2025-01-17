#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
ll a[MAX],now;
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	priority_queue<ll,vector<ll>,greater<ll>> q;
	now=0;
	for(i=1;i<=n;i++)
	{
		a[i]+=q.size();
		q.push(a[i]+now);
		while(!q.empty() && q.top()-now<=0) q.pop();
		a[i]=max(0LL,a[i]-(n-i));
		now++;
	}
	for(i=1;i<=n;i++) printf("%lld%c",a[i]," \n"[i==n]);
	return 0;
}

