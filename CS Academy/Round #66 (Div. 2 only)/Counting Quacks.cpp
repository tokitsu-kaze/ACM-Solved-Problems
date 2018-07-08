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
const int MAX=1e6+10;
const ll mod=1e9+7;
int cnt[MAX],flag[MAX];
int main()
{
	int n,t,i,j,x,a,b;
	while(~scanf("%d%d",&n,&t))
	{
		mem(cnt,0);
		mem(flag,0);
		vector<int> v;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(!flag[x]) v.pb(x);
			flag[x]++;
		}
		for(i=0;i<sz(v);i++)
		{
			for(j=v[i];j<=t;j+=v[i])
			{
				cnt[j]+=flag[v[i]];
			}
		}
		a=b=0;
		for(i=1;i<=t;i++) a=max(a,cnt[i]);
		for(i=1;i<=t;i++)
		{
			if(cnt[i]==a) b++;
		}
		printf("%d %d\n",a,b);
	}
	return 0; 
}