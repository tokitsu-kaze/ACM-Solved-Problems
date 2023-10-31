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
#define MAX 200000+10
using namespace std;
typedef long long ll;
int main()
{ 
	int t,m,n,i,sum1,sum2,a;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>m>>n;
			sum1=sum2=0;
			for(i=0;i<m;i++)
			{
				scanf("%d",&a);
				sum1+=a;
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&a);
				sum2+=a;
			}
			if(sum1>sum2) puts("Calem");
			else if(sum1==sum2) puts("Draw");
			else puts("Serena");
		}
	}
    return 0;
}