#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int sum[MAX];
int main()
{
	int t,n,i,x;
	sum[0]=0;
	for(i=1;i<=MAX-10;i++)
	{
		sum[i]=sum[i-1];
		x=i;
		while(x)
		{
			sum[i]+=x%10;
			x/=10;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",sum[n]);
	}
	return 0;
}
