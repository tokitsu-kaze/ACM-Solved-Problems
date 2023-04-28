#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int n,m,a[MAX];
int ck(int x)
{
	int i;
	ll res=0;
	for(i=1;i<=n;i++) res+=max(0,a[i]-x);
	return res>=m;
}
int main()
{
	int i,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	l=0;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
