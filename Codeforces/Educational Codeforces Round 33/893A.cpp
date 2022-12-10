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
int main()
{
	int n,x,i,j,a,b,flag[4],tag;
	while(~scanf("%d",&n))
	{
		a=1;
		b=2;
		tag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			mem(flag,0);
			flag[a]=1;
			flag[b]=1;
			if(x==a)
			{
				for(j=1;j<=3;j++)
				{
					if(!flag[j])
					{
						b=j;
						break;
					}
				}
			}
			else if(x==b)
			{
				for(j=1;j<=3;j++)
				{
					if(!flag[j])
					{
						a=j;
						break;
					}
				}
			}
			else tag=1;
		}
		if(tag) puts("NO");
		else puts("YES");
	}
	return 0;
}