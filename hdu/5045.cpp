////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-13 23:13:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5045
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:18320KB
//////////////////System Comment End//////////////////
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+7;
double mp[12][1033],dp[1002][11][1026];
int main()
{
	int t,n,m,cas=1,i,j,k,l;
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(k=0;k<=m/n+1;k++)
		{
			mem(dp[k],0);
		}
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%lf",&mp[i][j]);
			}
		}
		ans=0;
		for(k=0;k<m/n+(m%n?1:0);k++)
		{
			double res=0;
			for(i=1;i<=n;i++)
			{
				for(j=0;j<(1<<n);j++)
				{
					for(l=0;l<(min(n,m-n*k));l++)
					{
//						cout<<k<<" "<<i<<" "<<j<<" "<<l+n*k<<endl;
						if(!(j&(1<<l)))
						{
							dp[k][i][j|(1<<l)]=max(dp[k][i][j|(1<<l)],dp[k][i-1][j]+mp[i][l+n*k]);
							res=max(res,dp[k][i][j|(1<<l)]);
						}
					}
					dp[k][i][j]=max(dp[k][i][j],dp[k][i-1][j]);
					res=max(res,dp[k][i][j]);
				}
			}
//			cout<<res<<endl;
			ans+=res;
		}
		printf("Case #%d: %.5lf\n",cas++,ans);
	}
	return 0;
}
/*
100
3 5
0.6 0.3 0.4 0.7 0.3
0.3 0.1 0.9 0.6 0.1
0.3 0.7 0.9 0.9 0.1
*/