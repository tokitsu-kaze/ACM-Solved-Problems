#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,cnt,a1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%d",&a1);
		cnt=0;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			if(abs(x)>abs(a1)) cnt++;
		}
		if(cnt>=n-n/2-1) puts("YES");
		else puts("NO");
	}
	return 0;
}
