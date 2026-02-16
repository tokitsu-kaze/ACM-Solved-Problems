#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
long double v[MAX],a[MAX];
int main()
{
	int n,q,i,x,y,ans,l,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i]=-atan2l(y,x);
		v[i]=a[i];
	}
	sort(v+1,v+1+n);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		l=lower_bound(v+1,v+1+n,a[x])-v;
		r=upper_bound(v+1,v+1+n,a[y])-v-1;
		ans=0;
		if(r<l)
		{
			ans+=n-l+1;
			ans+=r;
		}
		else ans+=r-l+1;
		printf("%d\n",ans);
	}
	return 0;
}
