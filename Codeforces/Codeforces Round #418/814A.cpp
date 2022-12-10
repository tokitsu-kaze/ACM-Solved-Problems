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
int main()
{
	int n,m,a[111],b[111],i,j,flag;
	while(~scanf("%d%d",&n,&m))
	{
		mem(a,0);
		mem(b,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(b,b+m);
		for(i=m-1,j=0;i>=0,j<n;j++)
		{
			if(a[j]==0)
			{
				a[j]=b[i];
				i--;
			}
		}
		flag=0;
		for(i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
} 