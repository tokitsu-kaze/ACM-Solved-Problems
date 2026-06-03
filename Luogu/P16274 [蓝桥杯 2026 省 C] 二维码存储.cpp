#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,m,tmp;
	scanf("%d%d",&n,&m);
	printf("%lld\n",1LL*(m+31)/32*32*n/8);
	return 0;
}

