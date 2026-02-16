#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int v,id;
	friend bool operator < (node x,node y)
	{
		if(x.v==y.v) return x.id<y.id;
		return x.v<y.v;
	}
};
int vis[MAX],a[MAX],b[MAX],c[MAX];
int main()
{
	int n,i,ans,x,y,z;
	scanf("%d",&n);
	priority_queue<node> ra,rb,rc;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		ra.push({a[i],i});
		rb.push({b[i],i});
		rc.push({c[i],i});
		vis[i]=0;
	}
	ans=-1;
	while(1)
	{
		while(!ra.empty() && vis[ra.top().id]) ra.pop();
		while(!rb.empty() && vis[rb.top().id]) rb.pop();
		while(!rc.empty() && vis[rc.top().id]) rc.pop();
		if(ra.empty()) break;
		if(rb.empty()) break;
		if(rc.empty()) break;
		x=ra.top().id;
		y=rb.top().id;
		z=rc.top().id;
		if(b[x]==b[y] || c[x]==c[z]) vis[x]=1;
		if(a[y]==a[x] || c[y]==c[z]) vis[y]=1;
		if(a[z]==a[x] || b[z]==b[y]) vis[z]=1;
		if(!vis[x] && !vis[y] && !vis[z])
		{
			ans=a[x]+b[y]+c[z];
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
有点神秘。
用3个堆分别维护，如果有一个人不合法，说明这个人绝对不可能选出，把他删了继续做。 
*/
