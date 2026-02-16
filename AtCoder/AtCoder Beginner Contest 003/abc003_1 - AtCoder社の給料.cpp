#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1440+10;
int main()
{
	int x,i;
	double ans;
	scanf("%d",&x);
	ans=0;
	for(i=1;i<=x;i++) ans+=i*10000.0/x;
	printf("%.10f\n",ans);
	return 0;
}
