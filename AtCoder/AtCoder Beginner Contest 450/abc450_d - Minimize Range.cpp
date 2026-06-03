#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int n,k,i,ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=k;
	}
//	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n]-a[1];
	for(i=1;i<n;i++) ans=min(ans,a[i]+k-a[i+1]);
	printf("%d\n",ans);
	return 0;
}
