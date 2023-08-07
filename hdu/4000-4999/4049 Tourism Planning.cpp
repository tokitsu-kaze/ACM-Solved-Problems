////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-10 22:55:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4049
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:1728KB
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
const int MAX=1000000+10;
const ll mod=1e9+7;
int n,m,dp[12][1055];
int cost[12];
int v[12][12];
int rel[12][12];
int flag[12];
int cal(int x,int now)
{
	int i,j,res=0,cnt=0;
	mem(flag,0);
	for(i=0;i<n;i++)
	{
		if((1<<i)&now) flag[i]=1,cnt++;
	}
	for(i=0;i<n;i++)
	{
		if(flag[i]) res+=v[i][x];
	}
	res-=cost[x]*cnt;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(flag[i]&&flag[j]) res+=rel[i][j];
		}
	}
	return res;
}
int main()
{
	int i,j,k;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		mem(dp,-0x3f);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&cost[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&v[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&rel[i][j]);
			}
		}
		for(i=1;i<=m;i++)
		{
			for(j=0;j<(1<<n);j++)
			{
				if(i==1)
				{
					dp[i][j]=cal(i,j);
					continue;
				}
				int temp=-INF;
				for(k=0;k<(1<<n);k++)
				{
					if((j&k)==j) temp=max(temp,dp[i-1][k]);
				}
				dp[i][j]=temp+cal(i,j);
			}
		}
		int ans=-INF;
		for(i=0;i<(1<<n);i++)
		{
			ans=max(ans,dp[m][i]);
		}
		ans<=0?puts("STAY HOME"):printf("%d\n",ans);
	}
	return 0;
}