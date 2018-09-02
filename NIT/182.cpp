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
const double eps=1e-5;
const int MAX=100000+10;
const ll mod=1e6;
struct node
{
	int flag;//1:in 2:out
	int v;
	friend bool operator<(node a,node b)
	{
		if(a.v==b.v) return a.flag<b.flag;
		return a.v<b.v;
	}
}a[2*MAX];
int main()
{
	int t,n,m,sum,i,temp,ans,k,now,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		sum=0;
		while(n--)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		k=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[k].v);
			a[k++].flag=1;
			scanf("%d",&a[k].v);
			a[k++].flag=2;
		}
		sort(a,a+k);
		ans=0;
		now=0;
		flag=0;
		for(i=0;i<k;i++)
		{
			if(a[i].flag==1) now++;
			else if(a[i].flag==2) now--;
			if(now>sum)
			{
				flag=1;
				break;
			}
			ans=max(ans,now);
		}
		if(flag) puts("//(ToT)//");
		else printf("%d\n",ans);
	}
	return 0;
}