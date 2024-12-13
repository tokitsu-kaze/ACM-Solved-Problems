#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int T,n,k,i,a[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			if(k>=a[i]) k-=a[i];
			else break;
		}
		printf("%d\n",k);
	}
	return 0;
}
