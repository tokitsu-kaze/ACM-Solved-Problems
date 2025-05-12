#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,k,i,ok;
	ll sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=n-k+1;i<=n;i++) scanf("%d",&a[i]);
		for(i=0;i<n-k+1;i++) a[i]=0;
		for(i=n;i;i--) b[i]=a[i]-a[i-1];
		for(i=n-k+1;i;i--) b[i]=b[i+1];
		sum=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			sum+=b[i];
			if(i>1 && b[i-1]>b[i]) ok=0;
			if(i>=n-k+1 && sum<a[i]) ok=0;
//			printf("%d%c",b[i]," \n"[i==n]);
		}
		if(k==1) ok=1;
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}

