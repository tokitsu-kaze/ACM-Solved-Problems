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
const int MAX=3e4+10;
const ll mod=1e9+7;
int main()
{
	int a,b,c,d;
	int ans,i,j;
	while(~scanf("%d%d%d%d",&a,&b,&c,&d))
	{
		ans=0;
		for(i=floor(a/100.0*b+eps);i<=a;i++)
		{
			if(floor(i*100.0/a+eps)>=b+1) break;
			if(floor(i*100.0/a+eps)>=b)
			{
				for(j=floor(c/100.0*d+eps);j<=c;j++)
				{
					if(floor(j*100.0/c+eps)>=d+1) break;
					ans=max(ans,j-i);
	//				cout<<ans<<endl;
				}
			}
		}
		printf("%d\n",min(ans,c-a));
	}
	return 0;
}
/*
100 50 1 0
*/