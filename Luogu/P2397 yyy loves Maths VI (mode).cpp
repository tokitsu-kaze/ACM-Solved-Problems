#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,x,vote,now;
	scanf("%d",&n);
	vote=1;
	now=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==now) vote++;
		else vote--;
		if(vote==0)
		{
			now=x;
			vote=1;
		}
	}
	printf("%d\n",now);
	return 0;
}
