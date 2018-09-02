#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
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
ll a[MAX];
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	ll t=10,n=(ll)1e5,i,q,pos;
	printf("%lld\n",t);
	while(t--)
	{
		q=20;
		printf("%lld %lld\n",n,q);
		for(i=0;i<n;i++)
		{
			a[i]=(llrand()%(ll)1e9)+1;
		}
		sort(a,a+n);
		for(i=0;i<n;i++) printf("%lld ",a[i]);
		puts("");
		while(q--)
		{
			pos=llrand()%n+1;
			printf("%lld\n",pos);
		}
	}
	return 0;
}
/*
int a[MAX];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i,j,n,q,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while(q--)
		{
			scanf("%d",&mid);
			for(i=mid;i<=n;i++)
			{
				a[i]/=2;
			}
			sort(a+1,a+1+n);
		}
		printf("%d",a[1]);
		for(i=2;i<=n;i++) printf(" %d",a[i]);
		puts("");
	}
	return 0;
}
*/
struct FastIO  
{  
	static const int S=200;  
	int wpos;  
	char wbuf[S];  
	FastIO():wpos(0){}  
	inline int xchar()  
	{  
		static char buf[S];  
		static int len=0,pos=0;  
		if(pos==len) pos=0,len=fread(buf,1,S,stdin);  
		if(pos==len) exit(0);  
		return buf[pos++];  
	}  
	inline int read()  
	{  
		int s=1,c=xchar(),x=0;  
		while(c<=32) c=xchar();  
		if(c=='-') s=-1,c=xchar();  
		for(;'0'<=c&&c<='9';c=xchar()) x=x*10+c-'0';  
		return x*s;  
	}  
	~FastIO()  
	{  
		if(wpos) fwrite(wbuf,1,wpos,stdout),wpos=0;  
	}  
}io;
int a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,i,j,n,q,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while(q--)
		{
			scanf("%d",&mid);
			for(i=mid;i<=n;i++)
			{
				a[i]/=2;
			}
			inplace_merge(a+1,a+mid,a+1+n);
		}
		printf("%d",a[1]);
		for(i=2;i<=n;i++) printf(" %d",a[i]);
		puts("");
	}
	return 0;
}