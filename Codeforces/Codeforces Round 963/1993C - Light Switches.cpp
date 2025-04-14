#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,k,i,l,r,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		l=a[n];
		r=a[n]+k-1;
		for(i=1;i<=n;i++)
		{
			tmp=(a[n]-a[i])/k;
			if(tmp&1) l=max(l,a[i]+k*tmp+k);
			else r=min(r,a[i]+k*tmp+k-1);
		}
		if(l>r) l=-1;
		printf("%d\n",l);
	}
	return 0;
}

