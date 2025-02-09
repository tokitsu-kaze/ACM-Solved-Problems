#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
double sqr(double x){return x*x;}
int main()
{
	int r,x;
	ll h,ans;
	scanf("%d",&r);
	ans=0;
	for(x=r;x>=0;x--)
	{
		if(sqr(r)-sqr(x+0.5)<0) continue;
		h=sqrt(sqr(r)-sqr(x+0.5))-0.5;
		while(sqr(x+0.5)+sqr(h+1.5)<=sqr(r)) h++;
		while(sqr(x+0.5)+sqr(h+0.5)>sqr(r)) h--;
		ans+=h*2+1;
		if(x>0) ans+=h*2+1;
//		printf("%d %lld\n",x,h);
//		printf("%.10f\n",sqr(x+0.5)+sqr(h+0.5));
	}
	printf("%lld\n",ans);
	return 0;
}
