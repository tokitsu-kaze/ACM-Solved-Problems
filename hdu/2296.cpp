////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-15 19:06:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2296
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:3424KB
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
const double eps=1e-6;
const int MAX=2e3+10;
const ll mod=1e9+7;
int v[111];
struct node
{
	int v,cnt;
	char s[55];
	void init()
	{
		cnt=0;
		v=-INF;
		s[cnt]='\0';
	}
}dp[51][MAX],temp;
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
	void insert(char *s,int id)
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
		cnt[now]=v[id];
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
			for(i=0;i<26;i++)
			{
				if(next[now][i])
				{
					fail[next[now][i]]=next[fail[now]][i];
					q.push(next[now][i]);
					cnt[next[now][i]]+=cnt[fail[next[now][i]]];
				}
				else next[now][i]=next[fail[now]][i];
			}
		}
	}
	void solve(int len)
	{
		int i,j,k,res=0;
		char ans[55];
		ans[0]='\0';
		for(i=0;i<=len;i++)
		{
			for(j=0;j<tot;j++)
			{
				dp[i][j].init();
			}
		}
		dp[0][0].v=0;
		for(i=0;i<len;i++)
		{
			for(j=0;j<tot;j++)
			{
				if(dp[i][j].v==-INF) continue;
				for(k=0;k<26;k++)
				{
					temp=dp[i][j];
					temp.s[temp.cnt++]='a'+k;
					temp.s[temp.cnt]='\0';
					temp.v+=cnt[next[j][k]];
					if(temp.v>dp[i+1][next[j][k]].v)
					{
						dp[i+1][next[j][k]]=temp;
						if(dp[i+1][next[j][k]].v>res)
						{
							res=dp[i+1][next[j][k]].v;
							strcpy(ans,dp[i+1][next[j][k]].s);
						}
						else if(dp[i+1][next[j][k]].v==res)
						{
							if(strcmp(ans,dp[i+1][next[j][k]].s)>0) strcpy(ans,dp[i+1][next[j][k]].s);
						}
					}
					else if(temp.v==dp[i+1][next[j][k]].v)
					{
						if(strcmp(dp[i+1][next[j][k]].s,temp.s)>0)
						{
							dp[i+1][next[j][k]]=temp;
							if(dp[i+1][next[j][k]].v==res)
							{
								if(strcmp(ans,dp[i+1][next[j][k]].s)>0) strcpy(ans,dp[i+1][next[j][k]].s);
							}
						}
					}
				}
			}
		}
	//	cout<<res<<" ";
		puts(ans);
	}
}acm;
char s[111][22];
int main()
{
	int t,k,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&n);
		acm.init();
		for(i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
		}
		v[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			acm.insert(s[i],i);
		}
		acm.setfail();
		acm.solve(k);
	}
	return 0;
}