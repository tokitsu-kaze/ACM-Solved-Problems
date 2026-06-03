#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int x,y,id;}a[MAX];
int ans[MAX];
int main()
{
	int n,i,t,x,tot;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&t,&x);
		a[i]={t+x,t-x,i};
	}
	sort(a+1,a+1+n,[](node a,node b){
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	});
	set<pair<int,int>> s;
	tot=0;
	for(i=1;i<=n;i++)
	{
		auto it=s.upper_bound({a[i].y,INF});
		if(it!=s.begin())
		{
			it--;
			ans[a[i].id]=(*it).second;
			s.erase(it);
		}
		else ans[a[i].id]=++tot;
		s.insert({a[i].y,ans[a[i].id]});
	}
	printf("%d\n",tot);
	for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
