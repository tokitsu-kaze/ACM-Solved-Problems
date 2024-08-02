#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAX=1e7+10;
ull a[MAX],b;
int main()
{
	int t,n,m,i,j,ans,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%llu",&a[i]);
		ans=0;
		cnt=0;
		for(i=1,j=1;j<=m;j++)
		{
			scanf("%llu",&b);
			if(a[i]!=b)
			{
				ans^=cnt;
				cnt=0;
			}
			while(i<n && a[i]<b) i++;
			if(a[i]==b) cnt++;
		}
		ans^=cnt;
		printf("%d\n",ans);
	}
	return 0;
}
