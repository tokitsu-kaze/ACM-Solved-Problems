////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-09 20:33:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2182
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1772KB
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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	int now,k,v;
	node(){}
	node(int a,int b,int c):now(a),k(b),v(c){}
};
int n,a,b,k,ans,v[111];
int flag[111][111];
void bfs()
{
	int i;
	node t;
	queue<node> q;
	q.push(node(1,k,v[1]));
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.k==0||t.now==n)
		{
			ans=max(ans,t.v);
			continue;
		}
		for(i=a;i<=b;i++)
		{
			if(t.now+i<=n)
			{
				if(t.v+v[t.now+i]>flag[t.now+i][k-1])
				{
					q.push(node(t.now+i,t.k-1,t.v+v[t.now+i]));
					flag[t.now+i][k-1]=t.v+v[t.now+i];
				}
			}
			else break;
		} 
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&a,&b,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		if(k>n) k=n;
		ans=0;
		mem(flag,0);
		bfs();
		printf("%d\n",ans);
	}
	return 0;
}