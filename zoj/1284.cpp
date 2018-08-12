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
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int a,i,sum,flag=0;
    while(~scanf("%d",&a))
    {
		if(a==0)
		{
			puts("END OF OUTPUT");
			break;
		}
		else if(a==1)
		{
			printf("%5d  ",a);
			printf("DEFICIENT\n");
			continue;
		}
		if(flag==0)
		{
			puts("PERFECTION OUTPUT");
			flag=1;
		}
		for(i=2,sum=1;i<=sqrt(a);i++)
		{
			if(a%i==0)
			{
				sum+=i+a/i;
			}
		}
		printf("%5d  ",a);
		if(sum<a) printf("DEFICIENT\n");
		else if(sum==a) printf("PERFECT\n");
		else if(sum>a) printf("ABUNDANT\n");
    }
    return 0;
}