#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[105];
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n-k+1;i<=n;i++) printf("%d ",a[i]);
	for(i=1;i<n-k+1;i++) printf("%d ",a[i]);
	return 0;
}
