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
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	ll t=10,n,m,i,j,x;
	printf("%lld\n",t+3);
	while(t--)
	{
		n=llrand()%1000+1;
		m=rand()%3+1;
		printf("%lld %lld\n",n,m);
		for(i=1;i<=n;i++) printf("%lld%c",llrand()%1000+1," \n"[i==n]);
		for(i=1;i<=n;i++) printf("%lld%c",llrand()%1000+1," \n"[i==n]);
	}
	n=MAX-10;
	m=1;
	printf("%lld %lld\n",n,m);
	for(i=1;i<=n;i++) printf("%lld%c",llrand()%(MAX-10)+1," \n"[i==n]);
	for(i=1;i<=n;i++) printf("%lld%c",llrand()%(MAX-10)+1," \n"[i==n]);
	n=MAX-10;
	m=2;
	printf("%lld %lld\n",n,m);
	for(i=1;i<=n;i++) printf("%lld%c",llrand()%(MAX-10)+1," \n"[i==n]);
	for(i=1;i<=n;i++) printf("%lld%c",llrand()%(MAX-10)+1," \n"[i==n]);
	n=MAX-10;
	m=3;
	printf("%lld %lld\n",n,m);
	for(i=1;i<=n;i++) printf("%lld%c",llrand()%(MAX-10)+1," \n"[i==n]);
	for(i=1;i<=n;i++) printf("%lld%c",llrand()%(MAX-10)+1," \n"[i==n]);
	return 0;
}
*/
/*
ll a[MAX<<3],b[MAX<<3],c[MAX<<3];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,t,i,j,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		for(i=0;i<n;i++) scanf("%lld",&b[i]);
		mem(c,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(m==1) c[i^j]=(c[i^j]+a[i]*b[j]%mod)%mod;
				else if(m==2) c[i&j]=(c[i&j]+a[i]*b[j]%mod)%mod;
				else if(m==3) c[i|j]=(c[i|j]+a[i]*b[j]%mod)%mod;
			}
		}
		printf("Case #%d\n",cas++);
		for(i=0;i<n;i++) printf("%lld%c",c[i]," \n"[i==n-1]);
	}
	return 0;
}
*/
namespace FWT
{
	ll inv2;
	const ll p=1e9+7;
	ll pow2(ll a,ll b)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res=res*a%p;
			a=a*a%p;
			b>>=1;
		}
		return res;
	}
	void fwt(ll *a,int n,int f,int v)
	{  
		for(int d=1;d<n;d<<=1)
		{
			for(int m=d<<1,i=0;i<n;i+=m)
			{
				for(int j=0;j<d;j++)
				{  
					ll x=a[i+j],y=a[i+j+d];
					if(!v)
					{
						if(f==1) a[i+j]=(x+y)%p,a[i+j+d]=(x-y+p)%p;//xor
						else if(f==2) a[i+j]=(x+y)%p;//and
						else if(f==3) a[i+j+d]=(x+y)%p;//or
					}
					else
					{
						if(f==1) a[i+j]=(x+y)*inv2%p,a[i+j+d]=(x-y+p)%p*inv2%p;//xor
						else if(f==2) a[i+j]=(x-y+p)%p;//and
						else if(f==3) a[i+j+d]=(y-x+p)%p;//or
					}
	            }
			}
		}
	}
	void XOR(ll *a,ll *b,int n)
	{
		int len;
		for(len=1;len<=n;len<<=1);
		fwt(a,len,1,0);
		fwt(b,len,1,0);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%p;
		inv2=pow2(2,p-2);
		fwt(a,len,1,1);
	}
	void AND(ll *a,ll *b,int n)
	{
		int len;
		for(len=1;len<=n;len<<=1);
		fwt(a,len,2,0);
		fwt(b,len,2,0);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%p;
		fwt(a,len,2,1);
	}
	void OR(ll *a,ll *b,int n)
	{
		int len;
		for(len=1;len<=n;len<<=1);
		fwt(a,len,3,0);
		fwt(b,len,3,0);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%p;
		fwt(a,len,3,1);
	}
};
ll a[MAX<<1],b[MAX<<1];
int main()
{
	int n,m,t,i,j,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(a,0);
		mem(b,0);
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		for(i=0;i<n;i++) scanf("%lld",&b[i]);
		if(m==1) FWT::XOR(a,b,n);
		else if(m==2) FWT::AND(a,b,n);
		else if(m==3) FWT::OR(a,b,n);
		printf("Case #%d\n",cas++);
		for(i=0;i<n;i++) printf("%lld%c",a[i]," \n"[i==n-1]);
	}
	return 0;
}
/*
4
3 1
1 2 3
1 2 3
3 2
1 2 3
1 2 3
3 3
1 2 3
1 2 3
5 1
12345 23456 34567 45678 56789
98765 87654 76543 65432 54321
*/