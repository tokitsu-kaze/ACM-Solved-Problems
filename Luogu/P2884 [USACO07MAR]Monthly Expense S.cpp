#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int money[MAX];
int main()
{
	int n,m,i,mx,sum,l,r,mid,count;
	scanf("%d%d",&n,&m);
	sum=0;
	mx=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&money[i]);
		sum+=money[i];
		mx=max(mx,money[i]);
	}
	l=mx;
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
	printf("%d\n",l);
	return 0;
}
