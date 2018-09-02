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
const int MAX=5e5+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	int cas,t;
	ll x;
	char s[111];
	mem(s,0);
	srand(time(0));
	t=rand()%100+1;
	for(cas=1;cas<=t;cas++)
	{
		sprintf(s,"%03d",cas);
		strcpy(s+strlen(s),".in");
		freopen(s,"w",stdout);
		printf("%lld\n",llrand()%(mod-7)+1);
	}
	t++;
	sprintf(s,"%03d",t);
	strcpy(s+strlen(s),".in");
	freopen(s,"w",stdout);
	printf("%lld\n",1LL*(mod-7));
	t++;
	sprintf(s,"%03d",t);
	strcpy(s+strlen(s),".in");
	freopen(s,"w",stdout);
	printf("%lld\n",0LL);
	for(cas=t+1;cas<=t+100;cas++)
	{
		sprintf(s,"%03d",cas);
		strcpy(s+strlen(s),".in");
		freopen(s,"w",stdout);
		x+=2;
		printf("%lld\n",llrand());
	}
	t++;
	sprintf(s,"%03d",245);
	strcpy(s+strlen(s),".in");
	freopen(s,"w",stdout);
	printf("%lld\n",1000000000000000000LL);
	for(x=1,cas=t+1;x<=1000000000000000000LL;cas++,x<<=1)
	{
		sprintf(s,"%03d",cas);
		strcpy(s+strlen(s),".in");
		freopen(s,"w",stdout);
		printf("%lld\n",x);
	}
	return 0;
}
*/
int main()
{
	ll x,ans;
	while(~scanf("%lld",&x))
	{
		assert(x>=0&&x<=1000000000000000000LL);
		if(x==0)
		{
			puts("1");
			continue;
		}
		ans=0;
		while(x)
		{
			x>>=1;
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}