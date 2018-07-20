
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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
vector<pair<int,string> > v[MAX];
int main()
{
	int n,m,i,x,y;
	char s[111];
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=m;i++) v[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%s%d%d",s,&x,&y);
			v[x].pb(MP(y,s));
		} 
		for(i=1;i<=m;i++) sort(all(v[i]));
		for(i=1;i<=m;i++)
		{
			if(sz(v[i])>2&&v[i][sz(v[i])-2].fi==v[i][sz(v[i])-3].fi) puts("?");
			else cout<<v[i][sz(v[i])-1].se<<" "<<v[i][sz(v[i])-2].se<<"\n";
		}	 
	}
	return 0;
}