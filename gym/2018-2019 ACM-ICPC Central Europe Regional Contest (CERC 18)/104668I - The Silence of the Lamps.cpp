#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
int res[MAX];
int main()
{
	int t,n,i,j,k;
	memset(res,0,sizeof res);
	for(i=1;i<=MAX-10;i++)
	{
		for(j=i+1;1LL*i*j<=MAX-10;j++)
		{
			for(k=j+1;1LL*i*j*k<=MAX-10;k++)
			{
				res[i*j*k]++;
			}
		}
	}
	for(i=1;i<=MAX-10;i++) res[i]+=res[i-1];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",res[n]);
	}
	return 0;
}
