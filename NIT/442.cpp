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
	srand(time(0));
	freopen("in.txt","w",stdout);
	ll t=23,n,m,l,r,i,len;
	printf("%lld\n",t);
	t--;
	n=m=MAX-10;
	printf("%lld %lld\n",n,m);
	for(i=1;i<=m;i++) puts("1 100000");
	t--;
	n=m=MAX-10;
	printf("%lld %lld\n",n,m);
	for(i=1;i<=m;i++) printf("%lld %lld\n",i,i);
	while(t--)
	{
		n=llrand()%(MAX-10);
		m=llrand()%(MAX-10);
		printf("%lld %lld\n",n,m);
		for(i=1;i<=m;i++)
		{
			len=rand()%20+1;
			l=llrand()%n+1;
			r=min(l+rand()%len,n);
			assert(r<=n);
			assert(l<=r);
			printf("%lld %lld\n",l,r);
		}
	}
	return 0;
}
*/

int bit[MAX],w[MAX];
PII a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,i,j,ans,t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(bit,0);
		mem(w,0);
		ans=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i].fi,&a[i].se);
			bit[a[i].fi]++;
			bit[a[i].se+1]--;
		}
		for(i=1;i<=n;i++)
		{
			bit[i]+=bit[i-1];
			if(bit[i]) ans++;
			if(bit[i]==1) w[i]++;
			w[i]+=w[i-1];
		}
		ans=n-ans;
		printf("Case #%d:\n",cas++);
		for(i=1;i<=m;i++) printf("%d%c",ans+w[a[i].se]-w[a[i].fi-1]," \n"[i==m]);
	}
	return 0;
}