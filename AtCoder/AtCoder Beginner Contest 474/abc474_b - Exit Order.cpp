#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int n,i,j,p[105],ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	ok=1;
	for(i=1;i+10-1<=n;i+=10)
	{
		for(j=i;j<=i+10-1;j++)
		{
			if(p[j]<i || p[j]>i+10-1) ok=0;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
