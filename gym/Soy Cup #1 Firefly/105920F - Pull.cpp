#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,a,b,c,i,t;
	double now,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		now=1;
		for(i=1;i<=c;i++)
		{
			ans+=i*now*a/100;
			now=now*(1-a/100.0);
		}
		t=min(100,a+b);
		for(i=c+1;;i++)
		{
			ans+=i*now*t/100;
			now=now*(1-t/100.0);
			if(t>=100) break;
			t+=b;
			t=min(t,100);
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
