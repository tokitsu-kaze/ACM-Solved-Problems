#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&x,&y);
		printf("%d\n",(n+min(x,y)-1)/min(x,y));
	}
	return 0;
}
