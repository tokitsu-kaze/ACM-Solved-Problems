#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int n,m,i,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	for(i=2;i<=n;i++) a[i]=min(a[i],a[i-1]);
	for(i=1;i<=m;i++)
	{
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(a[mid]<=b[i]) r=mid;
			else l=mid+1;
		}
		if(a[l]<=b[i]) printf("%d\n",l);
		else puts("-1");
	}
	return 0;
}
