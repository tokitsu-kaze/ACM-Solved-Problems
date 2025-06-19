#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int p[MAX];
int main()
{
	int n,i,l,r,ok1,ok2;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	ans=0;
	ok1=ok2=0;
	for(i=1,l=r=1;i<n-1;i++)
	{
		while(l+1<n)
		{
			if(ok1 && ok2) break;
			l++;
			if(p[l]>p[l-1] && p[l]>p[l+1]) ok1++;
			if(p[l]<p[l-1] && p[l]<p[l+1]) ok2++;
		}
		r=max(r,l);
		while(r+2<=n)
		{
			if(p[r+1]>p[r] && p[r+1]>p[r+2]) break;
			if(p[r+1]<p[r] && p[r+1]<p[r+2]) break;
			r++;
		}
		if(p[i]<p[i+1] && ok1==1 && ok2==1) ans+=r-l+1;
		if(p[i+1]>p[i] && p[i+1]>p[i+2]) ok1--;
		if(p[i+1]<p[i] && p[i+1]<p[i+2]) ok2--;
	}
	printf("%lld\n",ans);
	return 0;
}
