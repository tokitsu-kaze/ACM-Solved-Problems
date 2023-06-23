#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e4+10;
struct Disjoint_Set_Union
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}da,db;
struct node{int x,y,w;};
int to[MAX];
int main()
{
	int n,m,i,a,b,c,ans;
	scanf("%d%d",&n,&m);
	da.init(n);
	db.init(n);
	for(i=1;i<=n;i++) to[i]=0;
	vector<node> e;
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		e.push_back({a,b,c});
	}
	sort(e.begin(),e.end(),[&](node x,node y){
		return x.w>y.w;
	});
	ans=0;
	for(auto &it:e)
	{
		if(da.find(it.x)==da.find(it.y)||
		   db.find(it.x)==db.find(it.y))
		{
			ans=it.w;
			break;
		}
		if(to[it.x]) db.merge(to[it.x],it.y);
		if(to[it.y]) db.merge(it.x,to[it.y]);
		to[it.x]=it.y;
		to[it.y]=it.x;
	}
	printf("%d\n",ans);
	return 0;
}
