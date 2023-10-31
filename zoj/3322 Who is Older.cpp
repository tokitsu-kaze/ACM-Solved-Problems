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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,y1,m1,d1,y2,m2,d2;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
			if(y1<y2) puts("javaman");
			else if(y1>y2) puts("cpcs");
			else
			{
				if(m1<m2) puts("javaman");
				else if(m1>m2) puts("cpcs");
				else
				{
					if(d1<d2) puts("javaman");
					else if(d1>d2) puts("cpcs");
					else puts("same");
				}
			}
		}
	}
	return 0;
}