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
int v[MAX],flag[MAX];
int main()
{
	int n,k,i,id;
	ll ans,s;
	while(~scanf("%d%d",&n,&k))
	{
		s=ans=0;
		v[0]=0;
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			s+=v[i];
		}
		while(k--)
		{
			scanf("%d",&id);
			ans+=1LL*v[id]*(s-v[id]);
			s-=v[id];
			flag[id]=1;
		}
		v[0]=v[n];
		flag[0]=flag[n];
		for(i=1;i<=n;i++) ans+=1LL*v[i]*v[i-1]*(flag[i]^1)*(flag[i-1]^1);
		printf("%lld\n",ans);
	}
	return 0;
}