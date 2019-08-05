////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-06 16:41:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3364
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=10000;
struct Matrix
{
	int c[55][55];
};
int GE(Matrix a,int n,int m)
{  
    int i,j;  
	for(i=1,j=1;i<=n&&j<=m;j++)
	{  
		int k=i;  
		while(k<=n&&!a.c[k][j]) k++;
		if(a.c[k][j])
		{  
			for(int r=1;r<=m+1;r++)
            {
				swap(a.c[i][r],a.c[k][r]);  
			}
			for(int r=1;r<=n;r++)
			{
				if(r!=i&&a.c[r][j])
				{
					for(k=1;k<=m+1;k++)
					{
						a.c[r][k]^=a.c[i][k];
					}
				}
			}
			i++;
		}  
	}  
    for(j=i;j<=n;j++)
    {
		if(a.c[j][m+1]) return -1;
	}
	return m-i+1;  
} 
int main()
{
	int t,n,m,k,i,j,q,cas=1;
	Matrix a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(a.c,0);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&j);
				a.c[j][i]=1;
			}
		}
		printf("Case %d:\n",cas++);
		scanf("%d",&q);
		while(q--)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a.c[i][m+1]);
			}
			b=a;
			int res=GE(b,n,m);
			if(res==-1) puts("0");
			else printf("%I64d\n",(ll)1L<<res);
		}
	}
	return 0;
}