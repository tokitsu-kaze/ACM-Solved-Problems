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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
	int n,i,a,cnt;
	while(~scanf("%d",&n))
	{
		map<int,int> m;
		cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			m[a]++;
			if(m[a]==2)
			{
				m[a]=0;
				cnt++;
			}
		}
		printf("%d\n",cnt/2);
	}
    return 0;
}