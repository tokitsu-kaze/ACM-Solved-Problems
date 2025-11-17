#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n>=3)
		{
			puts("Yes");
			continue;
		}
		if(n==1)
		{
			if(a[1]%3==0) puts("Yes");
			else puts("No");
		}
		else if(n==2)
		{
			if(a[1]%3==0 || a[2]%3==0) puts("Yes");
			else if((a[1]+a[2])%3==0) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
