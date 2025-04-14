#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,i,k,mn,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		mn=9;
		for(i=1;i<=n;i++)
		{
			x=abs(a[i]-b[i]);
			y=min(9-a[i]+b[i],9-b[i]+a[i]);
			mn=min(mn,abs(x-y));
			k-=min(x,y);
		}
		if(k<0) puts("No");
		else if(k%9%2)
		{
			if(k>=mn) puts("Yes");
			else puts("No");
		}
		else puts("Yes");
//		cout<<k<<endl;
	}
	return 0;
}
