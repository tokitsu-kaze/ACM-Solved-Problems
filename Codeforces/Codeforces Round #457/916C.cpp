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
int flag[MAX];
vector<int> p;
void init()
{
	int i,j;
	mem(flag,0);
	p.clear();
	for(i=2;i<=MAX-10;i++)
	{
		if(!flag[i])
		{
			p.pb(i);
			for(j=i+i;j<=MAX-10;j+=i)
			{
				flag[j]++;
			}
		}
	}
}
int main()
{
	init();
	int n,m,i,j,ans;
	while(~scanf("%d%d",&n,&m))
	{
		ans=*lower_bound(all(p),n-1);
		printf("%d %d\n",ans,ans);
		for(i=2;i<=n-1;i++)
		{
			printf("%d %d %d\n",i-1,i,1);
			ans--;
		}
		printf("%d %d %d\n",n-1,n,ans);
		m-=n-1;
		for(i=n;i>=1;i--)
		{
			for(j=1;j<i-1;j++)
			{
				if(!m) goto end;
				m--;
				printf("%d %d %d\n",j,i,(int)1e6);
			}
		}
		end:;
	}
	return 0;
}