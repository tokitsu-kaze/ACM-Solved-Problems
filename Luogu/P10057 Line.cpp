#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,a,b,c,d,e,f,g,h,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
		ans=0;
		if(b>h||b<f) ans++;
		if(e>c||e<a) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
