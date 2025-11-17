#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
int main()
{
	int T,n,i,x,a[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&x);
		sort(a+1,a+1+n);
		if(x<a[1] || x>a[n]) puts("NO");
		else puts("YES");
	}
	return 0;
}
