#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,i,j,k,sum,ans,a[55],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=i;j<=n;j++)
		{
			sum+=a[j];
			ok=1;
			for(k=i;k<=j;k++)
			{
				if(sum%a[k]==0) ok=0;
			}
			ans+=ok;
		}
	}
	printf("%d\n",ans);
	return 0;
}
