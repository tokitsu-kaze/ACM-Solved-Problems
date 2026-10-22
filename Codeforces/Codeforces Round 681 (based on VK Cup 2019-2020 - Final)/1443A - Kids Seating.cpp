#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
int main()
{
	int T,n,i,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		now=2*n-2;
		for(i=1;i<=n;i++)
		{
			now+=2;
			printf("%d%c",now," \n"[i==n]);
		}
	}
	return 0;
}
