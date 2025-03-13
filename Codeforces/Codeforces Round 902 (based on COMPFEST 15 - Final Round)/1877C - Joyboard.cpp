#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=1e9+7;
int main()
{
	int T,n,m,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(k==1) puts("1");
		else if(k==2) printf("%d\n",m/n+min(n-1,m));
		else if(k==3) printf("%d\n",max(0,m-n-(m/n-1)));
		else puts("0");
	}
	return 0;
}
