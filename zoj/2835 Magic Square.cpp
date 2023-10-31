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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int n,a[11][11],i,j,sum1[11],sum2[11],sum3[2],flag,tag[1111];
	while(~scanf("%d",&n)&&n)
	{
		mem(a,0);
		mem(sum1,0);
		mem(sum2,0);
		mem(sum3,0);
		flag=0;
		for(i=0;i<n;i++)
		{
			mem(tag,0);
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				sum1[i]+=a[i][j];
				if(tag[a[i][j]]) flag=1;
				tag[a[i][j]]=1;
			}
		}
		if(flag)
		{
			puts("No");
			continue;
		}
		for(j=0;j<n;j++)
		{
			mem(tag,0);
			for(i=0;i<n;i++)
			{
				sum2[j]+=a[i][j];
				if(tag[a[i][j]]) flag=1;
				tag[a[i][j]]=1;
			}
		}
		if(flag)
		{
			puts("No");
			continue;
		}
		mem(tag,0);
		for(i=0,j=0;i<n;i++,j++)
		{
			sum3[0]+=a[i][j];
			if(tag[a[i][j]]) flag=1;
			tag[a[i][j]]=1;
		}
		if(flag)
		{
			puts("No");
			continue;
		}
		mem(tag,0);
		for(i=n-1,j=0;i>=0;i--,j++)
		{
			sum3[1]+=a[i][j];
			if(tag[a[i][j]]) flag=1;
			tag[a[i][j]]=1;
		}
		if(flag)
		{
			puts("No");
			continue;
		}
		for(i=1;i<n;i++)
		{
			if(sum1[i]!=sum1[i-1]) flag=1;
		}
		for(i=2;i<n;i++)
		{
			if(sum2[i]!=sum2[i-1]) flag=1;
		}
		if(sum3[0]!=sum3[1]) flag=1;
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
}