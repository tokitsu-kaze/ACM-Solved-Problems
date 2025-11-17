#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,j,k,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&j,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>a[j]) cnt++;
		}
		if(k==1)
		{
			if(cnt==0) puts("YES");
			else puts("NO");
			continue;
		}
		if(cnt-(n-k)<=k-1) puts("YES");
		else puts("NO");
	}
	return 0;
}
