#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
int a[MAX];
int main()
{
	int n,i,ans,now;
	scanf("%d",&n);
	ans=now=0;
	a[0]=-10;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==a[i-1]+1) now++;
		else now=1;
		ans=max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}
