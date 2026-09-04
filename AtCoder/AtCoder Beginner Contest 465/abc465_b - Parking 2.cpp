#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int main()
{
	int x,y,l,r,a,b,len,ans;
	scanf("%d%d%d%d%d%d",&x,&y,&l,&r,&a,&b);
	len=max(0,min(r,b)-max(l,a));
	ans=len*x;
	ans+=(b-a-len)*y;
	printf("%d\n",ans);
	return 0;
}
