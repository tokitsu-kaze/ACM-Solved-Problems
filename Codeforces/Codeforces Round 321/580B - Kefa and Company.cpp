#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct node{int m,s;}a[MAX];
int main()
{
	int n,d,i,j;
	ll ans,now;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].m,&a[i].s);
	sort(a+1,a+1+n,[&](node x,node y){
		return x.m<y.m;
	});
	ans=now=0;
	for(i=1,j=0;i<=n;i++)
	{
		while(j+1<=n && a[j+1].m-a[i].m<d)
		{
			j++;
			now+=a[j].s;
		}
		ans=max(ans,now);
		now-=a[i].s;
	}
	printf("%lld\n",ans);
	return 0;
}
