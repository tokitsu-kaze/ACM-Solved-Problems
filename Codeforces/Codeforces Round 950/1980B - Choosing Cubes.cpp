#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,f,k,i,a[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&f,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(k==n)
		{
			puts("YES");
			continue;
		}
		f=a[f];
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		if(a[k]==f && a[k+1]==f) puts("MAYBE");
		else if(a[k]==f && a[k+1]!=f) puts("YES");
		else if(a[k]<f) puts("YES");
		else if(a[k]>f) puts("NO");
		else assert(0);
	}
	return 0;
}
