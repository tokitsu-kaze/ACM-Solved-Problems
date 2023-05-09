#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
int pos[222];
struct ACM
{
	int next[MAX][4],fail[MAX],cnt[MAX];
	int root,tot;
	int newnode()
	{
		int i;
		mem(next[tot],0);
		fail[tot]=0;
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=pos[s[i]];
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]++;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<4;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			if(cnt[fail[now]]) cnt[now]++;
			for(i=0;i<4;i++)
			{
				if(next[now][i])
				{
					fail[next[now][i]]=next[fail[now]][i];
					q.push(next[now][i]);
				}
				else next[now][i]=next[fail[now]][i];
			}
		}
	}
	int dp[MAX][MAX];
	void solve(char *s)
	{
		int i,j,k,len,ans;
		len=strlen(s);
		mem(dp,0x3f);
		dp[0][0]=0;
		for(i=0;i<len;i++)
		{
			for(j=0;j<tot;j++)
			{
				if(dp[i][j]==INF) continue;
				for(k=0;k<4;k++)
				{
					if(cnt[next[j][k]]) continue;
					dp[i+1][next[j][k]]=min(dp[i+1][next[j][k]],dp[i][j]+(pos[s[i]]!=k));
				}
			}
		}
		ans=INF;
		for(i=0;i<tot;i++) ans=min(ans,dp[len][i]);
		printf("%d\n",ans==INF?-1:ans);
	}
}acm;
char s[MAX];
int main()
{
	int n,cas=1,i;
	pos['A']=0;
	pos['T']=1;
	pos['C']=2;
	pos['G']=3;
	while(~scanf("%d",&n)&&n)
	{
		acm.init();
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			acm.insert(s);
		}
		acm.setfail();
		scanf("%s",s);
		printf("Case %d: ",cas++);
		acm.solve(s);
	}
	return 0;
}