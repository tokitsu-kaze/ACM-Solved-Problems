#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	puts("Yes");
	for(i=0;i<n;i++) printf("%d%c",(3*i-2+3*n)%(3*n)," \n"[i==n-1]);
	for(i=0;i<n;i++) printf("%d%c",(3*i-1+3*n)%(3*n)," \n"[i==n-1]);
	return 0;
}
