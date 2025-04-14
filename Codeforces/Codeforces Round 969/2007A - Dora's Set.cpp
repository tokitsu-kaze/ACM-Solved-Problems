#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
int main()
{
	int T,l,r,odd;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		odd=(r+1)/2-l/2;
		printf("%d\n",min(odd/2,(r-l+1)/3));
	}
	return 0;
}

