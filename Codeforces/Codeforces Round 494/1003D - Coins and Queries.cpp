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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=998244353;
int main()
{
	int n,q,i,x,cnt[66],ans,tmp[66],s,d;
	while(~scanf("%d%d",&n,&q))
	{
		mem(cnt,0);
		auto gao=[&](int x)
		{
			int t=0;
			while(x)
			{
				x>>=1;
				t++;
			}
			cnt[t]++;
		};
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			gao(x);
		} 
		while(q--)
		{
			scanf("%d",&x);
			s=ans=0;
			for(i=0;i<=32;i++) tmp[i]=cnt[i];
			for(i=32;~i;i--)
			{
				if(x&(1LL<<i)) s++;
				d=min(s,tmp[i+1]);
				tmp[i+1]-=d;
				s-=d;
				ans+=d;
				s*=2;
			}
			if(s) puts("-1");
			else printf("%d\n",ans);
		} 
	}
	return 0;
}
