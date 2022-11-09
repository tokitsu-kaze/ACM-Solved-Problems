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
const int MAX=200000+10;
const ll mod=10000;
int main()
{
	int n,m,r[111],c[111],mp[111][111],s,i,j,ans;
	while(~scanf("%d%d",&n,&m))
	{
		s=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
				s+=mp[i][j];
			}
		}
		mem(r,0);
		mem(c,0);
		ans=0;
		if(n<m)
		{
			for(i=1;i<=n;i++)
			{
				int temp=INF;
				for(j=1;j<=m;j++)
				{
					temp=min(temp,mp[i][j]);
				}
				for(j=1;j<=m;j++)
				{
					mp[i][j]-=temp;
					s-=temp;
				}
				r[i]=temp;
				ans+=temp;
			}
			for(i=1;i<=m;i++)
			{
				int temp=INF;
				for(j=1;j<=n;j++)
				{
					temp=min(temp,mp[j][i]);
				}
				for(j=1;j<=n;j++)
				{
					mp[j][i]-=temp;
					s-=temp;
				}
				c[i]=temp;
				ans+=temp; 
			}
		}
		else
		{
			for(i=1;i<=m;i++)
			{
				int temp=INF;
				for(j=1;j<=n;j++)
				{
					temp=min(temp,mp[j][i]);
				}
				for(j=1;j<=n;j++)
				{
					mp[j][i]-=temp;
					s-=temp;
				}
				c[i]=temp;
				ans+=temp; 
			}
			for(i=1;i<=n;i++)
			{
				int temp=INF;
				for(j=1;j<=m;j++)
				{
					temp=min(temp,mp[i][j]);
				}
				for(j=1;j<=m;j++)
				{
					mp[i][j]-=temp;
					s-=temp;
				}
				r[i]=temp;
				ans+=temp;
			}
		}
		if(s!=0) puts("-1");
		else
		{
			printf("%d\n",ans);
			for(i=1;i<=n;i++)
			{
				while(r[i]--)
				{
					printf("row %d\n",i);
				}
			}
			for(i=1;i<=m;i++)
			{
				while(c[i]--)
				{
					printf("col %d\n",i);
				}
			}
		}
	}
	return 0;
}