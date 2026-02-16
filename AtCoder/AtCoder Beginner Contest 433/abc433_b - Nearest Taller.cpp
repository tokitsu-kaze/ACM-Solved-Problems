#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,j,a[105],ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		ans=-1;
		for(j=i-1;j>=1;j--)
		{
			if(a[j]>a[i])
			{
				ans=j;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
