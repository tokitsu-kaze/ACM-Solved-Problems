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
#define eps 1e-9
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,i,j,k,flag;
	char a[211],ans[211][211];
	while(~scanf("%d",&n)&&n)
	{
		getchar();
		mem(a,0);
		mem(ans,0);
		scanf("%s",a);
		flag=1;
		for(i=0,j=0,k=0;i<strlen(a);i++)
		{
			if(flag==1)
			{
				ans[j][k++]=a[i];
			}
			else if(flag==-1)
			{
				ans[j][--k]=a[i];
			}
			if((i+1)%n==0&&flag==1)
			{
				flag=-1;
				j++;
			}
			else if((i+1)%n==0&&flag==-1)
			{
				flag=1;
				j++;
			}
		}
		for(i=0;i<n;i++)
		{
			for(k=0;k<j;k++)
			{
				printf("%c",ans[k][i]);
			}
		}
		puts("");
	}
    return 0;
}