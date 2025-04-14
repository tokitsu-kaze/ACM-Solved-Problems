#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,x,i,cnt[55],ok,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		ok=0;
		sum=0;
		for(i=n;i;i--)
		{
			sum+=cnt[i];
			if(sum&1) ok=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

