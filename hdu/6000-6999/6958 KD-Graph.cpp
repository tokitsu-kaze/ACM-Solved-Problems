#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
struct node{int x,y,w;};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,m,k,x,y,w,i,j,ans,now;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		vector<node> res;
		for(i=0;i<m;i++)
		{
			cin>>x>>y>>w;
			res.push_back({x,y,w});
		}
		if(n==k)
		{
			cout<<"0"<<"\n";
			continue;
		}
		sort(res.begin(),res.end(),[](node a,node b){
			return a.w<b.w;
		});
		dsu.init(n);
		now=n;
		ans=-1;
		for(i=j=0;i<m;)
		{
			while(j<m && res[j].w==res[i].w)
			{
				now-=dsu.merge(res[j].x,res[j].y);
				j++;
			}
			if(now==k)
			{
				ans=res[i].w;
				break;
			}
			i=j;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
