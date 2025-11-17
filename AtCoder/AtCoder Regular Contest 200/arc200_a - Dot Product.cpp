#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],x[MAX];
int main()
{
	int T,n,i,mn,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		mn=mx=1;
		for(i=2;i<=n;i++)
		{
			if(1LL*a[i]*b[mn]<1LL*a[mn]*b[i]) mn=i;
			if(1LL*a[i]*b[mx]>1LL*a[mx]*b[i]) mx=i;
		}
		if(mn==mx)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		for(i=1;i<=n;i++)
		{
			if(i==mn) x[i]=-a[mx]-b[mx];
			else if(i==mx) x[i]=a[mn]+b[mn];
			else x[i]=0;
			printf("%d%c",x[i]," \n"[i==n]);
		}
	}
	return 0;
}
