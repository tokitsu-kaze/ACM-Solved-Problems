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
int main()
{
	ll t,n,x,flag[]={1,-1};
	freopen("in.txt","w",stdout);
	srand((unsigned)time(0));
	t=1000;
	printf("%lld\n",t);
	while(t--)
	{
		n=rand()%10000+1;
		printf("%lld\n",n);
		while(n--)
		{
			x=(rand()%101)*flag[rand()%2];
			printf("%lld\n",x);
		}
	}
	return 0;
}
*/
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,s,ans,x,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		map<int,int> mp;
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
			s+=x;
		}
		if(s%2||mp[s/2]==0) puts("-1");
		else printf("%d\n",mp[s/2]);
	}
	return 0;
}

/*
2
5
1 3 -5 2 5
4
1 2 4 8

1
-1
*/