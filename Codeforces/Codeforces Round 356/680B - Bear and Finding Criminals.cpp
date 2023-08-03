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
const int MAX=1e5+10;
const ll mod=1e6;
int main()
{
	int n,p,i,j,a[111],ans;
	while(~scanf("%d%d",&n,&p))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		ans=0;
		for(i=p,j=p;;)
		{
			if(i>=1&&j<=n)
			{
				if(a[i]==1&&a[j]==1)
				{
					if(i==j) ans++;
					else ans+=2;
				}
				j++;
				i--;
			}
			else if(i>=1)
			{
				if(a[i]) ans++;
				i--;
			}
			else if(j<=n)
			{
				if(a[j]) ans++;
				j++;
			}
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}