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
const double eps=1e-4;
const int MAX=1e4+10;
const ll mod=1e9+7;
int flag[MAX];
vector<int> ans;
int main()
{
	int n,m,i,x;
	while(~scanf("%d%d",&n,&m))
	{
		ans.clear();
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			flag[x]++;
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				ans.pb(i);
			}
		}
		if((int)sz(ans)==0) puts("*");
		else
		{
			printf("%d",ans[0]);
			for(i=1;i<sz(ans);i++)
			{
				printf(" %d",ans[i]);
			}
			puts("");
		}
	}
	return 0;
}