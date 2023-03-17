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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
int a[22][3],b[22][3],n,m;
int check1(int x,int y)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<2;j++)
		{
			if(x==b[i][j]&&y!=b[i][j^1]) return 1;
		}
	}
	return 0;
}
int check2(int x,int y,int xx,int yy)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<2;j++)
		{
			if(x==b[i][j]&&y==b[i][j^1]&&xx!=b[i][j^1]&&yy!=b[i][j]) return 1;
		}
	}
	return 0;
}
int check3(int x,int y,int xx,int yy)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			if(x==a[i][j]&&y==a[i][j^1]&xx!=a[i][j^1]&&yy!=a[i][j]) return 1;
		}
	}
	return 0;
}
int check4(int x,int y)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			if(x==a[i][j]&&y!=a[i][j^1]) return 1;
		}
	}
	return 0;
}
int main()
{
	int i,j,k,l;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<2;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		set<int> s;
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				if(check1(a[i][j],a[i][j^1])) s.insert(a[i][j]);
			}
		}
		if(sz(s)==1)
		{
			printf("%d\n",*s.begin());
			continue;
		}
		s.clear();
		for(i=0;i<m;i++)
		{
			for(j=0;j<2;j++)
			{
				if(check4(b[i][j],b[i][j^1])) s.insert(b[i][j]);
			}
		}
		if(sz(s)==1)
		{
			printf("%d\n",*s.begin());
			continue;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=0;k<2;k++)
				{
					for(l=0;l<2;l++)
					{
						if(check2(a[i][k],a[j][l],a[i][k^1],a[j][l^1]))
						{
							puts("-1");
							goto end;
						}
					}
				}
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{
				for(k=0;k<2;k++)
				{
					for(l=0;l<2;l++)
					{
						if(check3(b[i][k],b[j][l],b[i][k^1],b[j][l^1]))
						{
							puts("-1");
							goto end;
						}
					}
				}
			}
		}
		puts("0");
		end:;
	}
	return 0;
}
