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
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
int main()
{
	int ans,t,c,n,i,j,k,x[1111],y[1111],s[1111];
	while(~scanf("%d%d%d",&t,&c,&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&s[i]);
		}
		for(k=0;k<t;k++)
		{
			ans=0;
			for(i=0;i<n;i++)
			{
				if(sgn(x[i]*1.0/c+k-y[i]*1.0/s[i])==0) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}