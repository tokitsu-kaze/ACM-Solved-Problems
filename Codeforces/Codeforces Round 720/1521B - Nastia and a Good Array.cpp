#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int p=1e9+7;
int a[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		printf("%d\n",n/2);
		for(i=1;i+1<=n;i+=2) printf("%d %d %d %d\n",i,i+1,min(a[i],a[i+1]),p);
	}
	return 0;
}
