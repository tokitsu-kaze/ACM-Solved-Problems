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
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n,p,l,r,ans,len,lf,rf;
	while(~scanf("%d%d%d%d",&n,&p,&l,&r))
	{
		len=r-l+1;
		if(n==len)
		{
			puts("0");
			continue;
		}
		lf=rf=ans=0;
		if(l!=1&&len+l-1<=n) lf=1;
		if(n>r) rf=1;
		if(lf&&rf)
		{
			ans+=2;
			if(p>=l&&p<=r) ans+=min(p-l+r-l,r-p+r-l);
			else if(p<l) ans+=r-p;
			else if(p>r) ans+=p-l;
		}
		else if(lf)
		{
			if(p>=l) ans+=p-l+1;
			else ans+=l-p+1;
		}
		else if(rf)
		{
			if(p<=r) ans+=r-p+1;
			else ans+=p-r+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}