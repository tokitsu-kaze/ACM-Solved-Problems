#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll cal(int n,int a,int b)
{
	ll res=0;
	res=1LL*(a+b+(a^b))*(n/3);
	if(n%3==1) res+=a;
	else if(n%3==2) res+=a+b;
	return res;
}
int main()
{
	int T,a,b,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&l,&r);
		printf("%lld\n",cal(r,a,b)-cal(l-1,a,b));
	}
	return 0;
}
