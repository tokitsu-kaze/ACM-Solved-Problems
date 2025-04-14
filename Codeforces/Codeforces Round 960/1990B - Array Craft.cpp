#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int T,n,x,y,i,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&x,&y);
		f=-1;
		for(i=y-1;i;i--)
		{
			a[i]=f;
			f*=-1;
		}
		for(i=y;i<=x;i++) a[i]=1;
		f=-1;
		for(i=x+1;i<=n;i++)
		{
			a[i]=f;
			f*=-1;
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}

