#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=1e9+7;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,j,ans,pn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		pn=n;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		n=unique(a+1,a+1+n)-a-1;
		ans=0;
		for(i=1,j=0;i<=n;i++)
		{
			while(j+1<=n && a[j+1]-a[i]<pn) j++;
			ans=max(ans,j-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}

