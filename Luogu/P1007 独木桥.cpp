#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l,n,i,x,mn,mx;
	scanf("%d",&l);
	scanf("%d",&n);
	mn=0;
	mx=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mn=max(mn,min(x,l-x+1));
		mx=max(mx,max(x,l-x+1));
	}
	printf("%d %d\n",mn,mx);
	return 0;
}
