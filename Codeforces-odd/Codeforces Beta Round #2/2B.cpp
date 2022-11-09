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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=100000+10;
const ll mod=10000;
int mp[2][1111][1111];
int dp2[1111][1111],dp5[1111][1111];
struct node
{
	int i,j;
	node(){}
	node(int x,int y)
	{
		i=x;
		j=y;
	}
}pre[2][1111][1111];
int cal(int x,int y)
{
	int cnt=0;
	while(x&&x%y==0)
	{
		x/=y;
		cnt++;
	}
	return cnt;
}
int main()
{
	int n,i,j,cnt,a,x0,y0;
	char ans[3111];
	while(~scanf("%d",&n))
	{
		mem(mp,0);
		x0=-1;
		y0=-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a);
				if(a==0)
				{
					x0=i;
					y0=j;
					mp[0][i][j]=1;
					mp[1][i][j]=1;
					continue;
				}
				mp[0][i][j]=cal(a,2);
				mp[1][i][j]=cal(a,5);
			}
		}
		mem(dp2,0);
		mem(dp5,0);
		dp2[1][1]=mp[0][1][1];
		dp5[1][1]=mp[1][1][1];
		pre[0][1][1]=pre[1][1][1]=node(-1,-1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==1&&j==1) continue;
				if(i-1==0)
				{
					dp2[i][j]=dp2[i][j-1];
					pre[0][i][j]=node(i,j-1);
				}
				else if(j-1==0)
				{
					dp2[i][j]=dp2[i-1][j];
					pre[0][i][j]=node(i-1,j);
				}
				else if(dp2[i-1][j]>dp2[i][j-1])
				{
					dp2[i][j]=dp2[i][j-1];
					pre[0][i][j]=node(i,j-1);
				}
				else
				{
					dp2[i][j]=dp2[i-1][j];
					pre[0][i][j]=node(i-1,j);
				}
				dp2[i][j]+=mp[0][i][j];
				if(i-1==0)
				{
					dp5[i][j]=dp5[i][j-1];
					pre[1][i][j]=node(i,j-1);
				}
				else if(j-1==0)
				{
					dp5[i][j]=dp5[i-1][j];
					pre[1][i][j]=node(i-1,j);
				}
				else if(dp5[i-1][j]>dp5[i][j-1])
				{
					dp5[i][j]=dp5[i][j-1];
					pre[1][i][j]=node(i,j-1);
				}
				else
				{
					dp5[i][j]=dp5[i-1][j];
					pre[1][i][j]=node(i-1,j);
				}
				dp5[i][j]+=mp[1][i][j];
			}
		}
		mem(ans,0);
		int tag=(dp2[n][n]>dp5[n][n]?1:0);
		cnt=0;
		int x,y,nx,ny;
		x=n;
		y=n;
		if(min(dp2[n][n],dp5[n][n])>1&&x0!=-1)
		{
			puts("1");
			while(x>x0)
			{
				ans[cnt++]='D';
				x--;
			}
			while(y>y0)
			{
				ans[cnt++]='R';
				y--;
			}
			while(x>1)
			{
				ans[cnt++]='D';
				x--;
			}
			while(y>1)
			{
				ans[cnt++]='R';
				y--;
			}
			
		}
		else
		{
			printf("%d\n",min(dp2[n][n],dp5[n][n]));
			while(x!=-1&&y!=-1)
			{
	//			cout<<x<<" "<<y<<endl;
				nx=pre[tag][x][y].i;
				ny=pre[tag][x][y].j;
				if(nx+1==x) ans[cnt++]='D';
				else if(ny+1==y) ans[cnt++]='R';
				x=nx;
				y=ny;
			}
		}
		ans[cnt]='\0';
		reverse(ans,ans+cnt);
		puts(ans);
	}
	return 0;
}
/*
3
2 5 2
5 2 5
2 0 5
*/