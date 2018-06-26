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
ll mp[111][2];
ll solve(ll a,ll b,ll c)
{
	double x,y,z;
	x=(mp[a][0]-mp[c][0])*(mp[b][0]-mp[c][0])+(mp[a][1]-mp[c][1])*(mp[b][1]-mp[c][1]);
	y=sqrt((mp[a][0]-mp[c][0])*(mp[a][0]-mp[c][0])+(mp[a][1]-mp[c][1])*(mp[a][1]-mp[c][1]));
	z=sqrt((mp[b][0]-mp[c][0])*(mp[b][0]-mp[c][0])+(mp[b][1]-mp[c][1])*(mp[b][1]-mp[c][1]));
	if(x/(y*z)>0&&x/(y*z)<1) return 1;
	else return 0;
}
int main()
{
	ll t,i,j,k,n,x,y,s,cnt;
	while(~scanf("%I64d",&t))
	{
		while(t--)
		{
			scanf("%I64d",&n);
			map<ll,ll> m;
			mem(mp,0);
			s=0;
			for(i=0;i<n;i++)
			{
				scanf("%I64d%I64d",&x,&y);
				if(m[x]&&m[y]) continue;
				mp[s][0]=x;
				mp[s][1]=y;
				s++;
				m[x]=1;
				m[y]=1;
			}
			cnt=0;
			for(i=0;i<s-2;i++)
			{
				for(j=i+1;j<s-1;j++)
				{
					for(k=j+1;k<s;k++)
					{
						if(solve(i,j,k)&&solve(j,k,i)&&solve(k,i,j)) cnt++;
					}
				}
			}
			printf("%I64d\n",cnt);
		}
	}
	return 0;
}