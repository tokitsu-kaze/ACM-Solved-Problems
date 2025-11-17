#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,cnt,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x&1) cnt++;
		}
		if(cnt==1) puts("Yes");
		else puts("No");
	}
	return 0;
}
