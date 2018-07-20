#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
int n,m;
char mp[2020][2020];
int xx[4][3]={{1,0,1},{0,-1,-1},{-1,-1,0},{1,1,0}};  
int yy[4][3]={{0,1,1},{1,0,1},{0,-1,-1},{0,-1,-1}}; 
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
void bfs()
{
	int i,j,cnt,flag;
	PII t,nex,tmp;
	queue<PII > q;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='.') q.push(MP(i,j));
		}
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			cnt=flag=0;
			for(j=0;j<3;j++)
			{
				nex=t;
				nex.fi+=xx[i][j];
				nex.se+=yy[i][j];
				if(!check(nex.fi,nex.se)) continue;
				if(mp[nex.fi][nex.se]=='*')
				{
					tmp=nex;
					cnt++;
				}
				flag++;
			}
			if(flag==3&&cnt==1)
			{
				mp[tmp.fi][tmp.se]='.';
				q.push(tmp);
			}
		}
	}
}
int main()
{
	int i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++) scanf("%s",mp[i]);
		bfs();
		for(i=0;i<n;i++) puts(mp[i]);
	}
	return 0;
}