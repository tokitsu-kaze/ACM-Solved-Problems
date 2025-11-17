#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,l,r,a[105];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	l=n+1;
	r=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			l=i;
			break;
		}
	}
	for(i=n;i;i--)
	{
		if(a[i]==1)
		{
			r=i;
			break;
		}
	}
	printf("%d\n",max(0,r-l));
	return 0;
}
