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
int mp[511][511];
int path[511][2];
int main()
{
	int t,n,m,i,cnt;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			mem(mp,0);
			mem(path,0);
			for(i=0;i<m;i++)
			{
				scanf("%d",&path[i][0]);
			}
			for(i=0;i<m;i++)
			{
				scanf("%d",&path[i][1]);
			}
			cnt=0;
			for(i=0;i<m;i++)
			{
				if(!mp[path[i][0]][path[i][1]])
				{
					cnt++;
					mp[path[i][0]][path[i][1]]=1;
					mp[path[i][1]][path[i][0]]=1;
				}
			}
			printf("%.3lf\n",cnt*1.0/n);
		}
	}
	return 0;
}