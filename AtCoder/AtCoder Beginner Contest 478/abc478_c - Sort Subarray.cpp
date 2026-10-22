#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int n,k,i,l,r;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	l=r=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			l=i;
			break;
		}
	}
	for(i=n;i;i--)
	{
		if(a[i]!=b[i])
		{
			r=i;
			break;
		}
	}
	if(r-l+1<=k) puts("Yes");
	else puts("No");
	return 0;
}
