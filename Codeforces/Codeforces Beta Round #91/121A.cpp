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
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
ll a[1111],k;
void init()
{
	ll t;
	queue<ll> q;
	k=0;
	q.push(4);
	q.push(7);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t>4444444444) break;
		a[k++]=t;
		q.push(t*10+4);
		q.push(t*10+7);
	}
}
int main()
{
	ll l,r,i,sum;
	mem(a,0);
	init();
	while(~scanf("%I64d%I64d",&l,&r))
	{
		sum=0;
		for(i=0;i<1023;i++)
		{
			if(l<=a[i]&&r>a[i])
			{
				sum+=(a[i]-l+1)*a[i];
				l=a[i]+1;
			}
			else if(l<=a[i]&&a[i]>=r)
			{
				sum+=(r-l+1)*a[i];
				l=r+1;
			}
			if(l>r) break;
		}
		printf("%I64d\n",sum);
	}
    return 0;
}