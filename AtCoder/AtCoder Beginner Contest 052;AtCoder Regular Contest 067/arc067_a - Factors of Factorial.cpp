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
const ll mod=1000000000+7;
int main()
{
	ll i,j,flag[1111],n,cnt,a[1111],b[1111],t,sum,temp;
	mem(flag,0);
	for(i=2;i<=1000/2;i++)
	{
		if(!flag[i])
		{
			for(j=i+i;j<=1000;j+=i)
			{
				flag[j]=1;
			}
		}
	}
	mem(a,0);
	cnt=0;
	for(i=2;i<=1000;i++)
	{
		if(!flag[i]) a[cnt++]=i;
	}
//	cout<<cnt<<endl;
	while(~scanf("%lld",&n))
	{
		mem(b,0);
		for(i=2;i<=n;i++)
		{
			for(j=0;j<cnt;j++)
			{
				if(a[j]>i) break;
				t=0;
				temp=i;
				while(temp%a[j]==0)
				{
					temp/=a[j];
					t++;
				}
				b[j]+=t;
			}
		}
		sum=1;
		for(i=0;i<cnt;i++)
		{
			if(b[i]) sum=sum%mod*(b[i]+1)%mod;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
//720 2 2 2 2 3 3 5  5*3*2

