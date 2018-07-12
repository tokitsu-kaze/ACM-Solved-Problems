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
#include <ext/hash_set>
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
const long double eps=1e-6;
const int MAX=5e3+10;
const ll mod=1e9+7;
int prime[10010];
vector<int> pp;
void init(int n)
{
	int i,j;
	mem(prime,0);
	pp.clear();
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		pp.pb(i);
		for(j=i+i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
void work(int &x)
{
	int t;
	if(x==0) return;
	for(auto i:pp)
	{
		t=i*i;
		if(abs(x)<t) return;
		while(x%t==0) x/=t;
	}
}
int ans[MAX],x[MAX],flag[MAX],a[MAX];
int main()
{  
	init(10000);
	int n,cnt,s;
	while(~scanf("%d",&n))
	{
		vector<int> res;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
			work(x[i]);
			res.pb(x[i]);
			a[i]=x[i];
		}
		sort(all(res));
		res.resize(unique(all(res))-res.begin());
		for(int i=1;i<=n;i++) x[i]=lower_bound(all(res),x[i])-res.begin();
		mem(ans,0);
		mem(flag,0);
		for(int i=1;i<=n;i++)
		{
			s=cnt=0;
			for(int j=i;j<=n;j++)
			{
				s+=(!flag[x[j]]);
				cnt|=(a[j]==0);
				flag[x[j]]=1;
				ans[s-cnt]++;
			}
			for(int j=i;j<=n;j++) flag[x[j]]=0;
		}
		ans[1]+=ans[0];
		for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
    return 0;
}