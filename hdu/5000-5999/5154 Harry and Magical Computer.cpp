////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-21 18:18:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5154
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1892KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int degree[111],n;
vector<int> mp[111];
int topsort()
{
	int i,cnt=0,x;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!degree[i]) q.push(i);
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		cnt++;
		for(i=0;i<sz(mp[x]);i++)
		{
			degree[mp[x][i]]--;
			if(degree[mp[x][i]]==0) q.push(mp[x][i]);
		}
	}
	return cnt;
}
int main()
{
	int m,i,a,b,ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			degree[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[b].pb(a);
			degree[a]++;
		}
		ans=topsort();
		if(ans!=n) puts("NO");
		else puts("YES");
	}
	return 0;
}