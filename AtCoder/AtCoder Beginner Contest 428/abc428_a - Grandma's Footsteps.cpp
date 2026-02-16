#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int s,a,b,x,ans;
	scanf("%d%d%d%d",&s,&a,&b,&x);
	ans=x/(a+b)*a*s;
	x%=a+b;
	ans+=min(x,a)*s;
	printf("%d\n",ans);
	return 0;
}
