////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-03 18:22:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3949
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1656KB
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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct Base
{
	#define type ll
	#define mx 61
	type d[mx+3],p[mx+3],cnt;
	Base()
	{
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		cnt=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
	type query_max()
	{
		int i;
		type res=0;
		for(i=mx;~i;i--)
		{
			if((res^d[i])>res) res^=d[i];
		}
		return res;
	}
	type query_min()
	{
		for(int i=0;i<=mx;i++)
		{
			if(d[i]) return d[i];
		}
		return 0;
	}
	void rebuild()
	{
		int i,j;
		cnt=0;
		for(i=mx;~i;i--)
		{
			for(j=i-1;~j;j--)
			{
				if(d[i]&(1LL<<j)) d[i]^=d[j];
			}
		}
		for(i=0;i<=mx;i++)
		{
			if(d[i]) p[cnt++]=d[i];
		}
	}
	type kth(type k)
	{
		type res=0;
		if(k>=(1LL<<cnt)) return -1;
		for(int i=mx;~i;i--)
		{
			if(k&(1LL<<i)) res^=p[i];
		}
		return res;
	}
	void merge(Base x)
	{
		for(int i=mx;~i;i--)
		{
			if(x.d[i]) insert(x.d[i]);
		}
	}
}; 
int main()
{
	int t,cas=1,n,i,flag;
	ll x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		Base lb;
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			flag|=!lb.insert(x);
		}
		lb.rebuild();
		printf("Case #%d:\n",cas++);
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld",&x);
			x-=flag;
			printf("%lld\n",lb.kth(x));
		}
	}
	return 0;
}