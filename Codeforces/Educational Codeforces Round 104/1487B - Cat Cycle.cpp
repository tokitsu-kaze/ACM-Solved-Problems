#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		k--;
		tmp=n/2;
		printf("%d\n",(k+(n%2)*k/tmp)%n+1);
	}
	return 0;
}
