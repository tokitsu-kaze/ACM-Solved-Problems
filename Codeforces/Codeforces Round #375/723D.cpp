#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=998244353;
/****************************************  head  ****************************************/
struct node
{
	int x,y,v;
	node(){}
	node(int _x,int _y,int _v) :x(_x),y(_y),v(_v){}
	friend bool operator <(node a,node b){return a.v>b.v;}
};
char mp[55][55];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,k,flag[55][55];
int check(int x,int y)
{
	if(x<1||y<1||x>n||y>m||flag[x][y]) return 0;
	return 1;
}
node bfs(int x,int y)
{
	int cnt=0,i,f=0;
	node t,nex,res;
	queue<node> q;
	q.push({x,y,1});
	flag[x][y]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		res=t;
		cnt++;
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(mp[nex.x][nex.y]=='#') f=1;
			if(check(nex.x,nex.y))
			{
				if(mp[nex.x][nex.y]=='.')
				{
					flag[nex.x][nex.y]=1;
					nex.v++;
					q.push(nex);
				}
			} 
		}
	}
	if(f) return node(0,0,0);
	res.v=cnt;
	return res;
}
void bfs2(int x,int y)
{
	int i;
	node t,nex;
	queue<node> q;
	q.push({x,y,1});
	flag[x][y]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		mp[t.x][t.y]='*';
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(check(nex.x,nex.y))
			{
				if(mp[nex.x][nex.y]=='.')
				{
					flag[nex.x][nex.y]=1;
					q.push(nex);
				}
			} 
		}
	}
}
int main()
{
	int i,j,ans;
	node t;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		mem(mp,'#');
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
			mp[i][0]=mp[i][m+1]='#';
		}
		priority_queue<node> q;
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(!flag[i][j]&&mp[i][j]=='.')
				{
					t=bfs(i,j);
					if(t.v) q.push(t);
				}
			}
		}
		mem(flag,0);
		ans=0;
		while(sz(q)>k)
		{
			t=q.top();
			q.pop();
			ans+=t.v;
			bfs2(t.x,t.y);
		}
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
		{
			mp[i][m+1]='\0';
			puts(mp[i]+1);
		}
	} 
	return 0;
}