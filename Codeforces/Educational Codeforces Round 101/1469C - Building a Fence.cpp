#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int h[MAX];
int main()
{
	int T,n,k,i,l,r,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&h[i]);
		l=r=h[1];
		ok=1;
		for(i=2;i<=n;i++)
		{
			l=max(h[i],l-k+1);
			r=min(h[i]+k-1,r+k-1);
			if(l>r || l>h[i]+(k-1)) ok=0;
		}
		if(l>h[n] || r<h[n]) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
