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
	int k,m,len,n,a[1111],t,temp,i;
	while(~scanf("%d%d",&k,&m))
	{
		n=len=0;
		mem(a,0);
		t=m;
		while(t)
		{
			
			a[len++]=t%10;
			t/=10;
		}
		while(1)
		{
			n++;
			if(len<k);
			else if(a[k-1]==7) break;
			temp=0;
			for(i=0;i<len;i++)
			{
				temp/=10;
				t=a[i]*m+temp;
		//		cout<<t<<" ";
				if(t>=10)
				{
					a[i]=t%10;
					temp=t-a[i];
				}
				else a[i]=t;
			}
			
			
			if(len>=k+5) continue;
			temp/=10;
			while(temp)
			{
				a[len++]=temp%10;
				temp/=10;
			}
	/*		cout<<len<<endl;
			for(i=len-1;i>=0;i--)
			{
				printf("%d",a[i]);
			}
			puts("");*/
		}
		printf("%d\n",n);
	}
	return 0;
}