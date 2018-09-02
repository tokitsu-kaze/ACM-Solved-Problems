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
void work(int x)
{
	ll n,i;
	n=llrand()%x+1;
	printf("%lld\n",n);
	for(i=1;i<=n;i++) printf("%lld%c",llrand()%x+1," \n"[i==n]);
}
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	ll t=20,n,i;
	while(t>15) work(100),t--;
	while(t>10) work(1000),t--;
	while(t>7) work(10000),t--;
	while(t>2) work(100000),t--;
	n=100000;
	printf("%lld\n",n);
	for(i=1;i<=n;i++) printf("%d%c",1," \n"[i==n]);
	n=100000;
	printf("%lld\n",n);
	for(i=1;i<=n;i++) printf("%d%c",100000," \n"[i==n]);
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
int prime[MAX];
vector<int> p;
void init(int n)
{
	int i,j;
	mem(prime,0);
	p.clear();
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p.pb(i);
		for(j=i+i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
vector<int> res;
void work(int x)
{
	int t;
	res.clear();
	res.pb(1);
	while(x>1)
	{
		t=prime[x];
		if(!t)
		{
			res.pb(x);
			return;
		}
		while(x%t==0&&x>1) x/=t;
		res.pb(t);
	}
}
int sg[MAX];
void SG(int n)
{
	int i,j,flag[4];
	mem(sg,0);
	for(i=1;i<=n;i++)
	{
		mem(flag,0);
		work(i);
		res.pb(i);
		for(j=0;j<sz(res);j++)
		{
			flag[sg[i-res[j]]]=1;
		}
		for(j=0;;j++)
		{
			if(!flag[j])
			{
				sg[i]=j;
				break;
			}
		}
	}
}
int x[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,ans,tag,maxx;
	while(n=io.read())
	{
		ans=tag=0;
		maxx=-1;
		for(i=0;i<n;i++)
		{
			x[i]=io.read();
			assert(x[i]>=1);
			maxx=max(maxx,x[i]);
		}
		init(maxx);
		SG(maxx);
		for(i=0;i<n;i++)
		{
			ans^=sg[x[i]];
			tag+=(sg[x[i]]>1);
		}
		if(tag) ans?puts("tokitsukaze"):puts("yukikaze");
		else ans?puts("yukikaze"):puts("tokitsukaze");
	}
	return 0;
}
/*
3
4 1 1
2
4 1
2
6 4
1
3

*/