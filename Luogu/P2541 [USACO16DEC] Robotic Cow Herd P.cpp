#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct node
{
	ll v;
	int x,y;
	friend bool operator < (node a,node b)
	{
		return a.v>b.v;
	}
};
vector<int> a[MAX];
int main()
{
	int k,tot,n,m,i;
	ll sum,ans;
	scanf("%d%d",&k,&n);
	sum=0;
	tot=0;
	for(i=0;i<k;i++)
	{
		scanf("%d",&m);
		a[tot].resize(m);
		for(auto &it:a[tot]) scanf("%d",&it);
		sort(a[tot].begin(),a[tot].end());
		sum+=a[tot][0];
		if(m>1) tot++;
	}
	if(n==1)
	{
		printf("%lld\n",sum);
		return 0;
	}
	vector<ll> res;
	res.push_back(sum);
	priority_queue<node> q;
	sort(a,a+tot,[](const vector<int> &x,const vector<int> &y){
		return x[1]-x[0]<y[1]-y[0];
	});
	q.push({sum-a[0][0]+a[0][1],0,1});
	while(res.size()<n)
	{
		node t=q.top();
		q.pop();
		res.push_back(t.v);
		if(t.y+1<a[t.x].size()) q.push({t.v-a[t.x][t.y]+a[t.x][t.y+1],t.x,t.y+1});
		if(t.x+1<tot) q.push({t.v-a[t.x+1][0]+a[t.x+1][1],t.x+1,1});
		if(t.x+1<tot && t.y==1) q.push({t.v-a[t.x][1]+a[t.x][0]-a[t.x+1][0]+a[t.x+1][1],t.x+1,1});
	}
	ans=0;
	for(auto &it:res) ans+=it;
	printf("%lld\n",ans);
	return 0;
}
/*
3 27
3 512 256 128
3 64 32 16
3 8 4 2
*/
