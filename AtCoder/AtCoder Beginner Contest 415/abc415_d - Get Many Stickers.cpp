#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{ll a,b;}res[MAX];
int main()
{
	int m,i;
	ll n,ans,tmp,d;
	scanf("%lld%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%lld%lld",&res[i].a,&res[i].b);
	sort(res+1,res+1+m,[](node x,node y){
		return x.a-x.b<y.a-y.b;
	});
	ans=0;
	for(i=1;i<=m;i++)
	{
		d=res[i].a-res[i].b;
		if(n<res[i].a) continue;
		tmp=max(0LL,(n-res[i].a)/d+1);
		ans+=tmp;
		n-=tmp*d;
		assert(n<res[i].a);
	}
	printf("%lld\n",ans);
	return 0;
}
