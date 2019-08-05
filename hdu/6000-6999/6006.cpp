////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-12 21:58:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6006
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1764KB
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
const int MAX=1e6+10;
const ll mod=1e9+7;
vector<int> a[12],b[12],res[12];
int dp[12][1066];
int main()
{
	int t,i,j,k,w,x,y,mp[101],flag,n,m,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			a[i].clear();
			res[i].clear();
		}
		for(i=0;i<m;i++)
		{
			b[i].clear();
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			for(j=0;j<x;j++)
			{
				scanf("%d",&y);
				a[i].pb(y);
			}
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			for(j=0;j<x;j++)
			{
				scanf("%d",&y);
				b[i].pb(y);
			}
		}
		printf("Case #%d: ",cas++);
		for(i=0;i<n;i++)
		{
			for(j=0;j<(1<<m);j++)
			{
				mem(mp,0);
				for(k=0;k<m;k++)
				{
					if((1<<k)&j)
					{
						for(w=0;w<sz(b[k]);w++)
						{
							mp[b[k][w]]=1;
						}
					}
				}
				flag=0;
				for(k=0;k<sz(a[i]);k++)
				{
					if(!mp[a[i][k]])
					{
						flag=1;
						break;
					}
				}
				if(!flag) res[i].pb(j);
			}
		}
		mem(dp,0);
		int ans=0;
		for(i=0;i<sz(res[0]);i++)
		{
			dp[0][res[0][i]]=1;
			ans=max(ans,dp[0][res[0][i]]);
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<(1<<m);j++)
			{
				for(k=0;k<sz(res[i]);k++)
				{
					if((j|res[i][k])==j) dp[i][j]=max(dp[i][j],dp[i-1][j-res[i][k]]+1);
				}
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				ans=max(ans,dp[i][j]); 
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}