#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int T,n,l,r,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		for(i=0;i<=n;i++) a[i]=i;
		a[r]=a[l-1];
		for(i=n;i;i--) a[i]^=a[i-1];
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
