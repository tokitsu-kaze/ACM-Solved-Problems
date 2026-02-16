#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		if(a[n]-1>a[1]) printf("%d\n",a[n]-1);
		else
		{
			ans=a[1]-1;
			while(a[n]%ans==0 || a[1]%ans==0) ans--;
			printf("%d\n",ans);
		}
	}
	return 0;
}
