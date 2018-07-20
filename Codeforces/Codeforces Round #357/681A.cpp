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
const int MAX=4000000;
const ll mod=1e6;
int main()
{
	int n,i,a,b,flag;
	char s[11111];
	while(~scanf("%d",&n))
	{
		flag=0;
		while(n--)
		{
			scanf("%s%d%d",s,&a,&b);
			if(a>=2400&&b-a>0) flag=1;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}