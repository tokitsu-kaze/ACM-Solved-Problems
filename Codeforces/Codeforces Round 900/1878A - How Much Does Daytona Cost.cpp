#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int T,n,k,i,ok,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		ok=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==k) ok=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
