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
int a[MAX];
int main()
{
	int n,i,temp;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		temp=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>a[temp]) temp=i;
		}
		if(a[temp]==1) a[temp]=2;
		else a[temp]=1;
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			if(!i) printf("%d",a[i]);
			else printf(" %d",a[i]);
		}
		puts("");
	}
    return 0;
}