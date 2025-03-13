#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=1e9+7;
struct node{int cnt,cost;} a[MAX];
int main()
{
	int T,n,p,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&p);
		for(i=1;i<=n;i++) scanf("%d",&a[i].cnt);
		for(i=1;i<=n;i++) scanf("%d",&a[i].cost);
		sort(a+1,a+1+n,[](node x,node y){
			return x.cost<y.cost;
		});
		ans=p;
		for(i=2,j=1;i<=n;i++)
		{
			while(j<i && a[j].cnt==0) j++;
			if(j<i && a[j].cost<=p)
			{
				ans+=a[j].cost;
				a[j].cnt--;
			}
			else ans+=p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
