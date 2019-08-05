////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-18 21:32:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5092
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1876KB
//////////////////System Comment End//////////////////
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
int mp[111][111],dp[111][111];
PII pre[111][111];
int main()
{
	int t,cas=1,i,j,n,m,tmp,x,y,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(dp,0x3f);
		dp[0][0]=0;
		mem(pre,0);
		for(i=1;i<=n;i++)
		{
			dp[0][i]=dp[i][0]=0;
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		printf("Case %d\n",cas++);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(j>1)
				{
					tmp=dp[i-1][j-1]+mp[i][j];
					if(tmp<=dp[i][j])
					{
						dp[i][j]=tmp;
						pre[i][j]=MP(i-1,j-1);
					}
				}
				tmp=dp[i-1][j]+mp[i][j];
				if(tmp<=dp[i][j])
				{
					dp[i][j]=tmp;
					pre[i][j]=MP(i-1,j);
				}
				if(j<m)
				{
					tmp=dp[i-1][j+1]+mp[i][j];
					if(tmp<=dp[i][j])
					{
						dp[i][j]=tmp;
						pre[i][j]=MP(i-1,j+1);
					}
				}
			}
		}
		ans=INF;
		x=n;
		for(i=1;i<=m;i++)
		{
			if(dp[n][i]<=ans)
			{
				ans=dp[n][i];
				y=i;
			}
		}
		vector<int> res;
		while(x&&y)
		{
			res.pb(y);
			PII to=pre[x][y];
			x=to.fi;
			y=to.se;
		}
		reverse(all(res));
		for(i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}