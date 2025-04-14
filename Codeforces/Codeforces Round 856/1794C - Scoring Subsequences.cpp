#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],ans[MAX];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			a[i]+=i;
			ans[i]=i-(lower_bound(a+1,a+1+i,i+1)-a)+1;
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
/*
a[i-1]>=i-(i-1)+1
a[i-2]>=i-(i-2)+1

a[x]+x>=i+1

*/
