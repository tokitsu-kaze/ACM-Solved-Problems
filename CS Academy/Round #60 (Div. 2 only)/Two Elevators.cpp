#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<PII > v,vv;
int a,b;
int getres(int f,int m)
{
	int res=0,i;
	if(f)
	{
		for(i=0;i<sz(v);i++)
		{
			if(v[i].fi>=m) res++;
		}
	}
	else
	{
		for(i=0;i<sz(vv);i++)
		{
			if(vv[i].fi<=m) res++;
		}
	}
	return res;
}
int solve(int f1,int f2)
{
	int i;
	if(f1==f2)
	{
		if(f1) return getres(1,min(a,b));
		else return getres(0,max(a,b));
	}
	if(f1) return getres(1,min(a,b))+getres(0,max(a,b));
}
int main()
{
	int n,i,l,r,ans;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		v.clear();
		vv.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&l,&r);
			if(l>r) vv.pb(MP(l,r));
			else v.pb(MP(l,r));
		}
		ans=0;
		ans=max(ans,solve(0,0));
		ans=max(ans,solve(1,0));
		ans=max(ans,solve(1,1));
		printf("%d\n",ans);
	}
	return 0;
}