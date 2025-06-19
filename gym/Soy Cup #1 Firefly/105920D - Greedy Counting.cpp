#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX],st[MAX],top,l[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			l[i]=0;
		}
		top=0;
		for(i=n;i;i--)
		{
			while(top && a[st[top-1]]<=a[i])
			{
				l[st[top-1]]=i;
				top--;
			}
			st[top++]=i;
		}
//		for(i=1;i<=n;i++) printf("%d %d\n",i,l[i]);
		ans=0;
		for(i=1;i<=n;i++) ans+=1LL*(i-l[i])*(n-i+1);
		printf("%lld\n",ans);
	}
	return 0;
}
