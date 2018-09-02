#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
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
int flag[MAX];
int main()
{
	ll t,n,x,k;
	freopen("in.txt","w",stdout);
	srand((unsigned)time(0));
	t=100;
	printf("%lld\n",t);
	while(t--)
	{
		mem(flag,0);
		n=(llrand()%(ll)1e5)+1;
		k=(llrand()%n)+1;
		printf("%lld %lld\n",n,k);
		while(n--)
		{
			x=(llrand()%(ll)1e6)+1;
			while(flag[x]) x=(llrand()%(ll)1e6)+1;
			printf("%lld\n",x);
			flag[x]=1;
		}
	}
	return 0;
}
*/
int a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,ans,k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n+1);
		for(i=0;i<k+1;i++)
		{
			a[++n]=(int)1e6+1;
		}
		ans=0;
		for(i=n-(k+1);i>=0;i--)
		{
			ans=max(ans,a[i+(k+1)]-a[i]-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}