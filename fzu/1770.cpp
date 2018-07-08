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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100+10;
const ll mod=20090717;
int res[(1<<10)+10];
struct ACM
{
	int next[MAX][26],fail[MAX],cnt[MAX];
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
	void insert(char *s,int v)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=s[i]-'a';
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]|=v;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<26;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			cnt[now]|=cnt[fail[now]];
			for(i=0;i<26;i++)
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
	int dp[27][MAX][(1<<10)+5];
	void solve(int len,int x,int m)
	{
		int i,j,k,f;
		for(i=0;i<=len;i++)
		{
			for(j=0;j<tot;j++)
			{
				for(k=0;k<(1<<m);k++)
				{
					dp[i][j][k]=0;
				}
			}
		}
		dp[0][0][0]=1;
		for(i=0;i<len;i++)
		{
			for(j=0;j<tot;j++)
			{
				for(k=0;k<(1<<m);k++)
				{
					if(dp[i][j][k]==0) continue;
					for(f=0;f<26;f++)
					{
						dp[i+1][next[j][f]][k|cnt[next[j][f]]]+=dp[i][j][k];
						dp[i+1][next[j][f]][k|cnt[next[j][f]]]%=mod;
					}
				}
			}
		}
		int ans=0;
		for(k=0;k<tot;k++)
		{
			for(i=0;i<(1<<m);i++)
			{
				if(res[i]>=x) ans=(ans+dp[len][k][i])%mod;
			}
		}
		printf("%d\n",ans);
	}
}acm;
int main()
{
	int n,m,k,i,j;
	char s[12];
	for(i=0;i<(1<<10);i++)
	{
		res[i]=0;
		for(j=0;j<10;j++)
		{
			if((1<<j)&i) res[i]++;
		}
	}
	while(~scanf("%d%d%d",&n,&m,&k)&&n+m+k)
	{
		acm.init();
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			acm.insert(s,1<<i);
		}
		acm.setfail();
		acm.solve(n,k,m);
	}
	return 0;
}