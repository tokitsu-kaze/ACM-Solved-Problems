#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	int x,y,bx,by,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int n,m,mp[22][22];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]==1) return 0;
	return 1;
}
int flag[22][22][22][22];
int bfs(int x,int y,int bx,int by)
{
	int i;
	node t,nex;
	mem(flag,0);
	priority_queue<node> q;
	q.push({x,y,bx,by,0});
	flag[x][y][bx][by]=1;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(mp[t.bx][t.by]==2) return t.v;
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(!check(nex.x,nex.y)) continue;
			if(flag[nex.x][nex.y][nex.bx][nex.by]) continue;
			if(nex.x==nex.bx&&nex.y==nex.by)
			{
				if(check(nex.bx+dir[i][0],nex.by+dir[i][1]))
				{
					nex.bx+=dir[i][0];
					nex.by+=dir[i][1];
					nex.v=t.v+1;
					flag[nex.x][nex.y][nex.bx][nex.by]=1;
					q.push(nex);
				}
			}
			else
			{
				flag[nex.x][nex.y][nex.bx][nex.by]=1;
				q.push(nex);
			}
		}
	}
	return -1;
}
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
		n=sz(grid);
		m=sz(grid[0]);
		int i,j,x,y,bx,by;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(grid[i][j]=='S')
				{
					x=i;
					y=j;
					mp[i][j]=0;
				}
				else if(grid[i][j]=='B')
				{
					bx=i;
					by=j;
					mp[i][j]=0;
				}
				else if(grid[i][j]=='.')
				{
					mp[i][j]=0;
				}
				else if(grid[i][j]=='#')
				{
					mp[i][j]=1;
				}
				else if(grid[i][j]=='T')
				{
					mp[i][j]=2;
				}
			}
		}
		return bfs(x,y,bx,by);
    }
};
