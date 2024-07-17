#include<bits/stdc++.h>
using namespace std;
const int MAX=5e4+10;
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
struct edge{int x,y,w,c;};
vector<edge> e;
int n,k;
int ck(int addw,int f)
{
	int res;
	vector<edge> tmp(e);
	for(auto &it:tmp)
	{
		if(it.c==0) it.w+=addw;
	}
	dsu.init(n);
	sort(tmp.begin(),tmp.end(),[&](edge x,edge y){
		if(x.w==y.w) return x.c<y.c;
		else return x.w<y.w;
	});
	res=0;
	for(auto &it:tmp)
	{
		if(dsu.merge(it.x,it.y))
		{
			if(!f) res+=!it.c;
			else res+=it.w;
		}
	}
	if(!f) return res>=k;
	else return res;
}
int main()
{
	int m,i,a,b,c,d,l,r,mid;
	scanf("%d%d%d",&n,&m,&k);
	e.clear();
	while(m--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e.push_back({a+1,b+1,c,d});
	}
	l=-105;
	r=105;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1,0)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",ck(l,1)-k*l);
	return 0;
}
