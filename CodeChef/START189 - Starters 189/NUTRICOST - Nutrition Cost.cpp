#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,ans,a[105],b[105],c,mx[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&c);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=100;i++) mx[i]=0;
		for(i=1;i<=n;i++) mx[a[i]]=max(mx[a[i]],c-b[i]);
		ans=0;
		for(i=1;i<=100;i++) ans+=mx[i];
		printf("%d\n",ans);
	}
	return 0;
}
