////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-17 00:31:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4609
////Problem Title: 
////Run result: Accept
////Run time:920MS
////Run memory:19188KB
//////////////////System Comment End//////////////////
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
namespace FFT
{
	#define rep(i,a,b) for(int i=(a);i<=(b);i++)
	const double pi=acos(-1);
//	const int p=1e9+7;
	const int maxn=(1<<18)+10;
	struct cp
	{
		double a,b;
		cp(){}
		cp(double _x,double _y){a=_x,b=_y;}
		cp operator +(const cp &o)const{return (cp){a+o.a,b+o.b};}
		cp operator -(const cp &o)const{return (cp){a-o.a,b-o.b};}
		cp operator *(const cp &o)const{return (cp){a*o.a-b*o.b,b*o.a+a*o.b};}
		cp operator *(const double &o)const{return (cp){a*o,b*o};}
		cp operator !()const{return (cp){a,-b};}
	}x[maxn],y[maxn],z[maxn],w[maxn];
	void fft(cp x[],int k,int v)
	{
		int i,j,l;
		for(i=0,j=0;i<k;i++)
		{
			if(i>j)swap(x[i],x[j]);
			for(l=k>>1;(j^=l)<l;l>>=1);
		}
		w[0]=(cp){1,0};
		for(i=2;i<=k;i<<=1)
		{
			cp g=(cp){cos(2*pi/i),(v?-1:1)*sin(2*pi/i)};
			for(j=(i>>1);j>=0;j-=2)w[j]=w[j>>1];
			for(j=1;j<i>>1;j+=2)w[j]=w[j-1]*g;
			for(j=0;j<k;j+=i)
			{
				cp *a=x+j,*b=a+(i>>1);
				for(l=0;l<i>>1;l++)
				{
					cp o=b[l]*w[l];
					b[l]=a[l]-o;
					a[l]=a[l]+o;
				}
			}
		}
		if(v)for(i=0;i<k;i++)x[i]=(cp){x[i].a/k,x[i].b/k};
	}
    void mul(ll *a,ll *b,ll *c,int l1,int l2)
	{
		if(l1<128&&l2<128)
		{
			rep(i,0,l1+l2)a[i]=0;
			rep(i,0,l1)rep(j,0,l2)a[i+j]+=b[i]*c[j];
			return;
		}
		int K;
        for(K=1;K<=l1+l2;K<<=1);
		rep(i,0,l1)x[i]=cp(b[i],0);
		rep(i,0,l2)y[i]=cp(c[i],0);
		rep(i,l1+1,K)x[i]=cp(0,0);
		rep(i,l2+1,K)y[i]=cp(0,0);
		fft(x,K,0);fft(y,K,0);
		rep(i,0,K)z[i]=x[i]*y[i];
		fft(z,K,1);
		rep(i,0,l1+l2)a[i]=((ll)(z[i].a+0.5));
    }
};
ll cnt[MAX],res[MAX<<1],a[MAX];
int main()
{
	int n,i,t;
	ll ans,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(cnt,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		sort(a+1,a+1+n);
		FFT::mul(res,cnt,cnt,a[n],a[n]);
		for(i=1;i<=a[n];i++)
		{
			res[i*2]-=cnt[i];
		}
		for(i=1;i<=a[n]*2;i++)
		{
			res[i]/=2;
			res[i]+=res[i-1];
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=res[a[n]*2]-res[a[i]];
			ans-=1LL*(n-i)*(i-1);
			ans-=n-1;
			ans-=1LL*(n-i)*(n-i-1)/2;
		}
		s=1LL*n*(n-1)*(n-2)/6;
		printf("%.7lf\n",ans*1.0/s);
	}
	return 0;
}
