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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e6;
char mp[11][11];
map<pair<int,int>,int> cnt;
int res,dir[4][2]={0,1,1,0,1,1,1,-1},tag[11][11];
int check(int x,int y)
{
	if(x<0||y<0||x>=10||y>=10||tag[x][y]||mp[x][y]!='X') return 0;
	return 1;
}
void dfs(int x,int y,int vx,int vy)
{
	int i;
	tag[x][y]=1;
	if(check(x+vx,y+vy))
	{
		cnt[MP(vx,vy)]++;
		dfs(x+vx,y+vy,vx,vy);
	}
	if(check(x-vx,y-vy))
	{
		cnt[MP(-vx,-vy)]++;
		dfs(x-vx,y-vy,vx,vy);
	}
}
int main()
{
	int i,j,k,flag=0;
	for(i=0;i<10;i++)
	{
		scanf("%s",mp[i]);
	}
	for(i=0;i<10&&!flag;i++)
	{
		for(j=0;j<10&&!flag;j++)
		{
			cnt.clear();
			if(mp[i][j]=='O') continue;
			mem(tag,0);
			if(mp[i][j]=='X')
			{
				for(k=0;k<4;k++)
				{
					dfs(i,j,dir[k][0],dir[k][1]);
				}
			}
			else if(mp[i][j]=='.')
			{
				mp[i][j]='X';
				for(k=0;k<4;k++)
				{
					dfs(i,j,dir[k][0],dir[k][1]);
				}
				mp[i][j]='.';
			}
			if((cnt[MP(1,0)]+cnt[MP(-1,0)]>=4)||
			(cnt[MP(0,1)]+cnt[MP(0,-1)]>=4)||
			(cnt[MP(1,1)]+cnt[MP(-1,-1)]>=4)||
			(cnt[MP(1,-1)]+cnt[MP(-1,1)]>=4)) flag=1;
		}
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}