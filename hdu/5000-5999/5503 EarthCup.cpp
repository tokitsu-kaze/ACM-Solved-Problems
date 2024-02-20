#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int t,n,i,ok;
	ll s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		s=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			s+=a[i];
			if(s<1ll*i*(i-1)/2) ok=0;
		}
		if(s!=1ll*n*(n-1)/2) ok=0;
		if(ok) puts("It seems to have no problem.");
		else puts("The data have been tampered with!");
	}
	return 0;
}
