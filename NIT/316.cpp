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
	ll t=20,n,k,x;
	printf("%lld\n",t);
	t--;
	n=(ll)1e5;
	k=(ll)1e12;
	printf("%lld %lld\n",n,k);
	while(n--)
	{
		x=1;
		printf("%lld ",x);
	}
	puts("");
	t--;
	n=(ll)1e5;
	k=(ll)1e12;
	printf("%lld %lld\n",n,k);
	while(n--)
	{
		x=(ll)1e9;
		printf("%lld ",x);
	}
	puts("");
	while(t--)
	{
		n=(llrand()%(ll)1e5)+1;
		k=(llrand()%(ll)1e12)+1;
		printf("%lld %lld\n",n,k);
		while(n--)
		{
			x=(llrand()%(ll)1e9)+1;
			printf("%lld ",x);
		}
		puts("");
	}
	return 0;
}
*/
ll a[MAX],n,k;
bool check(ll v)
{
	ll res=0,i;
	for(i=0;i<n;i++) res+=a[i]/v;
	if(res>=k) return 1;
	return 0;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll i,s,l,r,mid,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			s+=a[i];
		}
		l=1;
		r=s/k;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid+1)) l=mid+1;
			else r=mid;
		}
		if(check(l)) printf("%lld\n",l);
		else puts("0");
	}
	return 0;
}
/*
3
3 4
15 10 8
3 5
1 1 1
3 4
100 5 10
*/