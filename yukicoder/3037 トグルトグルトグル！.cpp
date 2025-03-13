#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	ll x,sq;
	cin>>x;
	sq=sqrt(x);
	while(sq*sq<x) sq++;
	while(sq*sq>x) sq--;
	printf("%lld\n",sq);
	return 0;
}
