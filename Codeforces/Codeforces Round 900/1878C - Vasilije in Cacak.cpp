#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,k;
	ll x,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lld",&n,&k,&x);
		l=1LL*(1+k)*k/2;
		r=1LL*(n-k+1+n)*k/2;
		if(x<l||x>r) puts("NO");
		else puts("YES");
	}
	return 0;
}
