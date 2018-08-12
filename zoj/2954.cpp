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
	int t,n,m,l,r,temp,ans,i;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			stack<int> a,b,c;
			for(i=n;i>=1;i--)
			{
				a.push(i);
			}
			ans=0;
			for(i=1;i<=m;i++)
			{
				scanf("%d%d",&l,&r);
				if(ans) continue;
				if(l==1)
				{
					temp=a.top();
					a.pop();
				}
				else if(l==2)
				{
					temp=b.top();
					b.pop();
				}
				else if(l==3)
				{
					temp=c.top();
					c.pop();
				}
				if(r==1)
				{
					if(a.empty()||temp<a.top()) a.push(temp);
					else ans=-i;
				}
				else if(r==2)
				{
					if(b.empty()||temp<b.top()) b.push(temp);
					else ans=-i;
				}
				else if(r==3)
				{
					if(c.empty()||temp<c.top()) c.push(temp);
					else ans=-i;
				}
				if(c.size()==n) ans=i;
			}
			printf("%d\n",ans);
		}
	} 
	return 0;
}