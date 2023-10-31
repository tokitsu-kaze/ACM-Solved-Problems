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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{ 
	int t,n,i,a[]={0,1,4,6,4,3,1,0,1,1,4,2,1,6,0,1,2,5,1,5,1,0,1,4,1,4,4,6,0,1,1,3,2,6,1,0,1,2,2,1,2,6};
	char day[7][11]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"}; 
	for(i=1;i<42;i++)
	{
		a[i]=(a[i]+a[i-1])%7;
	}
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			printf("%s\n",day[(n/42*a[41]+a[n%42])%7]);
		}
	}
    return 0;
}