#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e7+10;
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) printf("%d %d\n",(i*2)%n+1,(i*2+1)%n+1);
	return 0;
}
