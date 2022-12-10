#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e4+10;
const ll mod=1e9+7;
struct node
{
	int x,y,t,id;
	double ang;
	void input()
	{
		scanf("%d%d",&x,&y);
	}
	friend bool operator <(node a,node b)
	{
		return a.ang<b.ang;
	}
}p[MAX];
int ans[MAX];
void dfs(int l,int r)
{
	if(l>r) return;
	int i,tmp;
	for(i=l+1;i<=r;i++)
	{
		if(p[i].x<p[l].x) swap(p[i],p[l]);
		else if(p[i].x==p[l].x&&p[i].y<p[l].y) swap(p[i],p[l]);
	}
	for(i=l+1;i<=r;i++)
	{
		p[i].ang=atan2(p[i].y-p[l].y,p[i].x-p[l].x);
	}
	sort(p+l+1,p+r+1);
	tmp=0;
	for(i=l;i<=r;i++)
	{
		tmp+=p[i].t;
		if(tmp) continue;
		ans[p[l].id]=p[i].id;
		ans[p[i].id]=p[l].id;
		dfs(l+1,i-1);
		dfs(i+1,r);
		return;
	}
}
int main()
{
	int i,n;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=2*n;i++)
		{
			p[i].input();
			if(i>n) p[i].t=1;
			else p[i].t=-1;
			p[i].id=i;
		}
		dfs(1,2*n);
		for(i=1;i<=n;i++) printf("%d\n",ans[i]-n);
	}
	return 0;
}