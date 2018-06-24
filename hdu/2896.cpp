////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-14 22:00:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2896
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:30768KB
//////////////////System Comment End//////////////////
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
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> ans;
struct ACM
{
	int next[MAX][128],fail[MAX],cnt[MAX];
	bool flag[MAX];
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
			int t=s[i];
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]=id;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<128;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			for(i=0;i<128;i++)
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
	void query(char *s)
	{
		int len,now,i,res;
		len=strlen(s);
		now=root;
		res=0;
		mem(flag,0);
		for(i=0;i<len;i++)
		{
			int t=s[i];
			now=next[now][t];
			int temp=now;
			while(temp&&!flag[temp])
			{
				if(cnt[temp])
				{
					ans.pb(cnt[temp]);
					flag[temp]=1;
				}
				temp=fail[temp];
			}
		}
	}
}acm;
char s[MAX];
int main()
{
	int n,i,j,q,res;
	while(~scanf("%d",&n))
	{
		acm.init();
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			acm.insert(s,i);
		}
		acm.setfail();
		res=0;
		scanf("%d",&q);
		for(i=1;i<=q;i++)
		{
			scanf("%s",s);
			ans.clear();
			acm.query(s);
			if(sz(ans))
			{
				res++;
				sort(all(ans));
				printf("web %d:",i);
				for(j=0;j<sz(ans);j++)
				{
					printf(" %d",ans[j]);
				}
				puts("");
			}
		}
		printf("total: %d\n",res);
	}
	return 0;
}