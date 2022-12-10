#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,x,i,j,temp,ans;
	vector<int> a,b,res;
	while(~scanf("%d%d",&n,&m))
	{
		a.clear();
		b.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(i<n/2) a.pb(x);
			else b.pb(x);
		}
		res.clear();
		for(i=0;i<(1LL<<((int)sz(a)));i++)
		{
			temp=0;
			for(j=0;j<(int)sz(a);j++)
			{
				if(i&(1LL<<j)) temp=(temp+a[j])%m;
			}
			res.pb(temp);
		}
		sort(all(res));
		ans=0;
		for(i=0;i<(1LL<<((int)sz(b)));i++)
		{
			temp=0;
			for(j=0;j<(int)sz(b);j++)
			{
				if(i&(1LL<<j)) temp=(temp+b[j])%m;
			}
			int it=lower_bound(all(res),m-temp)-res.begin();
			if(it==0) ans=max(ans,max(temp,res[(int)sz(res)-1]));
			else ans=max(ans,(temp+res[it-1])%m);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 6
4 4 3
*/