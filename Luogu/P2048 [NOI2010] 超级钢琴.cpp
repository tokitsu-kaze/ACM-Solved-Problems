#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
struct RMQ
{
	#define type ll
	type v[MAX];
	int pmin(int a,int b){return v[a]<v[b]?a:b;}
	int lg[MAX],bin[22];
	int pmn[MAX][22];
	type mn[MAX][22];
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			mn[i][0]=v[i];
			pmn[i][0]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				mn[i][j]=min(mn[i][j-1],mn[i+bin[j-1]][j-1]);
				pmn[i][j]=pmin(pmn[i][j-1],pmn[i+bin[j-1]][j-1]);
			}
		}
	}
	type ask_min(int l,int r)
	{
		int t=lg[r-l+1];
		return min(mn[l][t],mn[r-bin[t]+1][t]);
	}
	int ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[l][t],pmn[r-bin[t]+1][t]);
	}
	#undef type
}rmq;
struct node
{
	int r,x,y;
	ll v;
	friend bool operator <(node a,node b)
	{
		return a.v<b.v;
	}
};
ll a[MAX],bit[MAX];
int main()
{
	int n,k,l,r,x,y,mid,i;
	ll ans;
	scanf("%d%d%d%d",&n,&k,&l,&r);
	bit[1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		bit[i+1]=bit[i]+a[i];
	}
	rmq.work(n,bit);
	priority_queue<node> q;
	for(i=1;i<=n;i++)
	{
		x=max(0,i-r)+1;
		y=i-l+1;
		if(y>=1) q.push({i,x,y,bit[i+1]-rmq.ask_min(x,y)});
	}
	ans=0;
	while(k--)
	{
		auto t=q.top();
		q.pop();
		ans+=t.v;
		mid=rmq.ask_pmin(t.x,t.y);
		if(mid-1>=t.x) q.push({t.r,t.x,mid-1,bit[t.r+1]-rmq.ask_min(t.x,mid-1)});
		if(mid+1<=t.y) q.push({t.r,mid+1,t.y,bit[t.r+1]-rmq.ask_min(mid+1,t.y)});
	}
	printf("%lld\n",ans);
	return 0;
}
