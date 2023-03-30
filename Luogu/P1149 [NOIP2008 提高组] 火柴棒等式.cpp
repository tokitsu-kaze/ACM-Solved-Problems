#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
const int cost[]={6,2,5,5,4,5,6,3,7,6};
int ans;
int cal(int x)
{
	if(x==0) return cost[0];
	int res=0;
	while(x>0)
	{
		res+=cost[x%10];
		x/=10;
	}
	return res;
}
int main()
{
	int n,i,j;
	cin>>n;
	ans=0;
	for(i=0;i<=1111;i++)
	{
		if(cal(i)>n) continue;
		for(j=0;j<=1111;j++)
		{
			if(cal(i)+cal(j)+cal(i+j)+4==n)
			{
	//			printf("%d %d\n",i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
