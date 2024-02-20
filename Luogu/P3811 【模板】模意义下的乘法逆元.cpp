#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e6+10;
ll inv[MAX];
void init_inv(int n,ll p)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
int main()
{
	int n,i;
	ll p;
	scanf("%d%lld",&n,&p);
	init_inv(n,p);
	for(i=1;i<=n;i++) printf("%lld\n",inv[i]);
	return 0;
}
