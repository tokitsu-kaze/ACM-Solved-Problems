#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i,sq,ans;
	scanf("%d",&n);
	sq=sqrt(n+0.5);
	for(i=2;i<=sq;i++)
	{
		if(n%i==0) ans=n/i;
	}
	printf("%d\n",ans);
	return 0;
}
