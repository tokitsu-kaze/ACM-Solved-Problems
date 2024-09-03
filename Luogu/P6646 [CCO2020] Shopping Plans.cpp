#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct multiset_kth
{
	struct node
	{
		ll v;
		int x,y,z;
		friend bool operator < (node a,node b){return a.v>b.v;}
	};
	int l,r;
	vector<ll> a,ans;
	priority_queue<node> q;
	void init()
	{
		a.clear();
		ans.clear();
		while(!q.empty()) q.pop();
	}
	void add(ll x){a.push_back(x);}
	ll kth(int k)
	{
		if(k<ans.size()) return ans[k];
		while(!q.empty() && ans.size()<=k)
		{
			node t=q.top();
			q.pop();
			ans.push_back(t.v);
			if(t.z==a.size() && t.x+1==t.y && t.y+1<r) q.push({t.v+a[t.y+1],t.x+1,t.y+1,t.z});
			if(t.y+1<t.z) q.push({t.v-a[t.y]+a[t.y+1],t.x,t.y+1,t.z});
			if(t.x>=0 && t.x+1<t.y) q.push({t.v-a[t.x]+a[t.x+1],t.x-1,t.x+1,t.y});
		}
		if(k<ans.size()) return ans[k];
		return -1;
	}
	void work()
	{
		if(a.size()<l) return;
		if(l==0)
		{
			ans.push_back(0);
			if(r==0) return;
			l++;
		}
		int i;
		ll sum;
		r=min((int)a.size(),r);
		sort(a.begin(),a.end());
		sum=0;
		for(i=0;i<l;i++) sum+=a[i];
		q.push({sum,l-2,l-1,(int)a.size()});
	}
}mk[MAX];
struct node
{
	ll v;
	int x,y;
	friend bool operator < (node a,node b){return a.v>b.v;}
};
int main()
{
	int n,m,k,i,a,c,ok;
	ll sum;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++) mk[i].init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&c);
		mk[a].add(c);
	}
	vector<int> id;
	sum=0;
	ok=1;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&mk[i].l,&mk[i].r);
		if(mk[i].a.size()==0)
		{
			if(mk[i].l>0) ok=0;
			continue;
		}
		mk[i].work();
		if(mk[i].kth(0)==-1)
		{
			ok=0;
			continue;
		}
		sum+=mk[i].kth(0);
		if(mk[i].kth(1)!=-1) id.push_back(i);
	}
	if(ok==0)
	{
		while(k--) puts("-1");
		return 0;
	}
	printf("%lld\n",sum);
	if(k==1) return 0;
	k--;
	if(id.size()==0)
	{
		while(k--) puts("-1");
		return 0;
	}
	sort(id.begin(),id.end(),[&](int x,int y){
		return mk[x].kth(1)-mk[x].kth(0)<mk[y].kth(1)-mk[y].kth(0);
	});
	priority_queue<node> q;
	q.push({sum-mk[id[0]].kth(0)+mk[id[0]].kth(1),0,1});
	while(!q.empty() && k>0)
	{
		node t=q.top();
		q.pop();
		printf("%lld\n",t.v);
		k--;
		ll tmp=mk[id[t.x]].kth(t.y+1);
		if(tmp!=-1) q.push({t.v-mk[id[t.x]].kth(t.y)+tmp,t.x,t.y+1});
		if(t.x+1<id.size()) q.push({t.v-mk[id[t.x+1]].kth(0)+mk[id[t.x+1]].kth(1),t.x+1,1});
		if(t.x+1<id.size() && t.y==1) q.push({t.v-mk[id[t.x]].kth(1)
												 +mk[id[t.x]].kth(0)
												 -mk[id[t.x+1]].kth(0)
												 +mk[id[t.x+1]].kth(1),t.x+1,1});
	}
	while(k--) puts("-1");
	return 0;
}
