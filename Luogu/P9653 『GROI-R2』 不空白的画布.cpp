#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int t,n,m,k,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=2;i<=n-1&&m>0;i++)
		{
			if(a[i]==a[i-1]&&a[i]==a[i+1])
			{
				if(a[i]==k) a[i]=1;
				else a[i]=k;
				m--;
			}
		}
		ans=1;
		for(i=2;i<=n;i++) ans+=(a[i]!=a[i-1]);
		if(k!=1) ans=min(n,ans+m);
		printf("%d\n",ans);
	}
	return 0;
}

