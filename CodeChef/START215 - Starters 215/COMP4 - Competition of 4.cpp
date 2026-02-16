#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int x,ans;
	scanf("%d",&x);
	ans=1000*16;
	while(x--) ans/=2;
	printf("%d\n",ans);
	return 0;
}
