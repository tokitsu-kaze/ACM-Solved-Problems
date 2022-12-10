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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
char mp[55][55],s[111];
int dir[4][2]={0,1,1,0,0,-1,-1,0},n,m;
PII be,en,now;
bool check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y]=='#') return 1;
	return 0;
}
int bfs(int *t)
{
	int d[333],i;
	for(i=0;i<4;i++)
	{
		d[t[i]+'0']=i;
	}
	now=be;
	for(i=0;i<strlen(s);i++)
	{
		now=MP(now.fi+dir[d[s[i]]][0],now.se+dir[d[s[i]]][1]);
		if(check(now.fi,now.se)) return 0;
		if(mp[now.fi][now.se]=='E') return 1;
	}
	return 0;
}
int main()
{
	int i,j,ans;
	while(~scanf("%d%d",&n,&m))
	{
		int temp[]={0,1,2,3};
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='S') be=MP(i,j);
				if(mp[i][j]=='E') en=MP(i,j);
			}
		}
		scanf("%s",s);
		ans=0;
		do
		{
			ans+=bfs(temp);
		}
		while(next_permutation(temp,temp+4));
		printf("%d\n",ans);
	}
	return 0;
}