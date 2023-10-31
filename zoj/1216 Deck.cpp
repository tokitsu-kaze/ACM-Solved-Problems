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
	int n,i;
	double sum;
	puts("# Cards  Overhang");
    while(cin>>n)
    {
		for(i=1,sum=0;i<=n;i++)
		{
			sum+=1.0/(2*i);
		}
		printf("%5d %9.3f\n",n,sum);
    }
    return 0;
}