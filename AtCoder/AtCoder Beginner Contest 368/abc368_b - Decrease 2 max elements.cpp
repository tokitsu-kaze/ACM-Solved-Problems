#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[105];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	while(1)
	{
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		if(a[1]>0 && a[2]>0)
		{
			ans++;
			a[1]--;
			a[2]--;
		}
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
