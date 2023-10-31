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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int flag[MAX],a[MAX];
int main()
{
	int n,m,k,i,x,pos;
	ll v,ans,cnt;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		n++;
		mem(flag,0);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			flag[x+1]++;
		}
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			if(flag[i]) a[i]=a[i-1];
			else a[i]=i;
		}
		ans=LLINF;
		for(i=1;i<=k;i++)
		{
			scanf("%lld",&v);
			pos=1;
			cnt=1;
			while(1)
			{
				if(pos+i>=n)
				{
					ans=min(ans,cnt*v);
					break;
				}
				if(a[pos+i]==pos) break;
				pos=a[pos+i];
				cnt++;
			}
		}
		if(flag[1])
		{
			puts("-1");
			continue;
		}
		if(ans==LLINF) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}
