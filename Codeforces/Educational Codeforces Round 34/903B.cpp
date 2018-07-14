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
int main()
{
	int a,b,c,d,e;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		scanf("%d%d",&d,&e);
		vector<string> ans;
		while(d>0)
		{
			if(d-b<=0)
			{
				ans.pb("STRIKE");
				break;
			}
			else if(a-e<=0)
			{
				ans.pb("HEAL");
				a+=c;
				a-=e;
			}
			else
			{
				ans.pb("STRIKE");
				d-=b;
				a-=e;
			}
		}
		printf("%d\n",sz(ans));
		for(int i=0;i<sz(ans);i++) cout<<ans[i]<<endl;
	}
	return 0;
}