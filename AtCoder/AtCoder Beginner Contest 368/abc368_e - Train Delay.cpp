#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int x,t,id,f;};
int x[MAX],mx[MAX];
int main()
{
	int n,m,i,a,b,s,t,id;
	memset(x,0,sizeof x);
	scanf("%d%d%d",&n,&m,&x[1]);
	vector<node> res;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&s,&t);
		res.push_back({a,s,i,0});
		res.push_back({b,t,i,1});
	}
	sort(res.begin(),res.end(),[](node x,node y){
		if(x.t==y.t) return x.f>y.f;
		return x.t<y.t;
	});
	memset(mx,0,sizeof mx);
	for(auto &it:res)
	{
		if(it.f==0)
		{
			if(it.id>1) x[it.id]=max(0,mx[it.x]-it.t);
		}
		else
		{
			mx[it.x]=max(mx[it.x],it.t+x[it.id]);
		}
	}
	for(i=2;i<=m;i++) printf("%d%c",x[i]," \n"[i==m]);
	return 0;
}
/*
ti+xi<=sj+xj
ti+xi-sj<=xj
xj=max{ti+xi}-sj  ti<=sj

3 5 5
1 2 15 30
2 3 30 40
2 3 30 50
3 1 50 60
3 1 30 60
*/
