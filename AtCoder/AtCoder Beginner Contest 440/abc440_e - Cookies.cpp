#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=50+10;
struct node{
	ll v;
	vector<int> cnt;
	friend bool operator < (node a,node b)
	{
		return a.v<b.v;
	}
};
int a[MAX];
int main()
{
	int n,k,x,i;
	scanf("%d%d%d",&n,&k,&x);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	reverse(a,a+n);
	priority_queue<node> q;
	vector<int> tmp(n,0);
	tmp[0]=k;
	q.push({1LL*a[0]*k,tmp});
	map<vector<int>,int> vis;
	vis[tmp]=1;
	while(x--)
	{
		auto t=q.top();
		q.pop();
		printf("%lld\n",t.v);
		for(i=0;i<n-1;i++)
		{
			if(t.cnt[i]>0)
			{
				tmp=t.cnt;
				tmp[i]--;
				tmp[i+1]++;
				if(vis.count(tmp)) continue;
				q.push({t.v-a[i]+a[i+1],tmp});
				vis[tmp]=1;
			}
		}
	}
	return 0;
}
