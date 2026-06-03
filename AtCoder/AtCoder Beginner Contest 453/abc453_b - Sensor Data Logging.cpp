#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,x,i,a[105],pre;
	scanf("%d%d",&n,&x);
	for(i=0;i<=n;i++) scanf("%d",&a[i]);
	printf("%d %d\n",0,a[0]);
	pre=a[0];
	for(i=1;i<=n;i++)
	{
		if(abs(a[i]-pre)>=x)
		{
			printf("%d %d\n",i,a[i]);
			pre=a[i];
		}
	}
	return 0;
}
