#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],mn[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=2*n;i++) mn[i]=1e9;
		for(i=1;i<=n;i++) mn[a[i]]=i;
		for(i=2;i<=2*n;i++) mn[i]=min(mn[i],mn[i-1]);
		ans=2e9;
		for(i=1;i<=n;i++) ans=min(ans,i-1+mn[b[i]]-1);
		printf("%d\n",ans);
	}
	return 0;
}
