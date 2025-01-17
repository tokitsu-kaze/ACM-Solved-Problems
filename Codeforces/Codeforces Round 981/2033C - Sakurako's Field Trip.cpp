#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int T,n,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=2,j=n-1;i<j;i++,j--)
		{
			if(a[i]==a[i-1] || a[j]==a[j+1]) swap(a[i],a[j]);
		}
		ans=0;
		for(i=2;i<=n;i++) ans+=(a[i]==a[i-1]);
		printf("%d\n",ans);
	}
	return 0;
}
