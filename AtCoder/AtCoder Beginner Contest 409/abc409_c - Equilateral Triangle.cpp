#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int cnt[MAX];
int main()
{
	int n,l,i,x,y,pre;
	ll ans;
	scanf("%d%d",&n,&l);
	for(i=0;i<l;i++) cnt[i]=0;
	pre=0;
	cnt[pre]++;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		pre=(pre+x)%l;
		cnt[pre]++;
	}
	if(l%3)
	{
		puts("0");
		return 0;
	}
	ans=0;
	for(i=0;i<l/3;i++)
	{
		x=i-l/3;
		if(x<0) x+=l;
		y=i+l/3;
		y%=l;
		ans+=1LL*cnt[i]*cnt[x]*cnt[y];
	}
	printf("%lld\n",ans);
	return 0;
}
