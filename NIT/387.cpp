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
const int MAX=1e6+10;
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
	ll t=11,n,k,i;
	printf("%lld\n",t);
	t--;
	n=(ll)1e5;
	k=(ll)1e6;
	printf("%lld %lld\n",n,k);
	for(i=1;i<=n;i++) printf("%d%c",rand()%10+1," \n"[i==n]);
	t--;
	n=(ll)1e5;
	k=(ll)1e6;
	printf("%lld %lld\n",n,k);
	for(i=1;i<=n;i++) printf("%d%c",i," \n"[i==n]);
	while(t--)
	{
		n=llrand()%((ll)1e5)+1;
		k=(ll)1e6;
		printf("%lld %lld\n",n,k);
		for(i=1;i<=n;i++) printf("%lld%c",llrand()%((ll)1e6)+1," \n"[i==n]);
	}
	return 0;
}
*/

int cnt[MAX],flag[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,k,i,j,x,a,b,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		mem(cnt,0);
		mem(flag,0);
		vector<int> v;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(!flag[x]) v.pb(x);
			flag[x]++;
		}
		for(i=0;i<sz(v);i++)
		{
			for(j=v[i];j<=k;j+=v[i])
			{
				cnt[j]+=flag[v[i]];
			}
		}
		a=b=0;
		for(i=1;i<=k;i++) a=max(a,cnt[i]);
		for(i=1;i<=k;i++)
		{
			if(cnt[i]==a) b++;
		}
		printf("%d %d\n",a,b);
	}
	return 0; 
}
/*
*/