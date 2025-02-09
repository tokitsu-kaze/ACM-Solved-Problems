#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e5+10;
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
struct node{int a,b,c;};
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	dsu.init(n);
	vector<node> tmp,res;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(!dsu.merge(a,b)) tmp.push_back({a,b,i});
	}
	set<int> s;
	for(i=1;i<=n;i++) s.insert(dsu.find(i));
	if(s.size()==1) return 0*puts("0");
	for(auto &it:tmp)
	{
		if(s.size()==1) break;
		if(dsu.merge(it.a,*s.begin()))
		{
			res.push_back({it.c,it.b,*s.begin()});
			s.erase(s.begin());
		}
		else if(dsu.merge(it.b,*s.begin()))
		{
			res.push_back({it.c,it.a,*s.begin()});
			s.erase(s.begin());
		}
		else if(dsu.merge(it.a,*s.rbegin()))
		{
			res.push_back({it.c,it.b,*s.rbegin()});
			s.erase(*s.rbegin());
		}
		else if(dsu.merge(it.b,*s.rbegin()))
		{
			res.push_back({it.c,it.a,*s.rbegin()});
			s.erase(*s.rbegin());
		}
	}
	printf("%d\n",res.size());
	for(auto &it:res) printf("%d %d %d\n",it.a,it.b,it.c);
	return 0;
}
