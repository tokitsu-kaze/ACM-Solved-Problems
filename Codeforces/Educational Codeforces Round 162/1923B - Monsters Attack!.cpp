#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=998244353;
struct node{int h,x;}a[MAX];
int main()
{
	int T,n,k,i,ok;
	ll now,tmp,ret;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i].h);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].x);
			if(a[i].x<0) a[i].x=-a[i].x;
		}
		sort(a+1,a+1+n,[](node a,node b){
			return a.x<b.x;
		});
		now=0;
		ret=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(a[i].h<=ret)
			{
				ret-=a[i].h;
				continue;
			}
			tmp=(a[i].h-ret+k-1)/k;
			now+=tmp;
			ret=ret+tmp*k-a[i].h;
			assert(ret<k);
			if(now>a[i].x)
			{
				ok=0;
				break;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
