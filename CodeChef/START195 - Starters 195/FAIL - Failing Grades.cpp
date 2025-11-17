#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,ok,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ok=1;
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum+=x;
			if(sum<i*40) ok=0;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
