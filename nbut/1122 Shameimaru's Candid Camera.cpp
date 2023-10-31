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
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=(int)1e5+10;
char mp[511][511];
int dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
int main()
{
	int i,j,k,n,m,x,y,tag=0;
	while(~scanf("%d%d",&m,&n))
	{
		if(tag) puts("");
		tag=1;
		for(i=0;i<n;i++) scanf("%s",mp[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='*')
				{
					for(k=0;k<8;k++)
					{
						x=i+dir[k][0];
						y=j+dir[k][1];
						if(x<0||y<0||x>=n||y>=m) continue;
						if(mp[x][y]=='-') mp[x][y]='1';
						else if(mp[x][y]=='*');
						else mp[x][y]++;
					}
				}
			}
		}
		for(i=0;i<n;i++) puts(mp[i]);
	}
	return 0;
} 