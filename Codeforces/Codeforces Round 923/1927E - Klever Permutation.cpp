#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,k,i,j,nowl,nowr;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		nowl=1;
		nowr=n;
		for(j=1;j<=k;j+=2)
		{
			for(i=j;i<=n;i+=k) a[i]=nowl++;
			for(i=j+1;i<=n;i+=k) a[i]=nowr--;
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
