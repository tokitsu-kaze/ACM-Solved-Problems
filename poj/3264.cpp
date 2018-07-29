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
using namespace std;
typedef long long ll;
typedef double LD;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int v[50010],maxx[50010][33],minn[50010][33];
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		maxx[i][0]=minn[i][0]=v[i];
		for(j=1;1<<(j-1)<=n;j++)
		{
			maxx[i][j]=0;
			minn[i][j]=INF;
		}
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			maxx[i][j]=max(maxx[i][j-1],maxx[i+t][j-1]);
			minn[i][j]=min(minn[i][j-1],minn[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	return max(maxx[l][j-1],maxx[i][j-1])-min(minn[l][j-1],minn[i][j-1]);
}
int main()
{
	int n,m,i,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		RMQ(n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",query(a,b));
		}
	}
	return 0;
}