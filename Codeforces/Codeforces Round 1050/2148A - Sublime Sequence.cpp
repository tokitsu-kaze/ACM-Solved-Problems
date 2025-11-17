#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,x,i,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			if(i&1) sum+=x;
			else sum-=x;
		}
		printf("%d\n",sum);
	}
	return 0;
}
