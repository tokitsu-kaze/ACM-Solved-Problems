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
const int MAX=2e5+10;
const ll mod=1e9+7;
char mp[555][555];
int n,m;
bool check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
	int i,j,k,flag,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++) scanf("%s",mp[i]);
		flag=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='W')
				{
					for(k=0;k<4;k++)
					{
						x=i+dir[k][0];
						y=j+dir[k][1];
						if(check(x,y))
						{
							if(mp[x][y]=='S') flag=1;
						}
					}
				}
			}
		}
		if(flag) puts("No");
		else
		{
			puts("Yes");
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(mp[i][j]=='.') mp[i][j]='D';
				}
				puts(mp[i]);
			}
		}
	}
	return 0;
}