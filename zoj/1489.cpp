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
    int n,i,sum;
    while(cin>>n)
    {
		sum=2;
		if(n==1||n%2==0)
		{
			printf("2^? mod %d = 1\n",n);
			continue;
		}
		else
		{
			for(i=1;;i++)
			{
				sum%=n;
				if(sum==1)
				{
					printf("2^%d mod %d = 1\n",i,n);
					break;
				}
				else sum*=2;
			}
		}
	}
    return 0;
}