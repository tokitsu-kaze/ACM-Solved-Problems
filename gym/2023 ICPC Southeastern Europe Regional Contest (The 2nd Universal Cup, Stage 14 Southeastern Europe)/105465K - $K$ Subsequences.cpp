#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int mx,now,id;
	friend bool operator<(node a,node b)
	{
		if(a.now==b.now)
		{
			if(a.mx==b.mx) return a.id<b.id;
			return a.mx<b.mx;
		}
		return a.now<b.now;
	}
	friend bool operator==(node a,node b)
	{
		return a.id==b.id;
	}
};
int col[MAX];
int main()
{
	int T,n,k,x,i;
	node it;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		set<node> s;
		for(i=1;i<=k;i++) s.insert({0,0,i});
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==1) it=*s.begin();
			else it=*s.rbegin();
			s.erase(it);
			col[i]=it.id;
			it.now=max(0,it.now+x);
			it.mx=max(it.mx,it.now);
			s.insert(it);
		}
		for(i=1;i<=n;i++) printf("%d%c",col[i]," \n"[i==n]);
	}
	return 0;
}
