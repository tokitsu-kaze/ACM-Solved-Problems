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
const ll mod=1e4;
int main()
{
	int l[6],s[6],r[6],p[6],flag,i;
	while(~scanf("%d%d%d%d",&l[1],&s[1],&r[1],&p[1]))
	{
		for(i=2;i<=4;i++)
		{
			scanf("%d%d%d%d",&l[i],&s[i],&r[i],&p[i]);
		}
		flag=0;
		for(i=1;i<=4;i++)
		{
			if(p[i])
			{
				if(l[i]||s[i]||r[i]||l[i+1>4?1:i+1]||s[i+2>4?i-2:i+2]||r[i+3>4?i-1:i+3])
				{
					flag=1;
					break;
				}
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}