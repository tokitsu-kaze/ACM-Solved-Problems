#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,i,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			if(a[i]==a[1]) x=i;
			else break;
		}
		for(i=n;i;i--)
		{
			if(a[i]==a[n]) y=i;
			else break;
		}
		if(a[1]!=a[n]) printf("%d\n",min(n-x,y-1));
		else printf("%d\n",max(0,y-x-1));
	}
	return 0;
}
