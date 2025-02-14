#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=1000+10;
int a[MAX];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(i=2;i<n;i++)
	{
		if((a[i]&1)!=(a[i-1]&1) && (a[i]&1)!=(a[i+1]&1)) ans=i;
	}
	if(ans==0 && (a[1]&1)!=(a[2]&1) && (a[1]&1)!=(a[3]&1)) ans=1;
	if(ans==0 && (a[n]&1)!=(a[n-1]&1) && (a[n]&1)!=(a[n-2]&1)) ans=n;
	printf("%d\n",ans);
	return 0;
}
