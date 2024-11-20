#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
const int mod=998244353;
int main()
{
	int t,n,i,a[44];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==2 && a[1]+1!=a[2]) puts("YES");
		else puts("NO");
	}
	return 0;
}
