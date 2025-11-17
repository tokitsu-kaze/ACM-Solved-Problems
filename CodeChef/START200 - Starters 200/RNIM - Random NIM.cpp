#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,i,x,cnt1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt1=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==1) cnt1++;
		}
		if(cnt1==n)
		{
			if(n&1) puts("1");
			else puts("0");
		}
		else puts("499122177");
	}
	return 0;
}

