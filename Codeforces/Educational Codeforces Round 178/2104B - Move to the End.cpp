#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],premx[MAX];
ll res[MAX];
int main()
{
	int T,n,i;
	ll sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		premx[1]=a[1];
		for(i=2;i<=n;i++) premx[i]=max(premx[i-1],a[i]);
		sum=0;
		for(i=n;i;i--)
		{
			res[i]=sum+premx[i];
			sum+=a[i];
		}
		reverse(res+1,res+1+n);
		for(i=1;i<=n;i++) printf("%lld%c",res[i]," \n"[i==n]);
	}
	return 0;
}
