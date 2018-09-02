#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
char mp[55][55];
int flag[55][55];
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
int bfs(int x,int y)
{
	PII t,nex;
	int i;
	queue<PII > q;
	mem(flag,0);
	q.push(MP(x,y));
	flag[x][y]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(mp[t.fi][t.se]=='E') return 1;
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.fi+=dir[i][0];
			nex.se+=dir[i][1];
			if(check(nex.fi,nex.se))
			{
				if(mp[nex.fi][nex.se]=='*') continue;
				if(flag[nex.fi][nex.se]) continue;
				flag[nex.fi][nex.se]=1;
				q.push(nex);
			}
		}
	}
	return 0;
}
int main()
{
	int t,i,j,sx,sy;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='S') sx=i,sy=j;
			}
		}
		bfs(sx,sy)?puts("YES"):puts("NO");
	}
	return 0;
}