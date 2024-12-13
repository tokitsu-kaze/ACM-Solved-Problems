#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int T,i,j,a[55],ok,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ok=1;
		for(i=2;i<=n;i++)
		{
			if(abs(a[i]-a[i-1])==5||abs(a[i]-a[i-1])==7);
			else ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
