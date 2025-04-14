#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			puts("-1");
			continue;
		}
		now=1;
		for(i=1;i<=n;i++)
		{
			a[i]=now;
			if(now==n) now=2;
			else now+=2;
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
