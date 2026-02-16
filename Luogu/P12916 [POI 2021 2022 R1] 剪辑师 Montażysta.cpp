#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct node{int id;ll t,e;}a[MAX];
int main()
{
	int T,n,i,ans;
	ll now;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].t,&a[i].e);
		a[i].id=i;
	}
	sort(a+1,a+1+n,[](node x,node y){
		if(x.e==y.e) return x.t<y.t;
		return x.e<y.e;
	});
	priority_queue<pair<ll,pair<ll,int>>> q;
	now=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		q.push({a[i].t,{-a[i].e,i}});
		now+=a[i].t;
		if(now<=a[i].e) ans++;
		else
		{
			now-=q.top().first;
			q.pop();
		}
	}
	printf("%d\n",ans);
	vector<node> res;
	while(!q.empty())
	{
		res.push_back(a[q.top().second.second]);
		q.pop();
	}
	sort(res.begin(),res.end(),[](node x,node y){
		return x.e<y.e;
	});
	now=1;
	for(auto &it:res)
	{
		printf("%d %lld\n",it.id,now);
		now+=it.t;
	}
	return 0;
}
