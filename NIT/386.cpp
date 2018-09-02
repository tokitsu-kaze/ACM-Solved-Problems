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
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
ll a[MAX],b[MAX];
void out(ll n)
{
	ll i;
	for(i=1;i<=n;i++) assert(a[i]<=(ll)1e9),printf("%lld%c",a[i]," \n"[i==n]);
	for(i=1;i<=n;i++) assert(b[i]<=(ll)1e9),printf("%lld%c",b[i]," \n"[i==n]);
}
int main()
{
	srand(time(0));
	freopen("in.txt","w",stdout);
	ll t=33,ans,n,i,f,k;
	printf("%lld\n",t);
	t--;
	n=(ll)1e5;
	printf("%lld\n",n);
	for(i=1;i<n;i++) a[i]=b[i]=llrand()%(mod-7);
	a[n]=b[n]=mod-7;
	out(n);
	while(t--)
	{
		f=rand()%5;
		n=llrand()%((ll)1e5)+1;
		printf("%lld\n",n);
		if(!f)
		{
			for(i=1;i<=n;i++) a[i]=llrand()%(mod-7);
			for(i=1;i<=n;i++) b[i]=llrand()%(mod-7);
		}
		else if(f&1)
		{
			ans=llrand()%((MAX-10)/10)+1;
			k=rand()+2;
			for(i=1;i<=n;i++) b[i]=rand();
			for(i=1;i<=n;i++) a[i]=ans*k+b[i];
		}
		else
		{
			ans=llrand()%(mod-7)+1;
			for(i=1;i<=n;i++) a[i]=llrand()%(mod-7);
			for(i=1;i<=n;i++) b[i]=a[i]%ans;
		}
		out(n);
	}
	return 0;
}
*/

int a[MAX],b[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,g,n,maxx,ans,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		g=0;
		maxx=0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&b[i]),maxx=max(maxx,b[i]);
		if(maxx==0)
		{
			puts("1");
			goto end;
		}
		for(i=0;i<n;i++)
		{
			g=__gcd(g,a[i]-b[i]);
			if(b[i]>a[i])
			{
				puts("-1");
				goto end;
			}
		}
		if(g==0) g=maxx+1;
		for(i=0;i<n;i++)
		{
			if(a[i]%g!=b[i])
			{
				puts("-1");
				goto end;
			}
		}
		ans=INF;
		for(i=1;i<=sqrt(g);i++)
		{
			if(g%i==0)
			{
				if(i>maxx) ans=min(ans,i);
				if(g/i>maxx) ans=min(ans,g/i);
			}
		}
		printf("%d\n",ans);
		end:;
	}
	return 0;
}