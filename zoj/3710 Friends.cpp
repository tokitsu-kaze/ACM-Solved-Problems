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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int flag[111];
int mp[111][111];
int main()
{
	int t,n,m,i,j,l,cnt,k,a,b,temp,s;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&n,&m,&k);
			mem(mp,0);
			for(i=0;i<m;i++)
			{
				scanf("%d%d",&a,&b);
				mp[a][b]=mp[b][a]=1;
			}
			s=0;
			mem(flag,0);
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(!mp[i][j]&&i!=j)
					{
						cnt=0;
						for(l=0;l<n;l++)
						{
							if(i!=l&&j!=l&&mp[i][l]&&mp[j][l])
							{
								cnt++;
							}
						}
						if(cnt>=k)
						{
							mp[i][j]=mp[j][i]=1;
							s++;
							i=-1;
							break;
						}
					}
				}
			}
			printf("%d\n",s);
		}
	}
	return 0;
}