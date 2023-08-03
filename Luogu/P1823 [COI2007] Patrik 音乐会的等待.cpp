#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
int a[MAX],st[MAX],cnt[MAX],top;
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	top=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[i]=1;
		while(top&&a[st[top-1]]<=a[i])
		{
			ans+=cnt[st[top-1]];
			if(a[st[top-1]]==a[i])
			{
				cnt[i]+=cnt[st[top-1]];
			}
			top--;
		}
		if(top) ans++;
		st[top++]=i;
	}
	printf("%lld\n",ans);
	return 0;
}
