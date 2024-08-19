#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX];
ll bit[MAX];
int main()
{
	int n,k,i;
	ll ans;
	scanf("%d%d",&n,&k);
	bit[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		bit[i]=bit[i-1]+a[i];
	}
	ans=0;
	for(i=k;i<=n;i++) ans+=bit[i]-bit[i-k];
	printf("%.10f\n",ans*1.0/(n-k+1));
	return 0;
}
