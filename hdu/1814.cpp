////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-05 00:16:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1814
////Problem Title: 
////Run result: Accept
////Run time:982MS
////Run memory:3372KB
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e4+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
bool flag[MAX];
int cnt,s[MAX];
void init(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		mp[i].clear();
	}
	mem(flag,0);
}
bool dfs(int x)
{
	int i;
	if(flag[x^1]) return 0;
	if(flag[x]) return 1;
	s[cnt++]=x;
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		if(!dfs(mp[x][i])) return 0;
	}
	return 1;
}
void twosat(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		if(!flag[i]&&!flag[i^1])
		{
			cnt=0;
			if(!dfs(i))
			{
				while(cnt) flag[s[--cnt]]=0;
				if(!dfs(i^1))
				{
					puts("NIE");
					return;
				}
			}
		}
	}
	for(i=0;i<2*n;i+=2)
	{
		if(flag[i]) printf("%d\n",i+1);
		else printf("%d\n",i+2);
	}
}
void add(int x,int y)
{
	mp[x].pb(y);
}
int main()
{
	int n,m,i,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		init(n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			a--;
			b--;
			add(a,b^1);
			add(b,a^1);
		}
		twosat(n);
	}
	return 0;
}