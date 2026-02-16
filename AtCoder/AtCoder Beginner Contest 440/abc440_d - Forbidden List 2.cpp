#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int n,a[MAX];
int ck(int y,int ans)
{
	return ans-(lower_bound(a+1,a+1+n,ans)-a-1)<=y;
}
int main()
{
	int q,i,x,y,cnt;
	ll l,r,mid;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		l=x;
		r=2e9;
		cnt=lower_bound(a+1,a+1+n,x)-a;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(y+(x-cnt),mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%lld\n",l);
	}
	return 0;
}
