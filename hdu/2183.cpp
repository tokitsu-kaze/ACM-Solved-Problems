////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-09 18:46:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2183
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e4+10;
const ll mod=1e9+7;
int n,ans[33][33];
void dfs(int x,int y,int a)
{
//	cout<<x<<" "<<y<<endl;
	ans[x][y]=a;
	if(a==n*n) return;
	if(x+1>=n&&y+1>=n) dfs(x+2-n,y,a+1);
	else if(x+1>=n) dfs(0,y+1,a+1);
	else if(y+1>=n) dfs(x+1,0,a+1);
	else if(ans[x+1][y+1])
	{
		if(x+2>=n) dfs(x+2-n,y,a+1);
		else dfs(x+2,y,a+1);
	}
	else dfs(x+1,y+1,a+1);

}
int main()
{
	int t,i,j;
	while(~scanf("%d",&n)&&n)
	{
		mem(ans,0);
		dfs(n/2+1,n/2,1);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%4d",ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}