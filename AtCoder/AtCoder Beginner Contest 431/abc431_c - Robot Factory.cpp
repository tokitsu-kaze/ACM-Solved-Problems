#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int h[MAX],b[MAX];
int main()
{
	int n,m,k,i,j,ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(h+1,h+1+n);
	sort(b+1,b+1+m);
	reverse(h+1,h+1+n);
	reverse(b+1,b+1+m);
	ans=0;
	for(i=1,j=1;i<=n;i++)
	{
		if(j<=n && h[i]<=b[j])
		{
			j++;
			ans++;
		}
	}
	if(ans>=k) puts("Yes");
	else puts("No");
	return 0;
}
