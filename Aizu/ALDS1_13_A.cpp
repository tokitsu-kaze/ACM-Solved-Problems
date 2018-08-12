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
const ll mod=998244353;
char mp[9][9];
int flag[9],tag,dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
int check2(int x,int y)
{
	if(x<0||y<0||x>=8||y>=8) return 0;
	return 1;
}
int check(int x,int y)
{
	int i,j,xx,yy;
	for(i=0;i<8;i++)
	{
		xx=x;
		yy=y;
		while(1)
		{
			xx+=dir[i][0];
			yy+=dir[i][1];
			if(!check2(xx,yy)) break;
			if(mp[xx][yy]=='Q') return 1;
		}
	}
	return 0;
}
void dfs(int x)
{
	int i;
	if(x==8)
	{
		tag=1;
		return ;
	}
	if(flag[x])
	{
		dfs(x+1);
		return ;
	}
	for(i=0;i<8;i++)
	{
		if(check(x,i)) continue;
		mp[x][i]='Q';
		dfs(x+1);
		if(tag) return;
		mp[x][i]='.';
	}
}
int main()
{
	int n,i,j,x,y;
	while(~scanf("%d",&n))
	{
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				mp[i][j]='.';
			}
			mp[i][8]='\0';
		}
		mem(flag,0);
		while(n--)
		{
			scanf("%d%d",&x,&y);
			mp[x][y]='Q';
			flag[x]=1;
		}
		tag=0;
		dfs(0);
		for(i=0;i<8;i++) puts(mp[i]);
	}
	return 0;
}
