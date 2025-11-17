#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int a[MAX];
int main()
{
	int T,n,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		ans=a[n-1];
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				ans=max(ans,a[n]%(a[i]+a[j]));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
