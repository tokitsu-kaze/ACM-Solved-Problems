#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],k;
int ck(int n,int m)
{
	int i,f;
	ll cnt;
	cnt=0;
	if(n&1) f=0;
	else f=1;
	for(i=1;i<=k;i++)
	{
		if(a[i]/m>=2) cnt+=a[i]/m;
		if(n&1) f|=(a[i]/m>=3);
	}
	return cnt>=n && f;
}
int main()
{
	int T,i,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=k;i++) scanf("%d",&a[i]);
		if(ck(n,m)) puts("Yes");
		else if(ck(m,n)) puts("Yes");
		else puts("No");
	}
	return 0;
}
