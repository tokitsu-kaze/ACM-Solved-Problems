#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int T,a[3];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		if((a[0]&1) && (a[1]&1)) a[0]--;
		printf("%d\n",a[0]+a[1]);
	}
	return 0;
}

