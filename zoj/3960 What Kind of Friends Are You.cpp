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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int t,k,i,j,temp,s,flag,n,q;
	char a[1111];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&q);
			map<string,int> m;
			map<string,int> ::iterator it,ans;
			scanf("%d",&k);
			for(i=0;i<k;i++)
			{
				scanf("%s",a);
				m[a]=0;
			}
			for(i=1;i<=q;i++)
			{
				scanf("%d",&k);
				for(j=0;j<k;j++)
				{
					scanf("%s",a);
					m[a]+=(1L<<i);
				}
			}
			for(i=0;i<n;i++)
			{
				s=0;
				for(j=1;j<=q;j++)
				{
					scanf("%d",&temp);
					if(temp) s+=(1L<<j);
				}
				flag=0;
				for(it=m.begin();it!=m.end();it++)
				{
					if(it->second==s)
					{
						flag++;
						ans=it;
					}
				}
				if(flag==1) cout<<ans->first<<endl;
				else puts("Let's go to the library!!");
			}
		}
	}
	return 0;
}