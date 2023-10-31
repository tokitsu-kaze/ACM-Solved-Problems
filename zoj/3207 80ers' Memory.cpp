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
	int n,m,cnt,i;
	char a[111];
	while(~scanf("%d",&n))
	{
		getchar();
		map<string,int> mp;
		while(n--)
		{
			gets(a);
			mp[a]=1;
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&n);
			cnt=0;
			for(i=0;i<n;i++)
			{
				scanf("%s",a);
				if(mp[a]) cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}