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
const ll mod=1e6;
int main()
{
	int t,s,x;
	while(~scanf("%d%d%d",&t,&s,&x))
	{
		if(x-t==1||x<t) puts("NO");
		else if((x-t)%s==0||(x-t)%s==1) puts("YES");
		else puts("NO");
	}
	return 0;
}