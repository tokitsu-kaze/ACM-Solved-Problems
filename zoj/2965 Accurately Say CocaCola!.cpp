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
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=50000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,n,cnt,flag[811],i,j,temp;
	char a[5];
	mem(flag,0);
	for(i=7;i<=800;i++)
	{
		if(i%7==0) flag[i]=1;
		sprintf(a,"%d",i);
		for(j=0;j<strlen(a);j++)
		{
			if(a[j]=='7')
			{
				flag[i]=1;
				break;
			}
		}
	}
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			cnt=0;
			for(i=7;i<=800;i++)
			{
				if(flag[i])
				{
					if(!cnt) temp=i;
					cnt++;
					if(cnt==n)
					{
						printf("%d\n",temp);
						break;
					}
				}
				else
				{
					if(cnt) cnt=0;
				}
			}
		}
	}
	return 0;
}