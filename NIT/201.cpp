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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int a[5],ans[5],i;
	while(~scanf("%d",&a[0]))
	{
		for(i=1;i<4;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<4;i++)
		{
			ans[i]=-1;
		}
		sort(a,a+4);
		do
		{
			if(a[0]>2) continue;
			if(a[0]==2)
			{
				if(a[1]>3) continue;
			}
			if(a[2]>5) continue;
			for(i=0;i<4;i++)
			{
				if(a[i]>ans[i])
				{
					for(;i<4;i++)
					{
						ans[i]=a[i];
					}
				}
			}
		}while(next_permutation(a,a+4));
		if(ans[0]==-1) puts("Are you kidding me? ");
		else printf("%d%d:%d%d\n",ans[0],ans[1],ans[2],ans[3]);
	}
	return 0;
}