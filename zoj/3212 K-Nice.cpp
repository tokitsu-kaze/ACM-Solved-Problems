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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,i,j,a,s,k,n,m,cnt,ans[22][22];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&n,&m,&k);
			s=(n-2)*(m-2)-k;
			cnt=1;
			mem(ans,0);
			for(i=0;i<n&&s;i++)
			{
				for(j=0;j<m&&s;j++)
				{
					ans[i][j]=cnt++;
					if(j!=0&&j!=m-1) s--;
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(!j) printf("%d",ans[i][j]);
					else printf(" %d",ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}