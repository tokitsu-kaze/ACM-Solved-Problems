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
const int MAX=5e4+10;
const ll mod=1e9+7;
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
	ll k,p,i,j,ans,now,len,t;
	char temp1[22],temp2[22];
	while(~scanf("%lld%lld",&k,&p))
	{
		ans=0;
		for(i=1;i<=k;i++)
		{
			sprintf(temp1,"%lld",i);
			len=strlen(temp1);
			strcpy(temp2,temp1);
			reverse(temp2,temp2+len);
			t=pow2(10,len);
			ans+=(i*t+atol(temp2))%p;
			ans%=p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}