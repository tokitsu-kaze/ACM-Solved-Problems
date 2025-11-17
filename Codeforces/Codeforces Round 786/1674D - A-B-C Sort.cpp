#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1+(n&1);i+1<=n;i+=2)
		{
			if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		}
		ok=1;
		for(i=2;i<=n;i++)
		{
			if(a[i]<a[i-1]) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
