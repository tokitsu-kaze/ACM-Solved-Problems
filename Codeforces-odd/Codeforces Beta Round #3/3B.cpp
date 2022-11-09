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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
struct node
{
	int v,id;
}a[MAX],b[MAX];
int ans[MAX];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int main()
{
	int n,v,sum,k,i,t1,t2,t,vt,k1;
	while(~scanf("%d%d",&n,&v))
	{
		t1=t2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&t,&vt);
			if(t==1)
			{
				a[t1].id=i+1;
				a[t1++].v=vt;
			}
			else if(t==2)
			{
				b[t2].id=i+1;
				b[t2++].v=vt;
			}
		}
		if(v==1&&!t1)
		{
			puts("0");
			continue;
		}
		sort(a,a+t1,cmp);
		sort(b,b+t2,cmp);
		sum=k=0;
		mem(ans,0);
		for(i=0;i<t2;i++)
		{
			if(2<=v)
			{
				v-=2;
				sum+=b[i].v;
				ans[k++]=b[i].id;
			}
			else break;
		}
		k1=k-1;
		for(i=0;i<t1-1;i++)
		{
			if(1<=v)
			{
				v-=1;
				sum+=a[i].v;
				ans[k++]=a[i].id;
			}
			else
			{
				if(sum-b[k1].v+a[i].v+a[i+1].v>sum)
				{
					sum=sum-b[k1].v+a[i].v+a[i+1].v;
					ans[k1]=a[i].id;
					ans[k++]=a[i+1].id;
					k1--;
					i++;
				}
				else break;
			}
		}
		if(v>=1)
		{
			ans[k++]=a[t1-1].id;
			sum+=a[t1-1].v;
		}
		printf("%d\n",sum);
		for(i=0;i<k;i++)
		{
			if(!i) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
		puts("");
	}
	return 0;
}