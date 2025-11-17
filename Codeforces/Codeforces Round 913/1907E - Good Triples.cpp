#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,j,k;
	ll v[11],ans;
	memset(v,0,sizeof v);
	for(i=0;i<=9;i++)
	{
		for(j=0;i+j<=9;j++)
		{
			for(k=0;i+j+k<=9;k++)
			{
				v[i+j+k]++;
			}
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=1;
		while(n)
		{
			ans*=v[n%10];
			n/=10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
