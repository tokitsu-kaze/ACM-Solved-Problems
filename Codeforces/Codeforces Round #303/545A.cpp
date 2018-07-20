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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int x,n,i,j,flag[111];
	while(~scanf("%d",&n))
	{
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&x);
				if(x==1) flag[i]=1;
				else if(x==2) flag[j]=1;
				else if(x==3) flag[i]=flag[j]=1;
			}
		}
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) res.pb(i);
		}
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}