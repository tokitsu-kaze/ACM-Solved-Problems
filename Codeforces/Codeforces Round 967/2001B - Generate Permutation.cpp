#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,i,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1)
		{
			a[(n+1)/2]=1;
			now=n;
			for(i=(n+1)/2-1;i>=1;i--) a[i]=now--;
			for(i=(n+1)/2+1;i<=n;i++) a[i]=now--;
			for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		}
		else puts("-1");
	}
	return 0;
}

