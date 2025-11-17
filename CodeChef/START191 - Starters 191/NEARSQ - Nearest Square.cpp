#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,sq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sq=sqrt(n);
		while((sq+1)*(sq+1)<=n) sq++;
		printf("%d\n",sq*sq);
	}
	return 0;
}
