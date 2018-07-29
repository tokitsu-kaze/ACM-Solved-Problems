#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#define MAX 100010
using namespace std;
int money[MAX];
int main()
{
	int n,m,i,max,sum,l,r,mid,count;
	while(cin>>n>>m)
	{
		sum=0;
		max=INT_MIN;
		for(i=0;i<n;i++)
		{
			scanf("%d",&money[i]);
			sum+=money[i];
			if(money[i]>max) max=money[i];
		}
		l=max;
		r=sum;
		while(r>l)
		{
			mid=(l+r)>>1;
			for(i=0,sum=0,count=0;i<n;i++)
			{
				sum+=money[i];
				if(sum>mid)
				{
					sum=money[i];
					count++;
				}
				
			}
			if(count<m) r=mid;
			else if(count>=m) l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}