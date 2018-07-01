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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=5e5+10;
const ll mod=998244353;
int mp[55][55];
int m,k;
const int n=4;
set<int> s;
struct node{int id,x,y;};
vector<node> res;
PII findpos()
{
	int i,j;
	for(i=2;i<=3;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!mp[i][j]) return MP(i,j);
		}
	}
	return MP(-1,-1);
}

void move(PII x)
{
	int i,j;
	i=x.fi;
	if(i==2)
	{
		for(j=x.se;j<m;j++)//<-
		{
			if(mp[i][j+1]) res.pb({mp[i][j+1],i,j});
			swap(mp[i][j],mp[i][j+1]);
		}
		if(mp[3][m]) res.pb({mp[3][m],i,m});//up
		swap(mp[2][m],mp[3][m]);
		i=3;
		for(j=m;j>1;j--)//->
		{
			if(mp[i][j-1]) res.pb({mp[i][j-1],i,j});
			swap(mp[i][j],mp[i][j-1]);
		}
		if(x.se!=1)
		{
			if(mp[2][1]) res.pb({mp[2][1],3,1});//dwon
			swap(mp[3][1],mp[2][1]);
		}
		i=2;
		for(j=1;j<x.se-1;j++)
		{
			if(mp[i][j+1]) res.pb({mp[i][j+1],i,j});
			swap(mp[i][j],mp[i][j+1]);
		}
	}
	else
	{
		for(j=x.se;j>1;j--)//->
		{
			if(mp[i][j-1]) res.pb({mp[i][j-1],i,j});
			swap(mp[i][j],mp[i][j-1]);
		}
		if(mp[2][1]) res.pb({mp[2][1],3,1});//dwon
		swap(mp[3][1],mp[2][1]);
		i=2;
		for(j=1;j<m;j++)//<-
		{
			if(mp[i][j+1]) res.pb({mp[i][j+1],i,j});
			swap(mp[i][j],mp[i][j+1]);
		}
		if(x.se!=m)
		{
			if(mp[3][m]) res.pb({mp[3][m],i,m});//up
			swap(mp[2][m],mp[3][m]);
		}
		i=3;
		for(j=m;j>x.se+1;j--)
		{
			if(mp[i][j-1]) res.pb({mp[i][j-1],i,j});
			swap(mp[i][j],mp[i][j-1]);
		}
	}
}
void gao()
{
	int j;
	for(j=1;j<=m;j++)
	{
		if(mp[2][j]&&mp[2][j]==mp[1][j])
		{
			mp[2][j]=0;
			res.pb({mp[1][j],1,j});
			s.insert(mp[1][j]);
		}
	}
	for(j=1;j<=m;j++)
	{
		if(mp[3][j]&&mp[3][j]==mp[4][j])
		{
			mp[3][j]=0;
			res.pb({mp[4][j],4,j});
			s.insert(mp[4][j]);
		}
	}
}
int main()
{
	int i,j,f;
	while(~scanf("%d%d",&m,&k))
	{
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		s.clear();
		res.clear();
		gao();
		PII pre=findpos();
		if(pre==MP(-1,-1))
		{
			puts("-1");
			continue;
		}
		if(pre.fi==2) f=-1;
		else f=1;
		while(sz(s)<k)
		{
	/*		puts("*****");
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					printf("%d ",mp[i][j]);
				}
				puts("");
			}*/
			move(pre);
			gao();
			pre.se+=f;
			if(pre.se==0||pre.se==m+1)
			{
				pre.se=(pre.se==0?1:m);
				f*=-1;
				pre.fi^=1;
			}
		}
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++) printf("%d %d %d\n",res[i].id,res[i].x,res[i].y);
	}
	return 0;
}
/*
4 5
1 2 3 4
7 1 2 3
4 5 6 0
5 6 7 0
*/