#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,k,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		sum=(n+1)/2-(n-k+1)/2;
		if(sum&1) puts("NO");
		else puts("YES");
	}
	return 0;
}
