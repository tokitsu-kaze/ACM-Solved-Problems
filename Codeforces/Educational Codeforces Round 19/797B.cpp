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
int a[MAX];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,i,sum,temp,cnt,k,t;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		sum=cnt=k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(t>0&&t%2==0) sum+=t;
			else if(t%2) a[k++]=t;
		}
		sort(a,a+k,cmp);
		temp=0;
		for(i=0;i<k;i++)
		{
			if(a[i]>0)
			{
				sum+=a[i];
				cnt++; 
				temp=a[i];
			}
			else
			{
				if(cnt%2&&cnt) break;
				else
				{
					if(temp) sum=max(sum-temp,sum+a[i]);
					else sum+=a[i];
					cnt++;
					break;
				}
			}
		}
		if(cnt%2==0) sum-=temp;
		printf("%d\n",sum);
	} 
	return 0;
}