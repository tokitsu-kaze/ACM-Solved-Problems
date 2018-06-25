////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-19 21:42:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6152
////Problem Title: 
////Run result: Accept
////Run time:1154MS
////Run memory:10520KB
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
const int MAX=3e3+10;
const ll mod=1e9+7;
bool mp[MAX][MAX];
bool check(int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if(mp[i][j]==mp[j][k]&&mp[j][k]==mp[i][k]) return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int t,n,i,j,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				scanf("%d",&a);
				mp[i][j]=mp[j][i]=a;
			}
		}
		if(check(n)) puts("Bad Team!");
		else puts("Great Team!");
	} 
	return 0;
}
