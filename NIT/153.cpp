#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
struct house1
{
	int v;
	int flag;
}a[5010];
struct house2
{
	int v;
	int flag;
}b[5010];
int cmp1(house1 a,house1 b)
{
	return a.v<b.v;
}
int cmp2(house2 a,house2 b)
{
	return a.v<b.v;
}
int main()
{
	int t,n,i,j,k,l,cnt;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i].v);
				a[i].flag=i+1;
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&b[i].v);
				b[i].flag=i+1;
			}
			sort(a,a+n,cmp1);
			sort(b,b+n,cmp2);
			cnt=j=k=0;
			for(i=n-1,l=n-1;i>=k;)
			{
				if(a[i].v>b[l].v)
				{
					cnt++;
					printf("%d %d\n",a[i--].flag,b[l--].flag);
				}
				else if(a[i].v<b[l].v)
				{
					cnt--;
					printf("%d %d\n",a[k++].flag,b[l--].flag);
				}
				else if(a[i].v==b[l].v)
				{
					if(a[k].v>b[j].v)
					{
						cnt++;
						printf("%d %d\n",a[k++].flag,b[j++].flag);
					}
					else
					{
						if(a[k].v<b[l].v) cnt--;
						printf("%d %d\n",a[k++].flag,b[l--].flag);
					}
				}
			}
			printf("%d\n",cnt*200);
		}
	}
	return 0;
}