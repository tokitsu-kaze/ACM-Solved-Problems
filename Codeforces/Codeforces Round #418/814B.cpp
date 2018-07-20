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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=10000;
int main()
{
	int n,i,a[1111],b[1111],ans[1111],flag1,flag2,flag[1111];
	while(~scanf("%d",&n))
	{
		mem(a,0);
		mem(b,0);
		mem(flag,0);
		flag1=flag2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			flag[a[i]]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				flag1=i;
				break;
			}
		}
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			flag[b[i]]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				flag2=i;
				break;
			}
		}
		mem(ans,0);
		for(i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				if(a[i]==flag1)
				{
					ans[i]=flag1;
					flag1=-i;
				}
				else if(b[i]==flag2)
				{
					ans[i]=flag2;
					flag2=-i;
				}
				else if(a[i]==flag2)
				{
					ans[i]=flag2;
					flag2=-i;
				}
				else if(b[i]==flag1)
				{
					ans[i]=flag1;
					flag1=-i;
				}
				else if(flag1&&flag1==flag2)
				{
					ans[i]=flag1;
					flag1=flag2=0;
				}
				else
				{
					if(flag1>0)
					{
						ans[i]=flag1;
						flag1=-i;
					}
					else if(flag2>0)
					{
						ans[i]=flag2;
						flag2=-i;
					}
					if(flag1<=0&&flag2<=0)swap(ans[-flag1],ans[-flag2]);
				}
			}
			else ans[i]=a[i];
		}
		for(i=0;i<n;i++)
		{
			if(!i) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
		puts("");
	}
	return 0;
}