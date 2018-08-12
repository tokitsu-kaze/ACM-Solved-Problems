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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,a[1001],i,ave,sum,k=1;
    while(cin>>n)
    {
		if(n==0) break;
		for(i=0,ave=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ave+=a[i];
		}
		ave=ave/n;
		for(i=0,sum=0;i<n;i++)
		{
			if(a[i]<ave) sum+=ave-a[i];
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",k++,sum);
    }
    return 0;
}