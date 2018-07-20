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
//typedef __int64 ll;
typedef long long ll;
int main()
{
    int n,a[1010],i;
    mem(a,0);
    a[4]=1;
    a[7]=1;
    a[47]=1;
    a[74]=1;
    a[444]=1;
    a[888]=1;
    a[447]=1;
    a[894]=1;
    a[474]=1;
    a[948]=1;
    a[477]=1;
    a[954]=1;
    a[744]=1;
    a[747]=1;
    a[774]=1;
    a[777]=1;
    for(i=1;i*4<=1000;i++)
    {
		a[i*4]=1;
	}
	for(i=1;i*7<=1000;i++)
    {
		a[i*7]=1;
	}
	for(i=1;i*47<=1000;i++)
    {
		a[i*47]=1;
	}
	for(i=1;i*74<=1000;i++)
    {
		a[i*74]=1;
	}
    while(~scanf("%d",&n))
    {
    	if(a[n]) puts("YES");
		else puts("NO");   
    }
    return 0;
}