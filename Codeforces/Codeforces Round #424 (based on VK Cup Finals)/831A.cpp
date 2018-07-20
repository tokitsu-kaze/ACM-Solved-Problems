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
	int n,a[111],i,maxx,flag,flag2,flag3,tag[1111];
	while(~scanf("%d",&n))
	{
		maxx=0;
		mem(tag,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			maxx=max(maxx,a[i]);
			tag[a[i]]++;
		}
		flag=flag2=flag3=0;
		for(i=0;i<n;i++)
		{
			if(a[i]!=maxx);
			else
			{
				if(flag3) flag2=1;
				flag=1;
			}
			if(i&&a[i]!=maxx)
			{
				if(flag)
				{
					if(a[i]<a[i-1]);
					else flag2=1;
					flag3=1;
				}
				else
				{
					if(a[i]>a[i-1]);
					else flag2=1;
				}
			}
		}
		if(flag2) puts("NO");
		else puts("YES");
	}
	return 0;
}