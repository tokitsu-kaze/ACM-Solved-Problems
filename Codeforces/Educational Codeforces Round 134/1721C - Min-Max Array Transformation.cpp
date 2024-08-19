#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
int a[MAX],b[MAX],mn[MAX],mx[MAX];
int main()
{
	int t,n,i,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) mn[i]=*lower_bound(b+1,b+i,a[i])-a[i];
		p=n;
		for(i=n;i;i--)
		{
			mx[i]=b[p]-a[i];
			if(a[i]>b[i-1]) p=i-1;
		}
		for(i=1;i<=n;i++) printf("%d%c",mn[i]," \n"[i==n]);
		for(i=1;i<=n;i++) printf("%d%c",mx[i]," \n"[i==n]);
	}
	return 0;
}

