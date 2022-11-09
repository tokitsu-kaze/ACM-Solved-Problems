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
const long double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,k,i,j,flag[266],x,l;
	while(~scanf("%d%d",&n,&k))
	{
		vector<int> res;
		mem(flag,-1);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(flag[x]!=-1)
			{
				res.pb(flag[x]);
				continue;
			}
			for(j=x,l=0;l<k&&j>=0;l++,j--)
			{
				if(flag[j]!=-1)
				{
					if(x-flag[j]+1<=k)
					{
						j=flag[j]-1;
					}
					break;
				}
			}
			j++;
			res.pb(j);
			for(;j<=x;j++) flag[j]=res[sz(res)-1];
		}
		for(i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}