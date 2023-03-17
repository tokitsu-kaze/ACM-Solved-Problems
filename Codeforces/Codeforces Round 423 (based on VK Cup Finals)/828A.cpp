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
const int MAX=2e5+10;
const ll mod=1e6;
int main()
{
	int n,a,b,c,p,ans,i;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		ans=0;
		c=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&p);
			if(p==1)
			{
				if(a) a--;
				else if(b)
				{
					b--;
					c++;
				}
				else if(c) c--;
				else ans++;
			}
			else if(p==2)
			{
				if(b) b--;
				else ans+=2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}