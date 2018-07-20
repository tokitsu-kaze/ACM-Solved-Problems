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
const long double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll n,k,d1,d2,flag,a,b,c,tag;
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		
		scanf("%lld%lld%lld%lld",&n,&k,&d1,&d2);
		if(n%3)
		{
			puts("no");
			continue;
		}
		flag=tag=0;
		//a<b&&b>c
		/*
		b-a=d1
		b-c=d2
		2b-a-c=d1+d2
		3b=k+d1+d2
		*/
		b=(k+d1+d2)/3;
		a=b-d1;
		c=b-d2;
		if(a+b+c==k&&a>=0&&b>=0&&c>=0&&a<=b&&b>=c&&(k+d1+d2)%3==0)
		{
			flag=0;
			flag|=(a*3>n);
			flag|=(b*3>n);
			flag|=(c*3>n);
			tag=1;
			if(!flag)
			{
				puts("yes");
				continue;
			}
		}
		//a>b&&b<c
		/*
		a-b=d1
		c-b=d2
		a-2b+c=d1+d2
		3b=k-(d1+d2)
		*/
		b=(k-d1-d2)/3;
		a=b+d1;
		c=b+d2;
		if(a+b+c==k&&a>=0&&b>=0&&c>=0&&a>=b&&b<=c&&(k-d1-d2)%3==0)
		{
			flag=0;
			flag|=(a*3>n);
			flag|=(b*3>n);
			flag|=(c*3>n);
			tag=1;
			if(!flag)
			{
				puts("yes");
				continue;
			}
		}

		//a<b&&b<c
		/*
		b-a=d1
		c-b=d2
		2b-a-c=d1-d2
		3b=d1-d2+k
		*/
		b=(d1-d2+k)/3;
		a=b-d1;
		c=b+d2;
		if(a+b+c==k&&a>=0&&b>=0&&c>=0&&a<=b&&b<=c&&(d1-d2+k)%3==0)
		{
			flag=0;
			flag|=(a*3>n);
			flag|=(b*3>n);
			flag|=(c*3>n);
			tag=1;
			if(!flag)
			{
				puts("yes");
				continue;
			}
		}
		
		//a>b&&b>c
		/*
		a-b=d1
		b-c=d2
		a-2b+c=d1-d2
		3b=k-(d1-d2)
		*/
		b=(k-(d1-d2))/3;
		a=d1+b;
		c=b-d2;
		if(a+b+c==k&&a>=0&&b>=0&&c>=0&&a>=b&&b>=c&&(k-(d1-d2))%3==0)
		{
			flag=0;
			flag|=(a*3>n);
			flag|=(b*3>n);
			flag|=(c*3>n);
			tag=1;
			if(!flag)
			{
				puts("yes");
				continue;
			}
		}
		flag|=(!tag);
		flag?puts("no"):puts("yes");
	}
	return 0;
}
/*
|a-b|=d1
|b-c|=d2
a+b+c=k;

*/