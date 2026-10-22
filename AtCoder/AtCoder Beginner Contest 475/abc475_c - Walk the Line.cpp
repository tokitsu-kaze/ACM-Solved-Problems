#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8000+10;
ll a[MAX];
int main()
{
	int n,s,i,j,ans,cnt,cntnow;
	ll l,sl,sr,now;
	scanf("%d%d%lld",&n,&s,&l);
	for(i=1;i<n;i++) scanf("%lld",&a[i]);
	ans=1;
	sl=0;
	cnt=1;
	for(i=s-1;i;i--)
	{
		sl+=a[i];
		cnt++;
		if(sl<=l) ans=max(ans,cnt);
		else break;
		now=2*sl;
		cntnow=cnt;
		for(j=s;j<n;j++)
		{
			now+=a[j];
			cntnow++;
			if(now<=l) ans=max(ans,cntnow);
		}
	}
	sr=0;
	cnt=1;
	for(i=s;i<n;i++)
	{
		sr+=a[i];
		cnt++;
		if(sr<=l) ans=max(ans,cnt);
		else break;
		now=2*sr;
		cntnow=cnt;
		for(j=s-1;j;j--)
		{
			now+=a[j];
			cntnow++;
			if(now<=l) ans=max(ans,cntnow);
		}
	}
	printf("%d\n",ans);
	return 0;
}
