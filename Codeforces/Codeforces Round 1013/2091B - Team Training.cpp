#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,x,i,ans,lst;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		lst=n;
		ans=0;
		for(i=n;i;i--)
		{
			if(1LL*a[i]*(lst-i+1)>=x)
			{
				ans++;
				lst=i-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
