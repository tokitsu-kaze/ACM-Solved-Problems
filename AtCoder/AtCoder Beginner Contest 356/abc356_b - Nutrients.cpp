#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[105];
int main()
{
	int n,m,i,j,x,ok;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	while(n--)
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			a[i]-=x;
		}
	}
	ok=1;
	for(i=1;i<=m;i++) ok&=(a[i]<=0);
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
