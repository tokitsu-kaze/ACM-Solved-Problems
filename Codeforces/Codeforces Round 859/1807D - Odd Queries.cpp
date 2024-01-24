#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int bit[MAX];
int main()
{
	int t,n,q,x,i,l,r,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			bit[i]=bit[i-1]+(x&1);
		}
		while(q--)
		{
			scanf("%d%d%d",&l,&r,&k);
			k&=1;
			if((bit[n]-(bit[r]-bit[l-1])+(r-l+1)*k)&1) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
