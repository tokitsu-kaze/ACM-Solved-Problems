#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int cnt[MAX];
int main()
{
	int T,a,b,x,y,tmp;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&x,&y);
		if(a>b)
		{
			swap(a,b);
			swap(x,y);
		}
		x=abs(x);
		y=abs(y);
		ans=0;
		tmp=min(x,y);
		ans+=2LL*a*tmp;
		x-=tmp;
		y-=tmp;
		if(3LL*a<=b)
		{
			ans+=4LL*a*((x+y)/2);
			x%=2;
			y%=2;
			if(x) ans+=a;
			else if(y) ans+=3LL*a;
		}
		else
		{
			if(x)
			{
				ans+=1LL*a*((x+1)/2);
				ans+=1LL*b*(x/2);
			}
			else
			{
				ans+=1LL*b*((y+1)/2);
				ans+=1LL*a*(y/2);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
