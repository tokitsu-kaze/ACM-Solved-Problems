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
const double eps=1e-10;
const int MAX=1e5+10;
const ll mod=1e9+7;
int dp[111][111][111][3];
int pos[111][3];
char a[111];
int cal(int v,int k,int x,int p)
{
	int i,res=0;
	for(i=0;i<p;i++)
	{
		if(a[i]=='V')
		{
			if(v) v--;
			else res++;
		}
		else if(a[i]=='K')
		{
			if(k) k--;
			else res++;
		}
		else
		{
			if(x) x--;
			else res++;
		}
	}
	return res;
}
int main()
{
	int n,v,k,x,i,cnt[3];
	while(~scanf("%d %s",&n,a))
	{
		mem(dp,0x3f);
		mem(cnt,0);
		mem(pos,0);
		for(i=0;i<n;i++)
		{
			if(a[i]=='V') pos[++cnt[0]][0]=i;
			else if(a[i]=='K') pos[++cnt[1]][1]=i;
			else pos[++cnt[2]][2]=i;
		}
		dp[0][0][0][0]=0;
		for(v=0;v<=cnt[0];v++)
		{
			for(k=0;k<=cnt[1];k++)
			{
				for(x=0;x<=cnt[2];x++)
				{
					if(!v&&!k&&!x)
					{
						dp[1][0][0][0]=cal(0,0,0,pos[1][0]);
						dp[0][1][0][1]=cal(0,0,0,pos[1][1]);
						dp[0][0][1][2]=cal(0,0,0,pos[1][2]);
						continue;
					}
					for(i=0;i<3;i++)
					{
						if(v<cnt[0]) dp[v+1][k][x][0]=min(dp[v+1][k][x][0],dp[v][k][x][i]+cal(v,k,x,pos[v+1][0]));
						if(i&&k<cnt[1]) dp[v][k+1][x][1]=min(dp[v][k+1][x][1],dp[v][k][x][i]+cal(v,k,x,pos[k+1][1]));
						if(x<cnt[2]) dp[v][k][x+1][2]=min(dp[v][k][x+1][2],dp[v][k][x][i]+cal(v,k,x,pos[x+1][2]));
					}
				}
			}
		}
		int ans=INF;
		for(i=0;i<3;i++)
		{
			ans=min(ans,dp[cnt[0]][cnt[1]][cnt[2]][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}