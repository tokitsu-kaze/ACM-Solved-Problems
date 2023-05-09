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
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int a[MAX]={0};
int main()
{
	int i,j,sum;
	for(i=1;i<=10000;i++)
	{
		sum=i;
		for(j=sum;j;j/=10)
		{
			sum+=j%10;
			
		}
		a[sum]=1;
		if(!a[i]) printf("%d\n",i);
	}
    return 0;
}