#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
bool flag[MAX];
int a[MAX];
int main()
{
	int n,m,i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		mem(flag,0);
		for(i=m;i>=1;i--)
		{
			if(!flag[a[i]])
			{
				flag[a[i]]=1;
				printf("%d\n",a[i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				flag[i]=1;
				printf("%d\n",i);
			}
		}
	}
	return 0;
}