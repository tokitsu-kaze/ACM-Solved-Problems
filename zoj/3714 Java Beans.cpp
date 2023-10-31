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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,n,m,i,j,k,a[211],sum,temp;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			mem(a,0);
			sum=0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			} 
			for(i=0;i<n;i++)
			{
				temp=0;
				for(j=i,k=0;k<m;j++,k++)
				{
					if(j==n) j=0;
					temp+=a[j];
				}
				sum=max(sum,temp);
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}