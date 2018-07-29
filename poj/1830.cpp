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
int a[33][33];
int GE(int n,int m)
{  
    int i,j;  
	for(i=1,j=1;i<=n&&j<=m;j++)
	{  
		int k=i;  
		while(k<=n&&!a[k][j]) k++;
		if(a[k][j])
		{  
			for(int r=1;r<=m+1;r++)
            {
				swap(a[i][r],a[k][r]);  
			}
			for(int r=1;r<=n;r++)
			{
				if(r!=i&&a[r][j])
				{
					for(k=1;k<=m+1;k++)
					{
						a[r][k]^=a[i][k];
					}
				}
			}
			i++;
		}  
	}  
    for(j=i;j<=n;j++)
    {
		if(a[j][m+1]) return -1;
	}
	return m-i+1;  
} 
int main()
{
	int t,n,i,j,s[33],e[33];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&e[i]);
		}
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			a[i][i]=1;
			a[i][n+1]=abs(e[i]-s[i]);
		}
		while(~scanf("%d%d",&i,&j)&&i+j)
		{
			a[j][i]=1;
		}
		int res=GE(n,n);
		if(res==-1) puts("Oh,it's impossible~!!");
		else printf("%d\n",1L<<res);
	}
	return 0;
}