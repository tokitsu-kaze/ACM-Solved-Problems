#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,i,x,ok;
	scanf("%d",&n);
	ok=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>=0) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
