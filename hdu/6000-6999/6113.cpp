////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-12 18:44:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1764KB
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
const int MAX=1e5+10;
const ll mod=1e9+7;
char mp[111][111];
int flag[111][111],n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y;
	node(){}
	node(int a,int b):x(a),y(b){} 
};
bool check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||flag[x][y]) return 0;
	return 1;
}
void bfs(int x,int y)
{
	queue<node> q;
	node t,next;
	int i;
	q.push(node(x,y));
	flag[x][y]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y)&&mp[x][y]==mp[next.x][next.y])
			{
				 
				flag[next.x][next.y]=1;
				q.push(next);
			}
		}
	}
}
int main()
{
	int i,j,cnt1,cnt0;
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,'0');
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
			mp[i][m+1]='0';
		}
		mem(flag,0);
		cnt0=cnt1=0;
		n+=2;
		m+=2;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(!flag[i][j])
				{
					bfs(i,j);
					if(mp[i][j]=='0') cnt0++;
					else cnt1++;
				}
			}
		}
		if(cnt1!=1) puts("-1");
		else if(cnt0==1) puts("1");
		else if(cnt0==2) puts("0");
		else puts("-1");
	}
	return 0;
}
/*
3 3
111
111
111

*/