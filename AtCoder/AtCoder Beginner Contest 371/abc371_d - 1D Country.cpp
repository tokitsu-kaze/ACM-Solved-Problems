#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int x[MAX],p[MAX];
ll bit[MAX];
int main()
{
	int n,q,i,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&x[i]);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	bit[0]=0;
	for(i=1;i<=n;i++) bit[i]=bit[i-1]+p[i];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		l=lower_bound(x+1,x+1+n,l)-x;
		r=upper_bound(x+1,x+1+n,r)-x-1;
		printf("%lld\n",bit[r]-bit[l-1]);
	}
	return 0;
}

