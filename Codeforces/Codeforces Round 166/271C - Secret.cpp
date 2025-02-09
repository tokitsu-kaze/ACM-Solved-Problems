#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e5+10;
struct node{int y,id;};
vector<node> pos[MAX];
int t[MAX],mx[MAX],cnt[MAX],id[MAX];
int x[MAX],y[MAX];
int main()
{
	int n,w,q,i,c,a,b;
	scanf("%d%d",&n,&w);
	for(i=1;i<=w;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		pos[x[i]].push_back({y[i],i});
		t[i]=mx[i]=cnt[i]=0;
	}
	for(i=1;i<=w;i++)
	{
		sort(pos[i].begin(),pos[i].end(),[](node a,node b){
			return a.y<b.y;
		});
		c=0;
		for(auto &it:pos[i])
		{
			t[it.id]=it.y;
			c++;
			cnt[c]++;
			mx[c]=max(mx[c],it.y);
			id[it.id]=c;
		}
	}
	for(i=2;i<=n;i++)
	{
		if(cnt[i]==w) mx[i]=max(mx[i-1]+1,mx[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(cnt[id[i]]!=w) t[i]=INF;
		else t[i]=max(t[i],mx[id[i]]);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		if(t[b]<=a) puts("No");
		else puts("Yes");
	}
	return 0;
}
/*
5 1
1 1
1 2
1 3
1 5
1 10
10000
1 1
1 2
1 3
*/
