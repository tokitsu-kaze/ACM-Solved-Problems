#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=(1L<<20)+10;
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
	ll i,t,n,m,a,b,maxx=1e6+1;
	freopen("in.txt","w",stdout);
	srand((unsigned)time(0));
	t=100;
	printf("%lld\n",t);
	while(t--)
	{
		n=rand()%1000+1;
		printf("%lld\n",n);
		for(i=0;i<n;i++)
		{
			printf("%lld ",llrand()%maxx);
		}
		puts("");
		m=rand()%(1000-n+1)+n;
		assert(m>=n);
		printf("%lld\n",m);
		for(i=0;i<m;i++)
		{
			printf("%lld ",llrand()%maxx);
		}
		puts("");
	}
	return 0;
}
*/
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll n,m,a[1010],b[1010],i,j,ans,t,cas=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&m);
		mem(b,0);
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
		}
		ans=LLINF;
		for(i=0;i<=m-n;i++)
		{
			ll temp=0;
			for(j=0;j<n;j++)
			{
				temp+=(a[j]-b[i+j])*(a[j]-b[i+j]);
			}
			ans=min(ans,temp);
		}
		printf("Case #%lld: %lld\n",cas++,ans);
	}
	return 0;
}
/*
100
2
1 2
4
3 4 1 2
*/