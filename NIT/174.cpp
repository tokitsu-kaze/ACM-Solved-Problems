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
const int MAX=100000+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,m,i,ans,flag;
	while(~scanf("%d%d",&n,&m))
	{
		mem(a,0);
		flag=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i>=m+1)
			{
				if(a[i]!=a[i-1]) flag=1;
	//			cout<<i-1<<" "<<i<<endl;
			}
		}
		if(flag)
		{
			puts("No");
			continue;
		}
		ans=0;
		for(i=m-1;i>=1;i--)
		{
			if(a[i]!=a[m])
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5 3
2 3 1 1 1
1 1
1
3 1
3 1 1
*/