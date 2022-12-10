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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=10000;
int main()
{
	int a,b,c,d,x,y,t1,t2;
	while(~scanf("%d%d%d%d",&a,&b,&c,&d))
	{
		scanf("%d%d",&x,&y);
		t1=c-a;
		t2=d-b;
		if(t1%x||t2%y)
		{
			puts("NO");
			continue;
		}
		t1/=x;
		t2/=y;
		if((t1+t2)%2==0) puts("YES");
		else puts("NO");
	}
	return 0;
} 