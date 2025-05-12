#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	ll a,b;
	scanf("%lld%lld",&a,&b);
	if (a==1 || a%b==0) puts("Alice");
	else if (a-b>1) puts("Alice");
	else if (a-b==1) puts("Bob");
	else if (a==b) puts("Alice");
	else puts("Bob");
	return 0;
}
