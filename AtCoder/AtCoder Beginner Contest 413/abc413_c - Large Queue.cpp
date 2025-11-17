#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int c[MAX],x[MAX];
int main()
{
	int q,op,k,i,l,r,tmp;
	ll ans;
	scanf("%d",&q);
	l=r=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&c[r],&x[r]);
			r++;
		}
		else
		{
			scanf("%d",&k);
			ans=0;
			while(k>0)
			{
				tmp=min(c[l],k);
				ans+=1LL*tmp*x[l];
				c[l]-=tmp;
				k-=tmp;
				if(c[l]==0) l++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
