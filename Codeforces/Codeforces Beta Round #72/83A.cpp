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
#define eps 1e-9
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
ll fact(ll a)
{
	ll i,s=0;
	for(i=1;i<a;i++)
	{
		s+=i;
	}
	return s;
}
int main()
{
	ll n,a[100010],i,j,cnt,sum,temp;
	while(cin>>n)
	{
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
		}
		temp=a[0];
		cnt=1;
		sum=n;
		for(i=1;i<n;i++)
		{
			if(a[i]==temp) cnt++;
			else
			{
				if(cnt>1) sum+=fact(cnt);
				temp=a[i];
				cnt=1;
			}
		}
		if(cnt>1) sum+=fact(cnt);
		printf("%I64d\n",sum);
	}
    return 0;
}