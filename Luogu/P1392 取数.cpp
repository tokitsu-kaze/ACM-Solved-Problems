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
	int n,m,k,i;
	ll sum;
	scanf("%d%d%d",&n,&m,&k);
	sum=0;
	for(i=0;i<n;i++)
	{
		a[i].resize(m);
		for(auto &it:a[i]) scanf("%d",&it);
		sort(a[i].begin(),a[i].end());
		sum+=a[i][0];
	}
	if(k==1)
	{
		printf("%lld\n",sum);
		return 0;
	}
	vector<ll> res;
	res.push_back(sum);
	priority_queue<node> q;
	sort(a,a+n,[](const vector<int> &x,const vector<int> &y){
		return x[1]-x[0]<y[1]-y[0];
	});
	q.push({sum-a[0][0]+a[0][1],0,1});
	while(res.size()<k)
	{
		node t=q.top();
		q.pop();
		res.push_back(t.v);
		if(t.y+1<a[t.x].size()) q.push({t.v-a[t.x][t.y]+a[t.x][t.y+1],t.x,t.y+1});
		if(t.x+1<n) q.push({t.v-a[t.x+1][0]+a[t.x+1][1],t.x+1,1});
		if(t.x+1<n && t.y==1) q.push({t.v-a[t.x][1]+a[t.x][0]-a[t.x+1][0]+a[t.x+1][1],t.x+1,1});
	}
	for(i=0;i<k;i++) printf("%lld%c",res[i]," \n"[i==k-1]);
	return 0;
}
/*
3 3 27
512 256 128
64 32 16
8 4 2
*/
