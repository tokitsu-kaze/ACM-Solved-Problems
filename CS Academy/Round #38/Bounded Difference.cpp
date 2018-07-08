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
const int MAX=1e5+10;
const ll mod=1e9+7;
int x[MAX],n,k;
int check(int i)
{
	int res=0;
	if(i>1)
	{
		if(abs(x[i]-x[i-1])>k) res|=1;
	}
	if(i<n) 
	{
		if(abs(x[i]-x[i+1])>k) res|=1;
	}
	return res;
}
int main()
{
	int i,j,c,it;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			if(check(i)) res.pb(i);
		}
		if(sz(res)==0) puts("0");
		else if(sz(res)>6) puts("-1");
		else
		{
			for(i=0;i<sz(res);i++)
			{
				for(j=1;j<=n;j++)
				{
					if(res[i]==j) continue;
					swap(x[j],x[res[i]]);
					c=0;
					c|=check(j);
					for(it=0;it<sz(res);it++)
					{
						c|=check(res[it]);
					}
					if(!c)
					{
						printf("%d %d\n",res[i],j);
						goto end;
					}
					swap(x[j],x[res[i]]);
				}
			}
			puts("-1");
			end:;
		}
	}
	return 0;
}