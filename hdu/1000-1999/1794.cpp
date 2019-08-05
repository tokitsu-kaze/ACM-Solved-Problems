////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-10 19:18:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1794
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:1716KB
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
int n;
int cal(int x,int y,int r)
{
	return (min(x,n-r+1)-max(1,x-r+1)+1)*(min(y,n-r+1)-max(1,y-r+1)+1);
}
int main()
{
	int t,i,j,k,mp[33][33],m,x;
	ll ans,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		scanf("%d",&m);
		vector<int> a,res;
		while(m--)
		{
			scanf("%d",&x);
			a.pb(x);
		}
		sort(all(a));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][j]) continue;
				cnt=0;
				for(k=1;k<=n;k++)
				{
					cnt+=cal(i,j,k);
				}
				res.pb(cnt);
			}
		}
		sort(all(res));
		ans=0;
		for(i=sz(res)-1,j=sz(a)-1;~i;i--,j--) ans+=res[i]*a[j];
		printf("%lld\n",ans);
	}
	return 0;
}