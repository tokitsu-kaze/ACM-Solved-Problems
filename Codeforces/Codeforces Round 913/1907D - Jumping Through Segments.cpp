#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,x[MAX],y[MAX];
int ck(int k)
{
	int i,l,r;
	l=r=0;
	for(i=1;i<=n;i++)
	{
		l-=k;
		r+=k;
		l=max(l,x[i]);
		r=min(r,y[i]);
		if(l>r) return 0;
	}
	return l<=r;
}
int main()
{
	int T,l,r,mid,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
		l=0;
		r=1e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
