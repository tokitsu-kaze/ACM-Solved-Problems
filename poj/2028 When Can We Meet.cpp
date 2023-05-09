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
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=10000;
int main()
{
	int n,m,flag[111],i,j,a,b,maxx;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		mem(flag,0);
		maxx=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			while(a--)
			{
				scanf("%d",&b);
				flag[b]++;
				maxx=max(maxx,flag[b]);
			}
		}
		if(maxx<m)
		{
			puts("0");
			continue;
		}
		for(i=0;i<101;i++)
		{
			if(flag[i]==maxx)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}